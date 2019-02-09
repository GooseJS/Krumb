#include <vector>
#include <string>

#include <KrumbEngine.h>
#include <KrumbEngine/GL.h>
#include <KrumbEngine/EntryPoint.h>

#include "Krumb/filesystem/WorldIO.h"

#include "Krumb/world/World.h"
#include "Krumb/render/ChunkMeshBuilder.h"
#include "Krumb/render/WorldRenderer.h"
#include "Krumb/entity/Player.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

class KrumbApp : public KrumbEngine::Application
{
public:
	Krumb::World world;
	Krumb::BlockLoader blockLoader;
        Krumb::WorldRenderer worldRenderer;
        Krumb::Player player;

	KrumbApp() : worldRenderer(&world)
	{
		KrumbEngine::EventSystem::getInstance()->addListener<KrumbEngine::EventWindowOpen>(KRUMB_SUBSCRIBE_EVENT(&KrumbApp::onWindowOpen));
                KrumbEngine::EventSystem::getInstance()->addListener<KrumbEngine::EventMouseMove>(KRUMB_SUBSCRIBE_EVENT(&KrumbApp::onMouseMove));
	}


	~KrumbApp()
	{

	}

	void update() override
	{
	    updateCameraPos();
	}

	void render() override
	{
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
            worldRenderer.render();
	}

	void onWindowOpen(KrumbEngine::EventWindowOpen event)
	{

	    std::vector<std::string> textureFileNames;
	    textureFileNames.emplace_back("dirt.png");
	    textureFileNames.emplace_back("grass-side.png");
	    textureFileNames.emplace_back("grass-top.png");
	    KrumbEngine::Texture::TextureArray textureArray = KrumbEngine::Texture::create2DTextureArray(16, 16, textureFileNames);
	    blockLoader.setTextureArray(textureArray);
	    Krumb::BlockData dirtBlockData = blockLoader.loadBlockData("dirt.json");
	    Krumb::Block blockDirt("dirt", dirtBlockData);
	    Krumb::Block blockAir("air", Krumb::BlockData());

	    // NOTE: Make sure air is registered first, as the first block registered is not rendered
	    Krumb::BlockManager::getInstance()->registerBlock(blockAir);
	    Krumb::BlockManager::getInstance()->registerBlock(blockDirt);

            KRUMB_INFO("Dirt block ID: {}", blockDirt.getBlockID());

	    KRUMB_INFO("Dirt Texture ID: {}.", dirtBlockData.textureLayers.nx);

	    world.setBlockAt(Krumb::BlockPos(38, 23, 8), blockDirt);

	    KRUMB_INFO("BlockID at 38, 23, 8 is: {}", world.getBlockAt(Krumb::BlockPos(38, 23, 8)).getBlockID());

	    Krumb::ChunkMeshBuilder meshBuilder(&world);

	    meshBuilder.buildChunk(Krumb::BlockPos(38, 23, 8));

	    worldRenderer.initRenderer(textureArray);
	    worldRenderer.setWorldRenderCam(&player.getPlayerCamera());
	}

        void onMouseMove(KrumbEngine::EventMouseMove event)
        {
            player.handleRotationInput(event.deltaX(), event.deltaY());
        }

        void updateCameraPos()
        {
            Krumb::PlayerMovement playerMovement {};

            playerMovement.moveForwardPressed = getWindow().isKeyPressed(GLFW_KEY_W);
            playerMovement.moveBackPressed = getWindow().isKeyPressed(GLFW_KEY_S);
            playerMovement.moveLeftPressed = getWindow().isKeyPressed(GLFW_KEY_A);
            playerMovement.moveRightPressed = getWindow().isKeyPressed(GLFW_KEY_D);
            playerMovement.moveUpPressed = getWindow().isKeyPressed(GLFW_KEY_Q);
            playerMovement.moveDownPressed = getWindow().isKeyPressed(GLFW_KEY_Z);
        }
};

KrumbEngine::Application* KrumbEngine::createApplication()
{
	return new KrumbApp();
}
