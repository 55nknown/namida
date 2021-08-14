#include "namida/log.h"

namespace Namida
{
    std::shared_ptr<spdlog::logger> Log::_coreLogger;
    std::shared_ptr<spdlog::logger> Log::_clientLogger;

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        
        _coreLogger = spdlog::stdout_color_mt("NAMIDA");
        _coreLogger->set_level(spdlog::level::trace);

        _clientLogger = spdlog::stdout_color_mt("APP");
        _coreLogger->set_level(spdlog::level::trace);
    }
}