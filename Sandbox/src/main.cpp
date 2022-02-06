#include <iostream>
#include <vector>

#include <GLFW/glfw3.h>

#include <Little.h>

void ok();
bool OnMouseButtonDown(lil::MouseButtonDownEvent& e);
bool OnKeyDown(lil::KeyDownEvent& e);

int main(){

    lil::Application::Get()->Init();

    lil::KeyDownEvent eKey(GLFW_KEY_W, false);

    lil::MouseButtonDownEvent eMouse(GLFW_MOUSE_BUTTON_1, GLFW_PRESS);

    lil::Dispatcher dispatcher(eMouse);
    dispatcher.Dispatch<lil::MouseButtonDownEvent>(OnMouseButtonDown);

    lil::Dispatcher disKey(eKey);
    disKey.Dispatch<lil::KeyDownEvent>(OnKeyDown);

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