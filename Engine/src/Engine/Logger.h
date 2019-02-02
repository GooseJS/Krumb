#pragma once

#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace KrumbEngine
{
	class Logger
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

#define KMB_CORE_TRACE(...) ::KrumbEngine::Logger::getCoreLogger()->trace(__VA_ARGS__)
#define KMB_CORE_INFO(...) ::KrumbEngine::Logger::getCoreLogger()->info(__VA_ARGS__)