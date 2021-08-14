#ifndef __KEY_EVENT_H__
#define __KEY_EVENT_H__

#include <sstream>

#include "namida/events/event.h"

namespace Namida
{
    class NAMIDA_API KeyEvent : public Event
    {
    protected:
        KeyEvent(int keycode)
            : _keycode(keycode) {}
        
        int _keycode;

    public:
        inline int GetKeyCode() const { return _keycode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    };

    class NAMIDA_API KeyPressedEvent : public KeyEvent
    {
    private:
        int _repeat;

    public:
        KeyPressedEvent(int keycode, int repeat)
            : KeyEvent(keycode), _repeat(repeat) {}

        inline int GetRepeatCount() const { return _repeat; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << _keycode << " (" << _repeat << ")";
            return ss.str();
        }

        EVENT_CLASS_TYPE(EventType::KeyPressed)
    };

    class NAMIDA_API KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(int keycode)
            : KeyEvent(keycode) {}
        
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << _keycode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(EventType::KeyReleased)
    };
}

#endif // __KEY_EVENT_H__