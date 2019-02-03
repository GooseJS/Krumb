#pragma once

#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "KrumbEngine/Core.h"

namespace KrumbEngine
{
	class KRUMB_API Logger
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return _coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return _clientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> _coreLogger;
		static std::shared_ptr<spdlog::logger> _clientLogger;
	};
}

#define KRUMB_CORE_TRACE(...) ::KrumbEngine::Logger::getCoreLogger()->trace(__VA_ARGS__)
#define KRUMB_CORE_INFO(...) ::KrumbEngine::Logger::getCoreLogger()->info(__VA_ARGS__)
#define KRUMB_CORE_WARN(...) ::KrumbEngine::Logger::getCoreLogger()->warn(__VA_ARGS__)
#define KRUMB_CORE_ERROR(...) ::KrumbEngine::Logger::getCoreLogger()->error(__VA_ARGS__)
#define KRUMB_CORE_CRITICAL(...) ::KrumbEngine::Logger::getCoreLogger()->critical(__VA_ARGS__)

#define KRUMB_TRACE(...) ::KrumbEngine::Logger::getClientLogger()->trace(__VA_ARGS__)
#define KRUMB_INFO(...) ::KrumbEngine::Logger::getClientLogger()->info(__VA_ARGS__)
#define KRUMB_WARN(...) ::KrumbEngine::Logger::getClientLogger()->warn(__VA_ARGS__)
#define KRUMB_ERROR(...) ::KrumbEngine::Logger::getClientLogger()->error(__VA_ARGS__)
#define KRUMB_CRITICAL(...) ::KrumbEngine::Logger::getClientLogger()->critical(__VA_ARGS__)