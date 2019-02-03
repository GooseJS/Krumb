#include <KrumbEngine.h>

class KrumbApp : public KrumbEngine::Application
{
public:
	KrumbApp()
	{
		KrumbEngine::EventSystem::getInstance()->addListener<KrumbEngine::EventWindowResize>(KRUMB_SUBSCRIBE_EVENT(&KrumbApp::windowResize));
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

	void windowResize(KrumbEngine::EventWindowResize& event)
	{
		KRUMB_INFO("Window Resized. New Size - X:{}, Y:{}", event.windowData().width, event.windowData().height);
	}
};

KrumbEngine::Application* KrumbEngine::createApplication()
{
	return new KrumbApp();
}