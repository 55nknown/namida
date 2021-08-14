#ifndef __CORE_H__
#define __CORE_H__

#include <signal.h>

#if defined(_MSC_VER)
    //  Microsoft 
    #define EXPORT __declspec(dllexport)
    #define IMPORT __declspec(dllimport)
    #define BREAK __debugbreak();
#elif defined(__GNUC__)
    //  GCC
    #define EXPORT __attribute__((visibility("default")))
    #define IMPORT
    #define BREAK raise(SIGTRAP)
#else
    //  do nothing and hope for the best?
    #define EXPORT
    #define IMPORT
    #define BREAK
    #pragma warning Unknown dynamic link import/export semantics.
#endif

#if NAMIDA_BUILD_LIB
#   define NAMIDA_API EXPORT
#else
#   define NAMIDA_API IMPORT
#endif

#ifdef NAMIDA_ASSERTS
    #define N_ASSERT(x, ...)      { if (!(x)) { N_ERROR("Assertion Failed: {0}", __VA_ARGS__); BREAK } }
    #define N_CORE_ASSERT(x, ...) { if (!(x)) { N_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); BREAK } }
#else
    #define N_ASSERT(x, ...)
    #define N_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#endif // __CORE_H__