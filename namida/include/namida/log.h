#ifndef __LOG_H__
#define __LOG_H__

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/fmt/ostr.h>

#include "namida/core.h"

namespace Namida
{
    class NAMIDA_API Log
    {
    private:
        static std::shared_ptr<spdlog::logger> _coreLogger;
        static std::shared_ptr<spdlog::logger> _clientLogger;
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return _coreLogger; }
        inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return _clientLogger; }
    };
}

// Core logging
#define N_CORE_TRACE(...)   ::Namida::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define N_CORE_INFO(...)    ::Namida::Log::GetCoreLogger()->info(__VA_ARGS__)
#define N_CORE_WARN(...)    ::Namida::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define N_CORE_ERROR(...)   ::Namida::Log::GetCoreLogger()->error(__VA_ARGS__)
#define N_CORE_FATAL(...)   ::Namida::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client logging
#define N_TRACE(...)   ::Namida::Log::GetClientLogger()->trace(__VA_ARGS__)
#define N_INFO(...)    ::Namida::Log::GetClientLogger()->info(__VA_ARGS__)
#define N_WARN(...)    ::Namida::Log::GetClientLogger()->warn(__VA_ARGS__)
#define N_ERROR(...)   ::Namida::Log::GetClientLogger()->error(__VA_ARGS__)
#define N_FATAL(...)   ::Namida::Log::GetClientLogger()->critical(__VA_ARGS__)

#endif // __LOG_H__