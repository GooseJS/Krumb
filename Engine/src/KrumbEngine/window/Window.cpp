#include "KrumbEngine/window/Window.h"

namespace KrumbEngine
{
	static bool s_glfwInit = false;

	static void glfwError(int id, const char* description)
	{
		KRUMB_CORE_ERROR("OpenGL Error: {} {} {} ", description);
	}

	Window::Window(const WindowCfg& cfg)
	{
		// TODO (Brendan): Figure out what the fuck I am doing with this constructor
	}

	void Window::init(const WindowCfg& cfg)
	{
		_data.title = cfg.title;
		_data.width = cfg.width;
		_data.height = cfg.height;
		_data.aspectRatio = static_cast<float>(cfg.width) / static_cast<float>(cfg.height);

		KRUMB_CORE_INFO("Creating window - Title: {} - Width: {} - Height: {}", _data.title, _data.width, _data.height);

		glfwSetErrorCallback(&glfwError);
		if (!s_glfwInit)
		{
			// TODO: glfwTerminate() on program shutdown
			int status = glfwInit();
			KRUMB_CORE_ASSERT(status, "Could not initialize GLFW.");
			KRUMB_CORE_INFO("Initialized GLFW.");

			s_glfwInit = true;
		}

		_window = glfwCreateWindow(static_cast<int>(_data.width), static_cast<int>(_data.height), _data.title, nullptr, nullptr);
		glfwMakeContextCurrent(_window);
		glfwSetWindowUserPointer(_window, &_data);
		setVSync(true);

		//glewExperimental = true;
		// TODO: Glew stuff goes here

		// TODO: Event system callback stuff goes here
	}

	void Window::update()
	{
		glfwPollEvents();
		glfwSwapBuffers(_window);
	}

	void Window::setVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		_data.vSync = enabled;
	}

	bool Window::isVSync()
	{
		return _data.vSync;
	}
	
	bool Window::shouldClose()
	{
		return glfwWindowShouldClose(_window) == GLFW_TRUE;
	}
}