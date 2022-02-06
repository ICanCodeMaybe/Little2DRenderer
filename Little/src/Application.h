#pragma once

#include "log.h"


namespace lil{

    class Application{
        public: 

            static Application* Get();
        
            void Init();
        
        private:
            Application();
            ~Application();

            static Application* s_instance;
    };

}