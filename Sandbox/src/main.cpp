#include <iostream>
#include <vector>

//#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <Little.h>

void OnEvent(lil::Event& e);
bool OnMouseButtonDown(lil::MouseButtonDownEvent& e);
bool OnKeyDown(lil::KeyDownEvent& e);

bool shouldClose = false;

int main(){

    lil::Application::Get()->Init();

//window creation
    lil::WindowSpecs spec;
    spec.CallbackEventFn = OnEvent;
    
    lil::Window window;
    window.Create(spec);

    lil::Application::Get()->CreateOpenglContext(window.GetWindowPointer());



    while(!shouldClose){
        window.ClearWithColor(glm::vec4(0.5f, 0.1f, 0.7f, 1.0f));

        window.HandleEvents();
        window.SwapBuffers();
    }
    return 0;
}

void OnEvent(lil::Event& e){
    e.LogIt();
    
    if(e.GetEventType() == lil::EventType::WindowClosed)
        shouldClose = true;
}
