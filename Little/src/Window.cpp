#include "src/Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace lil{
    Window::Window(){}
    Window::~Window(){}

    void Window::Create(WindowSpecs& windowSpecs){
        m_window = glfwCreateWindow(windowSpecs.width, windowSpecs.height, 
                                    windowSpecs.title, nullptr, nullptr);

        if(!m_window){
            LIL_ERROR("Window was not created!")
        }

    //TODO: Set event callbacks!
    }

    void Window::SwapBuffers(){
        glfwSwapBuffers(m_window);
    }

    void Window::HandleEvents(){
        glfwPollEvents();
    }

    void Window::ClearWithColor(float r, float g,float b,float a){
        glClearColor(r, g, b, a);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}