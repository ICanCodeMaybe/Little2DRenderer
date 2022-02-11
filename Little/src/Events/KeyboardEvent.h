#pragma once

#include "Event.h"

namespace lil{

    class KeyEvent : public Event{
        public:
            inline int GetKeyCode() { return m_keyCode; }

            void LogIt(){
                LIL_INFO("KeyEvent(keycode to char): " << (char)KeyEvent::GetKeyCode())
            }
            SET_EVENT_TYPE(EventType::None)

            SET_CATEGORY(EventCategory::Keyboard | EventCategory::Input)
        protected:
            KeyEvent(int keyCode) { m_keyCode = keyCode;}

            int m_keyCode;

    };


    class KeyPressedEvent : public KeyEvent {
        public:
            KeyPressedEvent(int keycode, bool repeated) : KeyEvent(keycode), m_repeated(repeated){
            }

            bool WasRepeated() { return m_repeated; }
            void LogIt(){
                LIL_INFO("KeyPressedEvent(keycode to char): " << (char)KeyEvent::GetKeyCode())
            }
            SET_EVENT_TYPE(EventType::KeyPressed)
            SET_CATEGORY(EventCategory::Keyboard | EventCategory::Input | EventCategory::Press)
        private:
            bool m_repeated;
                
    };

    class KeyReleasedEvent : public KeyEvent {
        public:
            KeyReleasedEvent(int keycode) : KeyEvent(keycode){
            }

            void LogIt(){
                LIL_INFO("KeyReleasedEvent(keycode to char): " << (char)KeyEvent::GetKeyCode())
            }

            SET_EVENT_TYPE(EventType::KeyReleased)
            SET_CATEGORY(EventCategory::Keyboard | EventCategory::Input | EventCategory::Release)
    };
}