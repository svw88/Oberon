#pragma once

#include "Oberon/Core/Base.h"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)


namespace Oberon {

	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define OB_CORE_TRACE(...)    ::Oberon::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define OB_CORE_INFO(...)     ::Oberon::Log::GetCoreLogger()->info(__VA_ARGS__)
#define OB_CORE_WARN(...)     ::Oberon::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define OB_CORE_ERROR(...)    ::Oberon::Log::GetCoreLogger()->error(__VA_ARGS__)
#define OB_CORE_CRITICAL(...) ::Oberon::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define OB_TRACE(...)         ::Oberon::Log::GetClientLogger()->trace(__VA_ARGS__)
#define OB_INFO(...)          ::Oberon::Log::GetClientLogger()->info(__VA_ARGS__)
#define OB_WARN(...)          ::Oberon::Log::GetClientLogger()->warn(__VA_ARGS__)
#define OB_ERROR(...)         ::Oberon::Log::GetClientLogger()->error(__VA_ARGS__)
#define OB_CRITICAL(...)      ::Oberon::Log::GetClientLogger()->critical(__VA_ARGS__)