#include <KrumbEngine.h>

class KrumbApp : public KrumbEngine::Application
{
public:
	KrumbApp()
	{

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
};

KrumbEngine::Application* KrumbEngine::createApplication()
{
	return new KrumbApp();
}