#include <iostream>
#include <vector>

#include <GLFW/glfw3.h>

#include <Little.h>

void ok();


int main(){

    lil::Application::Get()->Init();

    LIL_ERROR("You have made mistake")
    LIL_WARNING("Watchout")
    LIL_INFO("Some interesting fact")

    lil::KeyDownEvent e(GLFW_KEY_W, false);
    lil::MouseButtonPressedEvent eMouse(GLFW_MOUSE_BUTTON_1, GLFW_PRESS);



    e.LogIt();
    if(eMouse.GetEventType() == lil::EventType::MouseButtonPressed)
        LIL_WARNING("MouseButtonPressed")
    eMouse.LogIt();

    return 0;
}