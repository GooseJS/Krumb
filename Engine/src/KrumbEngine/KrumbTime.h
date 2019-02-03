#pragma once

#include <vector>
#include <chrono>

#define KRUMB_GET_CURRENT_MILLIS std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()

namespace KrumbEngine
{
	class Application;
	class KrumbTime
	{
	private:
		double _lastFrameTime;
		double _currentFrameTime;
		float _deltaTime;
		friend Application;
	public:
		double getLastFrameTime() const { return _lastFrameTime; }
		double getCurrentFrameTime() const { return _currentFrameTime; }
		float getDeltaTime() const { return _deltaTime; }
		double getCurrentTimeInMS() const { return KRUMB_GET_CURRENT_MILLIS; }
	};
}