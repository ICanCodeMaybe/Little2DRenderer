#pragma once 

#include "Event.h"

namespace lil{

    class WindowCloseEvent : public Event{
    public:
        WindowCloseEvent(const char* TitleOfWindow)
            :m_title(TitleOfWindow){}

        inline const char* GetWindowTitle() { return m_title; }

        void LogIt() override { LIL_INFO("Window(" << m_title << ") was closed")}

        SET_EVENT_TYPE(EventType::WindowClosed)
        SET_CATEGORY(EventCategory::Windows)

    private:
        const char* m_title;
    };

    class WindowResizeEvent : public Event{
    public:
        WindowResizeEvent(int width, int height) 
            : m_width(width), m_height(height){}

        inline int GetWidth() { return m_width; }
        inline int GetHeight() { return m_height; }

        void LogIt() override { LIL_INFO("Window resize event - width: " << GetWidth() << ", height: " << GetHeight())}
        
        SET_EVENT_TYPE(EventType::WindowResize)
        SET_CATEGORY(EventCategory::Windows)

    private:
        int m_width, m_height;
    };

}