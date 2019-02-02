#pragma once

namespace KrumbEngine
{
	class Application
	{
	private:
		bool _running = false;
	protected:
		virtual void update() {}
		virtual void render() {}

		virtual void prepareClose() { close(); }

		void close() { _running = false; }
	public:
		Application();
		virtual ~Application();

		void run();
	};

	Application* createApplication();
}