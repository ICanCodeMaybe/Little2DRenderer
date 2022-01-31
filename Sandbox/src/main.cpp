#include <iostream>
#include <vector>

#include <GLFW/glfw3.h>

#include <Little.h>

void ok();
int main(){
    SaySomething("cusik");

    glfwInit();

    if(!glfwInit())
        std::cout << "glfw was not initialized \n";
    
    GLFWwindow* window = glfwCreateWindow(1280, 720, "wow okno", nullptr, nullptr);


    while(!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}