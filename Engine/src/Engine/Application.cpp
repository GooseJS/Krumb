#include "Application.h"

namespace KrumbEngine
{
	Application::Application() {}
	Application::~Application() {}

	void Application::run()
	{
		_running = true;

		while (_running)
		{
			update();
			render();
		}
	}
}