#include "Application.h"

    lil::Application* lil::Application::s_instance;
namespace lil{

    Application::Application(){
    }

    void Application::Init(){
        LIL_INFO("Little is running")
    }
    Application::~Application(){}

    Application* Application::Get(){
        return Application::s_instance;
    }
}