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

    float data[4*3*2] = {
     0.75f,  0.75f, 0.0f,     1.0f, 0.0f, 0.0f, // top right
     0.75f, -0.75f, 0.0f,     0.0f, 1.0f, 0.0f,// bottom right
    -0.75f, -0.75f, 0.0f,     0.0f, 0.0f, 1.0f,// bottom left
    -0.75f,  0.75f, 0.0f,     1.0f, 1.0f, 1.0f
    };
    float triangleData[3*3*2] = {
    0.5f,  0.5f, 0.0f,     1.0f, 0.0f, 0.0f, // top right
     0.5f, -0.5f, 0.0f,     1.0f, 0.0f, 0.0f,// bottom right
    -0.5f, -0.5f, 0.0f,     1.0f, 0.0f, 1.0f
    };

    unsigned int indecies[2*3] = {0, 1, 3, 1, 2, 3};
    unsigned int TriangleIndecies[3] = {0, 1, 2,};

    lil::VertexArray VAO;

    lil::VertexBuffer VBO(data, sizeof(data));
    VBO.Bind();


    VAO.AddVertexAttribute(lil::TYPES::FloatX3);
    VAO.AddVertexAttribute(lil::TYPES::FloatX3);
    VAO.EnableVertexAttributes();


    lil::IndexBuffer IBO(indecies, 6);
    VAO.AddIBO(&IBO);

//------TRIANGLE VAO---------------
    lil::VertexArray TriangleVao;
    lil::VertexBuffer VBO1(triangleData, sizeof(triangleData));
    VBO1.Bind();

    TriangleVao.AddVertexAttribute(lil::TYPES::FloatX3);// positions
    TriangleVao.AddVertexAttribute(lil::TYPES::FloatX3);// colors
    TriangleVao.EnableVertexAttributes();

    lil::IndexBuffer TriagnleIBO(TriangleIndecies, 3);
    TriangleVao.AddIBO(&TriagnleIBO);
//---------------------------------

//shader
    lil::Shader shader("Sandbox/src/shaders/red.vs", "Sandbox/src/shaders/red.fg");
    shader.Bind();

    while(!shouldClose){
        lil::RendererCommand::Get()->SetClearColor({0.1f, 0.2f, 0.3f, 1.0f});
        lil::RendererCommand::Get()->Clear();
          
        shader.Bind();

        lil::RendererCommand::Get()->DrawIndexed(VAO);
        lil::RendererCommand::Get()->DrawIndexed(TriangleVao);

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
