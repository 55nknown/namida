#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <string>
#include <functional>
#include <GLFW/glfw3.h>

#include "namida/core.h"
#include "namida/events/event.h"

namespace Namida
{
    struct WindowProps
    {
        std::string Title;
        unsigned int Width, Height;

        WindowProps(const std::string &title = "Namida Engine",
                    unsigned int width = 1280,
                    unsigned int height = 720)
            : Title(title), Width(width), Height(height) {}
    };

    class NAMIDA_API Window
    {
        using EventCallbackFn = std::function<void(Event&)>;
    private:
        GLFWwindow *_window;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool Vsync;
            EventCallbackFn EventCallback;
        };

        WindowData _data;

        virtual void Init(const WindowProps& props);
		virtual void Shutdown();
    public:
        Window(const WindowProps &props);
        virtual ~Window();

        void OnUpdate();

        inline unsigned int GetWidth() const { return _data.Width; }
        inline unsigned int GetHeight() const { return _data.Height; }

        inline void SetEventCallback(const EventCallbackFn &callback) { _data.EventCallback = callback; }
        inline bool VsyncEnabled() const { return _data.Vsync; }
        void SetVsync(bool enabled);

        static Window* Create(const WindowProps &props = WindowProps());
    };
} // namespace Namida


#endif // __WINDOW_H__