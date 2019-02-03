#pragma once

#include "KrumbEngine/GL.h"

#include "KrumbEngine/Core.h"

#include "KrumbEngine/event/EventSystem.h"
#include "KrumbEngine/input/InputEvents.h"
#include "KrumbEngine/window/WindowEvents.h"

namespace KrumbEngine
{
	struct WindowCfg
	{
		const char* title;
		unsigned int width;
		unsigned int height;

		WindowCfg(const char* _title = "Krumb", unsigned int _width = 1280, unsigned int _height = 720) : title(_title), width(_width), height(_height) {}
	};

	class KRUMB_API Window
	{
	private:
		GLFWwindow* _window;
		WindowData _data;
	public:
		Window(const WindowCfg& cfg);
		~Window() = default;

		void init(const WindowCfg& cfg);
		void update();

		void setVSync(bool enabled);
		bool isVSync();

		bool shouldClose();

		inline bool isKeyPressed(int key) { return glfwGetKey(_window, key) != GLFW_RELEASE; }

		inline void enableCursor() { glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL); }
		inline void disableCursor() { glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); }

		inline WindowData& getWindowData() { return _data; }
	};
}