#include "Application.h"

namespace KrumbEngine
{
	Application::Application() : _window(WindowCfg()) {}
	Application::~Application() {}

	void Application::run()
	{
		_window.init(WindowCfg());
		_running = true;

		while (_running)
		{
			_window.update();
			if (_window.shouldClose()) prepareClose();
			update();
			render();
		}
	}
}