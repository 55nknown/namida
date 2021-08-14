#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "namida/core.h"

namespace Namida
{
    class NAMIDA_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    Application *CreateApplication();
}

#endif // __APPLICATION_H__