#pragma once

#include "src/log.h"

namespace lil{
   
    enum class EventCategory{
        None = 0, Mouse, Keyboard, Window, Down, Release
    };

    enum class EventType{
        None = 0, 
        KeyPressed, KeyDown, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseButtonDown, MouseButton, Released,
        MousePositionChanged, MousePositionXChanged, MousePositionYChanged,
        WindowResize, WindowClosed
    };

//https://bastian.rieck.me/blog/posts/2015/event_system_cxx11/
    class Event{
    public:  
        ~Event(){}
        virtual EventType GetEventType() = 0;
    };
}
