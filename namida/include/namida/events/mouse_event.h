#ifndef __MOUSE_EVENT_H__
#define __MOUSE_EVENT_H__

#include <sstream>

#include "namida/events/event.h"

namespace Namida
{
    class NAMIDA_API MouseMovedEvent : public Event
    {
    private:
        float _mouseX, _mouseY;
    public:
        MouseMovedEvent(float x, float y)
            : _mouseX(x), _mouseY(y) {}

        inline float GetX() const { return _mouseX; }
        inline float GetY() const { return _mouseY; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << _mouseX << ", " << _mouseY;
            return ss.str();
        }

        EVENT_CLASS_TYPE(EventType::MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    };

    class NAMIDA_API MouseScrolledEvent : public Event
    {
    private:
        float _offsetX, _offsetY;
    public:
        MouseScrolledEvent(float x, float y)
            : _offsetX(x), _offsetY(y) {}

        inline float GetXOffset() const { return _offsetX; }
        inline float GetYOffset() const { return _offsetY; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << _offsetX << ", " << _offsetY;
            return ss.str();
        }

        EVENT_CLASS_TYPE(EventType::MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    };

    class NAMIDA_API MouseButtonEvent : public Event
    {
    protected:
        MouseButtonEvent(int button)
            : _button(button) {}

        int _button;

    public:
        inline int GetMouseButton() const { return _button; }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    };

    class NAMIDA_API MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(int button)
            : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << _button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(EventType::MouseButtonPressed)
    };

    class NAMIDA_API MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int button)
            : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << _button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(EventType::MouseButtonReleased)
    };
} // namespace Namida


#endif // __MOUSE_EVENT_H__