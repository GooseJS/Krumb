#pragma once

#include "KrumbEngine/Core.h"
#include "KrumbEngine/KrumbTime.h"

namespace KrumbEngine
{
	struct GameTime
	{
		float deltaTime;
	};

	class GameSettings
	{
	private:
		GameSettings() {}
		~GameSettings() = default;
		GameSettings(const GameSettings& gs) {}
		GameSettings& operator=(const GameSettings& gs) = delete;

	public:
		KRUMB_STATIC_INSTANCE(GameSettings);

		KrumbTime* gameTime;
		WindowData* windowData; 
	};
}