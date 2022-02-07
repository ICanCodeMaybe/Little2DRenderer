#include "Application.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace lil{
    Application* Application::s_instance;

    Application::Application(){
    }

    Application::~Application(){}

    void Application::Init(){
        LIL_INFO("Little is running")

        //initializing glfw
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }

    void Application::CreateOpenglContext(GLFWwindow* window){
        m_window = window;
        glfwMakeContextCurrent(m_window);

        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
             LIL_ASSERT(1 == 1,"OPENGL CONTEXT WAS NOT CREATED");
        }   

    }

    Application* Application::Get(){
        if(!s_instance){
            s_instance = new Application;
            LIL_INFO("CREATED APP")
        }
        return Application::s_instance;
    }
}