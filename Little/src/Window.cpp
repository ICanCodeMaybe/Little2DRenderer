#include "src/Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Events/WindowEvent.h>
#include <Events/MouseEvent.h>
#include <Events/KeyboardEvent.h>

namespace lil{
    Window::Window() : m_windowSpecs(nullptr){}
    Window::~Window(){}

    void Window::Create(WindowSpecs& windowSpecs){
        m_windowSpecs = &windowSpecs;
        m_window = glfwCreateWindow(m_windowSpecs->width, m_windowSpecs->height, 
                                    m_windowSpecs->title, nullptr, nullptr);

        if(!m_window){
            LIL_ERROR("Window was not created!")
        }

        glfwSetWindowUserPointer(m_window, m_windowSpecs);

    //GLFW window event handeling
        glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window){
            WindowSpecs mySpecs = *(WindowSpecs*)glfwGetWindowUserPointer(window);

            WindowCloseEvent myEvent(mySpecs.title);
            mySpecs.CallbackEventFn(myEvent);
        });

        glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height){
            WindowSpecs& mySpecs = *(WindowSpecs*)glfwGetWindowUserPointer(window);

            mySpecs.width = width;
            mySpecs.height = height;

            WindowResizeEvent event(width, height);

            mySpecs.CallbackEventFn(event);


        //-----view port changing------------
        //-----(temporary)-----------------
            glViewport(0, 0, width, height);
        });

        glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xPos, double yPos){
            WindowSpecs& mySpecs = *(WindowSpecs*)glfwGetWindowUserPointer(window);

            MousePositionEvent event(xPos, yPos);
            mySpecs.CallbackEventFn(event);
        });

        glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods){
            WindowSpecs& mySpecs = *(WindowSpecs*)glfwGetWindowUserPointer(window);

            switch(action){
                case GLFW_PRESS:
                {
                    MouseButtonPressedEvent pressEvent(button, GLFW_PRESS);
                    mySpecs.CallbackEventFn(pressEvent);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseButtonReleasedEvent releaseEvent(button, GLFW_RELEASE);
                    mySpecs.CallbackEventFn(releaseEvent);
                    break;
                }
                case GLFW_REPEAT:
                {
                    MouseButtonDownEvent downEvent(button, GLFW_REPEAT);
                    mySpecs.CallbackEventFn(downEvent);
                    break;
                }
            };

        });

        glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods){
            WindowSpecs& mySpecs = *(WindowSpecs*)glfwGetWindowUserPointer(window);

            switch(action){
                case GLFW_PRESS:
                {
                    KeyPressedEvent pressEvent(key);
                    mySpecs.CallbackEventFn(pressEvent);
                    break;
                }
                case GLFW_KEY_DOWN:
                {
                    KeyDownEvent downEvent(key, false);
                    mySpecs.CallbackEventFn(downEvent);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent releaseEvent(key);
                    mySpecs.CallbackEventFn(releaseEvent);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyDownEvent downEvent(key, true);
                    mySpecs.CallbackEventFn(downEvent);
                    break;
                }
            }
        });
    }

    void Window::SwapBuffers(){
        glfwSwapBuffers(m_window);
    }

    void Window::HandleEvents(){
        glfwPollEvents();
    }

}