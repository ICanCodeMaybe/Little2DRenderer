#pragma once

#include "log.h"
#include "Window.h"

namespace lil{

    class Application{
        public: 

            static Application* Get();
        
            void Init();
        
            void CreateOpenglContext(Window& window);

            Window* GetWindow() { return m_window; }

            float GetDeltaTime() { return m_deltaTime; } // returns zero, will be implementec later
        private:
            Application();
            ~Application();

            float m_deltaTime = 0.0f; 
            GLFWwindow* m_GlfwWindow;
            
            Window* m_window;
            static Application* s_instance;
    };

}