#include <KrumbEngine.h>
#include <KrumbEngine/EntryPoint.h>

#include "Krumb/filesystem/WorldIO.h"

#include "Krumb/world/World.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

class KrumbApp : public KrumbEngine::Application
{
public:
	Krumb::World world;
	Krumb::BlockLoader blockLoader;

	KrumbApp()
	{
		KrumbEngine::EventSystem::getInstance()->addListener<KrumbEngine::EventWindowOpen>(KRUMB_SUBSCRIBE_EVENT(&KrumbApp::onWindowOpen));
	}


	~KrumbApp()
	{

	}

	void update() override
	{

	}

	void render() override
	{

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
	}
};

KrumbEngine::Application* KrumbEngine::createApplication()
{
	return new KrumbApp();
}