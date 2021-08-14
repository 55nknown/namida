#ifndef __APPLICATION_EVENT_H__
#define __APPLICATION_EVENT_H__

#include <sstream>

#include "namida/events/event.h"

namespace Namida
{
    class NAMIDA_API WindowResizeEvent : public Event
    {
    private:
        unsigned int _width, _height;
    public:
        WindowResizeEvent(unsigned int width, unsigned int height)
            : _width(width), _height(height) {}

        inline unsigned int GetWidth() const { return _width; }
        inline unsigned int GetHeight() const { return _height; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << _width << ", " << _height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(EventType::WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class NAMIDA_API WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() {}

        EVENT_CLASS_TYPE(EventType::WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class NAMIDA_API AppUpdateEvent : public Event
    {
    public:
        AppUpdateEvent() {}

        EVENT_CLASS_TYPE(EventType::AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class NAMIDA_API AppTickEvent : public Event
    {
    public:
        AppTickEvent() {}

        EVENT_CLASS_TYPE(EventType::AppTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class NAMIDA_API AppRenderEvent : public Event
    {
    public:
        AppRenderEvent() {}

        EVENT_CLASS_TYPE(EventType::AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
} // namespace Namida


#endif // __APPLICATION_EVENT_H__