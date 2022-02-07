#include <iostream>
#include <vector>

#include <GLFW/glfw3.h>

#include <Little.h>

void ok();
bool OnMouseButtonDown(lil::MouseButtonDownEvent& e);
bool OnKeyDown(lil::KeyDownEvent& e);

bool shouldClose = false;
int main(){

    lil::Application::Get()->Init();

//window creation
    lil::Window window;
    lil::WindowSpecs spec;
    window.Create(spec);

    lil::Application::Get()->CreateOpenglContext(window.GetWindowPointer());

    lil::KeyDownEvent eKey(GLFW_KEY_W, false);
    lil::MouseButtonDownEvent eMouse(GLFW_MOUSE_BUTTON_1, GLFW_PRESS);
    
    lil::Dispatcher dispatcher(eMouse);
    dispatcher.Dispatch<lil::MouseButtonDownEvent>(OnMouseButtonDown);
    lil::Dispatcher disKey(eKey);
    disKey.Dispatch<lil::KeyDownEvent>(OnKeyDown);

    while(!shouldClose){
        window.ClearWithColor(1.0f, 0.0f, 1.0f, 1.0f);

        window.HandleEvents();
        window.SwapBuffers();
    }
    return 0;
}

bool OnMouseButtonDown(lil::MouseButtonDownEvent& e){
    LIL_INFO("OnMouseButtonDown func has been called")
    e.LogIt();
    return true;
}

bool OnKeyDown(lil::KeyDownEvent& e){
    LIL_INFO("Key down: " << (char)e.GetKeyCode())
    e.LogIt();
    return true;
}