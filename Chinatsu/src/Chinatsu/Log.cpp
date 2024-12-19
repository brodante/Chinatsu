#include "cnpch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"
namespace Chinatsu
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		//---------------------------------------------
		// This is the logger for the engine
		
		s_CoreLogger = spdlog::stdout_color_mt("CHINATSU");
		s_CoreLogger->set_level(spdlog::level::trace);

		//---------------------------------------------
		// This is the logger for the client application

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}