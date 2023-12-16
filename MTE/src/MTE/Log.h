#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace MTE 
{
	class MTE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() 
		{ 
			return s_CoreLogger;
		}
		
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
		{
			return s_ClientLogger;
		}
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


// Core log macros
#define MTE_CORE_TRACE(...)    ::MTE::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MTE_CORE_INFO(...)     ::MTE::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MTE_CORE_WARN(...)     ::MTE::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MTE_CORE_ERROR(...)    ::MTE::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MTE_CORE_CRITICAL(...) ::MTE::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define MTE_TRACE(...)         ::MTE::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MTE_INFO(...)          ::MTE::Log::GetClientLogger()->info(__VA_ARGS__)
#define MTE_WARN(...)          ::MTE::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MTE_ERROR(...)         ::MTE::Log::GetClientLogger()->error(__VA_ARGS__)
#define MTE_CRITICAL(...)      ::MTE::Log::GetClientLogger()->critical(__VA_ARGS__)
