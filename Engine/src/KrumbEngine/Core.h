#pragma once

#ifdef KMB_PLATFORM_WINDOWS
#ifdef KMB_BUILD_DLL
#define KRUMB_API _declspec(dllexport)
#else
#define KRUMB_API _declspec(dllimport)
#endif
#else
#define KRUMB_API
#endif

#include "KrumbEngine/Logger.h"

#ifdef KMB_ENABLE_ASSERTS
#ifdef KMB_PLATFORM_WINDOWS
#define KRUMB_ASSERT(x, ...) { if(!(x)) { KRUMB_CRITICAL("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define KRUMB_CORE_ASSERT(x, ...) { if(!(x)) { KRUMB_CORE_CRITICAL("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#endif
#else
#define KRUMB_ASSERT(x, ...)
#define KRUMB_CORE_ASSERT(x, ...)
#endif

#define KRUMB_STATIC_INSTANCE(x) static KRUMB_API x *getInstance() { static x instance; return &instance; }
#define KRUMB_GET_WINDOW_DATA(x) *(WindowData*)glfwGetWindowUserPointer(x)

namespace KrumbEngine
{
	struct WindowData
	{
		const char* title;
		unsigned int width, height;
		float aspectRatio;
		bool vSync;

		float oldMouseX;
		float oldMouseY;
	};
}