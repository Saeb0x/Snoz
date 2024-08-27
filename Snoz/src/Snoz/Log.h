#pragma once

#include "Core.h"

#include <spdlog/spdlog.h>
#include <memory>

namespace Snoz
{
	class SZ_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_ClientLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core engine logs
#define SZ_TRACE(...)	Snoz::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SZ_DEBUG(...)	Snoz::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define SZ_INFO(...)	Snoz::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SZ_WARN(...)	Snoz::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SZ_ERROR(...)	Snoz::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SZ_CRITICAL(...) Snoz::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client app logs
#define SZ_APP_TRACE(...)	Snoz::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SZ_APP_DEBUG(...)	Snoz::Log::GetClientLogger()->debug(__VA_ARGS__)
#define SZ_APP_INFO(...)	Snoz::Log::GetClientLogger()->info(__VA_ARGS__)
#define SZ_APP_WARN(...)	Snoz::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SZ_APP_ERROR(...)	Snoz::Log::GetClientLogger()->error(__VA_ARGS__)
#define SZ_APP_CRITICAL(...) Snoz::Log::GetClientLogger()->critical(__VA_ARGS__)