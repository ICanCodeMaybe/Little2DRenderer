#pragma once

#include "Event.h"

namespace lil{

    class MouseButton : public Event{
        public:
            inline int GetMouseButton(){ return m_mouseButton; }

            inline int GetMode(){ return m_mode; }

            EventType GetEventType() override { return EventType::None; }

            void LogIt() { LIL_INFO("Mouse button event: " << m_mouseButton <<  " (mode(int): " << m_mode << ")")}
        protected:
            MouseButton(int mouseButton, int mode) : m_mouseButton(mouseButton), m_mode(mode) 
            {}


            int m_mouseButton;
            int m_mode;
    };

    class MouseButtonDownEvent : public MouseButton {
        public:
            MouseButtonDownEvent(int mouseButton, int mouseButtonMode) 
                : MouseButton(mouseButton, mouseButtonMode)
            {}

            EventType GetEventType() override { return EventType::MouseButtonDown; }
    };

    class MouseButtonPressedEvent : public MouseButton {
        public:
            MouseButtonPressedEvent(int mouseButton, int mouseButtonMode) 
                : MouseButton(mouseButton, mouseButtonMode)
            {}

            EventType GetEventType() override { return EventType::MouseButtonPressed; }
    };

        class MouseButtonReleasedEvent : public MouseButton {
        public:
            MouseButtonReleasedEvent(int mouseButton, int mouseMode) 
                : MouseButton(mouseButton, mouseMode)
            {}

            EventType GetEventType() override { return EventType::MouseButtonReleased; }
    };


    class MousePosition{
        public:
            MousePosition(float x, float y){
                
            }
    };
}