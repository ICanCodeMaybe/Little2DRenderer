#include "Application.h"

namespace lil{
    Application* Application::s_instance;

    Application::Application(){
    }

    void Application::Init(){
        LIL_INFO("Little is running")
    }
    Application::~Application(){}

    Application* Application::Get(){
        if(!s_instance){
            s_instance = new Application;
            LIL_INFO("CREATED APP")
        }
        return Application::s_instance;
    }
}