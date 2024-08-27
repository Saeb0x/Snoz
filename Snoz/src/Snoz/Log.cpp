#include "szPCH.h"
#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Snoz
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("[%I:%M:%S %p] [%l] %n: %^%v%$");
		spdlog::set_level(spdlog::level::trace);

		s_CoreLogger = spdlog::stdout_color_mt("SNOZ");
		s_ClientLogger =spdlog::stdout_color_mt("APP");
	}
}


