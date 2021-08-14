#include "namida/application.h"

#include "namida/events/application_event.h"
#include "namida/log.h"

namespace Namida
{
    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        WindowResizeEvent e(1280, 720);
        N_INFO(e);

        while (true);
    }
}