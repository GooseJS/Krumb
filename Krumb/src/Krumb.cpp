#include <KrumbEngine.h>
#include <KrumbEngine/EntryPoint.h>

#include "Krumb/filesystem/WorldIO.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

class KrumbApp : public KrumbEngine::Application
{
public:
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

		KRUMB_INFO("Dirt Texture ID: {}.", dirtBlockData.textureLayers.nx);
	}
};

KrumbEngine::Application* KrumbEngine::createApplication()
{
	return new KrumbApp();
}