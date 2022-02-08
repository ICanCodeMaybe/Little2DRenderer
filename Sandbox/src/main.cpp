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

    float data[4*3] = {
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f
    };

    unsigned int indecies[2*3] = {0, 1, 3, 1, 2, 3};

    unsigned int VAO, IBO;

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    lil::VertexBuffer VBO(data, sizeof(data));
    VBO.Bind();

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

   lil::IndexBuffer(indecies, 6);
//shader
    lil::Shader shader("Sandbox/src/shaders/red.vs", "Sandbox/src/shaders/red.fg");
    shader.Bind();

    while(!shouldClose){
        window.ClearWithColor(glm::vec4(0.1f, 0.2f, 0.3f, 1.0f));
        
        shader.Bind();
        shader.set4xFloat("color", {0.5f, 0.3f, 1.7f, 1.0f});

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        //glDrawArrays(GL_TRIANGLES, 0, 3);

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
