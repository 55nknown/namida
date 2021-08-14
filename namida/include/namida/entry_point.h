#ifndef __ENTRY_POINT_H__
#define __ENTRY_POINT_H__

#include "namida/namida.h"

extern Namida::Application *Namida::CreateApplication();

int main(int argc, char **argv)
{
    Namida::Log::Init();
    N_CORE_WARN("Initialized Log!");

    auto app = Namida::CreateApplication();
    app->Run();
    delete app;
}

#endif // __ENTRY_POINT_H__