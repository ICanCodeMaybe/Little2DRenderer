#pragma once

#include "Event.h"

namespace lil{

    class MouseButton : public Event{
        public:
            inline int GetMouseButton(){ return m_mouseButton; }
            inline int GetMode(){ return m_mode; }

            void LogIt() { LIL_INFO("Mouse button event: " << m_mouseButton <<  " (mode(int): " << m_mode << ")")}

            SET_EVENT_TYPE(EventType::None);
            SET_CATEGORY(EventCategory::Mouse | EventCategory::Input)
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
            
            SET_EVENT_TYPE(EventType::MouseButtonDown)
            SET_CATEGORY(EventCategory::Mouse | EventCategory::Input | EventCategory::Down)
    };

    class MouseButtonPressedEvent : public MouseButton {
        public:
            MouseButtonPressedEvent(int mouseButton, int mouseButtonMode) 
                : MouseButton(mouseButton, mouseButtonMode)
            {}

            SET_EVENT_TYPE(EventType::MouseButtonPressed)
            SET_CATEGORY(EventCategory::Mouse | EventCategory::Input | EventCategory::Press)
    };

        class MouseButtonReleasedEvent : public MouseButton {
        public:
            MouseButtonReleasedEvent(int mouseButton, int mouseMode) 
                : MouseButton(mouseButton, mouseMode)
            {}

            SET_EVENT_TYPE(EventType::MouseButtonReleased)
            SET_CATEGORY(EventCategory::Mouse | EventCategory::Input | EventCategory::Release)
    };


    class MousePositionEvent : public Event{
        public:
            MousePositionEvent(float x, float y)
                : m_mouseX(x), m_mouseY(y)
            {}

            float GetMouseX(){ return m_mouseX; }
            float GetMouseY(){ return m_mouseY; }

            void LogIt()
            { LIL_INFO("Mouse Event: " << m_mouseX << ", " << m_mouseY) }

            SET_EVENT_TYPE(EventType::MousePositionChanged)
            SET_CATEGORY(EventCategory::Mouse | EventCategory::Input)
        private:
            float m_mouseX, m_mouseY;
    };
}