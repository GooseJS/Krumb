#pragma once

#include "KrumbEngine/GL.h"
#include "KrumbEngine/Core.h"
#include "KrumbEngine/event/IEvent.h"

namespace KrumbEngine
{
	struct EventWindowOpen : public IEvent
	{
	private:
		WindowData& _windowData;
	public:
		EventWindowOpen(WindowData& windowData) : _windowData(windowData) {}
		WindowData& windowData() { return _windowData; }
	};

	struct EventWindowResize : public IEvent
	{
	private:
		WindowData& _windowData;
	public:
		EventWindowResize(WindowData& windowData) : _windowData(windowData) {}
		WindowData& windowData() { return _windowData; }
	};

	struct EventWindowClose : public IEvent
	{
	private:
		WindowData& _windowData;
	public:
		EventWindowClose(WindowData& windowData) : _windowData(windowData) {}
		WindowData& windowData() { return _windowData; }
	};
}
