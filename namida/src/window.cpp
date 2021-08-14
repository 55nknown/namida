#include "namida/log.h"
#include "namida/window.h"

namespace Namida
{
    static bool GLFWInitialized = false;

    Window *Window::Create(const WindowProps &props)
    {
        return new Window(props);
    }

    Window::Window(const WindowProps &props)
    {
        Init(props);
    }

    Window::~Window()
    {
        Shutdown();
    }

    void Window::Init(const WindowProps &props)
    {
        _data.Title = props.Title;
        _data.Width = props.Width;
        _data.Height = props.Height;

        N_CORE_INFO("Creating window {0}, ({1}, {2})", props.Title, props.Width, props.Height);

        if (!GLFWInitialized)
        {
            int success = glfwInit();
            N_CORE_ASSERT(success, "Could not initialize GLFW.");

            GLFWInitialized = true;
        }

        _window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), NULL, NULL);
        glfwMakeContextCurrent(_window);
        glfwSetWindowUserPointer(_window, &_data);
        SetVsync(true);
    }

    void Window::Shutdown()
    {
        glfwDestroyWindow(_window);
    }

    void Window::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(_window);
    }

    void Window::SetVsync(bool enabled)
    {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        _data.Vsync = enabled;
    }
} // namespace Namida
