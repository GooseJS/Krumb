#pragma once

#include "KrumbEngine/Core.h"
#include "KrumbEngine/window/Window.h"

namespace KrumbEngine
{
	class KRUMB_API Application
	{
	private:
		bool _running = false;
		Window _window;
	protected:
		virtual void update() {}
		virtual void render() {}

		virtual void prepareClose() { close(); }

		void close() { _running = false; }

		inline Window& getWindow() { return _window; }
	public:
		Application();
		virtual ~Application();

		void run();
	};

	Application* createApplication();
}