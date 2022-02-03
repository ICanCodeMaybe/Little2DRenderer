#pragma once

#include "Event.h"

namespace lil{

    class KeyEvent : public Event{
        public:
            EventType GetEventType() override { return EventType::KeyDown; }
        
            inline int GetKeyCode() { return m_keyCode; }

            void LogIt(){
                LIL_INFO("KeyEvent(keycode to char): " << (char)KeyEvent::GetKeyCode())
            }
        protected:
            KeyEvent(int keyCode) { m_keyCode = keyCode;}

            int m_keyCode;

    };

    class KeyDownEvent : public KeyEvent {
        public:
            KeyDownEvent(int keyCode, bool wasRepeated) 
            : m_wasRepeated(wasRepeated), KeyEvent(keyCode){

            }
            
            inline bool WasKeyDownRepeate() { return m_wasRepeated;}

        private:
            bool m_wasRepeated;
    };

    class KeyPressed : public KeyEvent {
        public:
            KeyPressed(int keycode) : KeyEvent(keycode){
            }
    };

    class KeyReleased : public KeyEvent {
        public:
            KeyReleased(int keycode) : KeyEvent(keycode){
            }
    };
}