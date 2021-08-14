#ifndef __EVENT_H__
#define __EVENT_H__

#include <functional>
#include <string>

#include "namida/core.h"

namespace Namida
{
    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryInput       = BIT(1),
        EventCategoryKeyboard    = BIT(2),
        EventCategoryMouse       = BIT(3),
        EventCategoryMouseButton = BIT(4),
    };

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return type; } \
                               virtual EventType GetEventType() const override { return GetStaticType(); } \
                               virtual const char *GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

    class NAMIDA_API Event
    {
        friend class EventDispatcher;
    public:
        virtual EventType GetEventType() const = 0;
        virtual const char *GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

        inline bool IsCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;
        }

    protected:
        bool _handled = false;
    };

    class EventDispatcher
    {
        template <typename T>
        using EventFn = std::function<bool(T&)>;
    private:
        Event &_event;
    public:
        EventDispatcher(Event &event) : _event(event) {}
        
        template <typename T>
        bool Dispatch(EventFn<T> func)
        {
            if (_event.GetEventType() == T::GetStaticType())
            {
                _event._handled = func(*(T*)&_event);
                return true;
            }
            return false;
        }
    };

    inline std::ostream &operator<<(std::ostream &os, const Event &e)
    {
        return os << e.ToString();
    }

} // namespace Namida


#endif // __EVENT_H__