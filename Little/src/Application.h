#pragma once

#include "log.h"

struct GLFWwindow;

namespace lil{

    class Application{
        public: 

            static Application* Get();
        
            void Init();
        
            void CreateOpenglContext(GLFWwindow* window);

        private:
            Application();
            ~Application();
            
            GLFWwindow* m_window;
            
            static Application* s_instance;
    };

}