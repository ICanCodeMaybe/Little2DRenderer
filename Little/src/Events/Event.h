#pragma once
#include <functional>

#include "src/log.h"

namespace lil{
   #define BIT_SHIFT(x) 1 << x 
    enum EventCategory{
        None        = BIT_SHIFT(0),
        Input       = BIT_SHIFT(1),
        Mouse       = BIT_SHIFT(2),
        Keyboard    = BIT_SHIFT(3),
        Windows      = BIT_SHIFT(4),
        Press       = BIT_SHIFT(5),
        Down        = BIT_SHIFT(6),
        Release     = BIT_SHIFT(7)
    };

    enum class EventType{
        None = 0, 
        KeyPressed, KeyDown, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseButtonDown, MouseButton, Released,
        MousePositionChanged,
        WindowResize, WindowClosed
    };

#define SET_EVENT_TYPE(x)   EventType GetEventType() override { return x; }\
                            static EventType GetStaticEventType() {return x;}

#define SET_CATEGORY(x) int GetCategoryFlags() override{\
                            return x;}
    class Event{
    public:  
        ~Event(){}
        virtual void LogIt() = 0;

        virtual int GetCategoryFlags() = 0;
        virtual EventType GetEventType() = 0;

        bool IsInCategory(int EventCategory) { return GetCategoryFlags() & EventCategory;}
        protected:
            bool m_handled = false;

        friend class Dispatcher;
    };

    class Dispatcher{
        
        template<typename T>
        using EventFn = std::function<bool(T&)>;

    public:
        Dispatcher(Event& event) : m_event(event){}

        template<typename T>

        bool Dispatch(std::function<bool(T&)> EventFunction){

            if(m_event.GetEventType() == T::GetStaticEventType()){
                m_event.m_handled = EventFunction(*(T*)&m_event);
                return true;
            }

            return false;
        }
    private:
        Event& m_event;
    };
}
