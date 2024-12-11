#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Chinatsu
{
	class CHINATSU_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Logging Macros
#define CN_CORE_TRACE(...)    ::Chinatsu::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CN_CORE_INFO(...)     ::Chinatsu::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CN_CORE_WARN(...)     ::Chinatsu::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CN_CORE_ERROR(...)    ::Chinatsu::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CN_CORE_CRITICAL(...) ::Chinatsu::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Logging Macros
#define CN_TRACE(...)         ::Chinatsu::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CN_INFO(...)          ::Chinatsu::Log::GetClientLogger()->info(__VA_ARGS__)
#define CN_WARN(...)          ::Chinatsu::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CN_ERROR(...)         ::Chinatsu::Log::GetClientLogger()->error(__VA_ARGS__)
#define CN_CRITICAL(...)      ::Chinatsu::Log::GetClientLogger()->critical(__VA_ARGS__)
