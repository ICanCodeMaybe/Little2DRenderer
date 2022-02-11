#include <iostream>
#include <vector>

#include <glm/glm.hpp>

#include <Little.h>

#include <GLFW/glfw3.h>
void OnEvent(lil::Event& e);
bool OnMouseButtonDown(lil::MouseButtonDownEvent& e);
bool OnKeyPressed(lil::KeyPressedEvent& e);
bool OnKeyRelease(lil::KeyReleasedEvent& e);

bool shouldClose = false;

lil::OrthoCamera cam(-1.0f, 1.0f, -1.0f, 1.0f);
glm::vec2 camPos = glm::vec2(0.0f);

bool Key_W = false,  Key_S = false,  Key_A = false, Key_D;

int main(){

    lil::Application::Get()->Init();

//window creation
    lil::WindowSpecs spec;
    spec.CallbackEventFn = OnEvent;
    
    lil::Window window;
    window.Create(spec);

    lil::Application::Get()->CreateOpenglContext(window.GetWindowPointer());

    float data[4*3*2] = {
     0.5f,  0.5f, 0.0f,     1.0f, 0.0f, 0.0f, // top right
     0.5f, -0.5f, 0.0f,     0.0f, 1.0f, 0.0f,// bottom right
    -0.5f, -0.5f, 0.0f,     0.0f, 0.0f, 1.0f,// bottom left
    -0.5f,  0.5f, 0.0f,     1.0f, 1.0f, 1.0f
    };
    float triangleData[3*3] = {
    0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,// bottom right
    -0.5f, -0.5f, 0.0f
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
    TriangleVao.EnableVertexAttributes();

    lil::IndexBuffer TriagnleIBO(TriangleIndecies, 3);
    TriangleVao.AddIBO(&TriagnleIBO);
//---------------------------------

//shader
    lil::Shader shader("Sandbox/src/shaders/red.vs", "Sandbox/src/shaders/red.fg");
    lil::Shader green("Sandbox/src/shaders/green.vert", "Sandbox/src/shaders/green.frag");


    glm::mat4 greenTrans = glm::mat4(1.0f);
    greenTrans = glm::translate(glm::mat4(1.0f), {1.0f, 1.0f, 0.0f})
        *glm::scale(glm::mat4(1.0f), {0.5f, 0.5f, 1.0f});
    
    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(glm::mat4(1.0f), {1.0f, 1.0f, 0.0f});

    while(!shouldClose){
        lil::RendererCommand::Get()->SetClearColor({0.1f, 0.2f, 0.3f, 1.0f});
        lil::RendererCommand::Get()->Clear();

     //This imput system is done realy wierdly, i'll have to work on it   
        if(Key_W == true)
            camPos.y += 0.1f;
        if(Key_S == true)
            camPos.y -= 0.1f;
        if(Key_D == true)
            camPos.x += 0.1f;
        if(Key_A == true)
            camPos.x -= 0.1f;

        //settting cameras's postition
        cam.SetPosition({camPos.x, camPos.y, 1.0f});

        //rendering
        lil::Renderer::Get()->BeginScene(&cam);

        lil::Renderer::Get()->DrawIndexed(shader, VAO, trans);
        lil::Renderer::Get()->DrawIndexed(green, TriangleVao, greenTrans);
        
        lil::Renderer::Get()->EndScene();

        window.HandleEvents();
        window.SwapBuffers();
    }
    return 0;
}

void OnEvent(lil::Event& e){
    e.LogIt();
    
    if(e.GetEventType() == lil::EventType::WindowClosed)
        shouldClose = true;

    lil::Dispatcher dispatcher(e);
    dispatcher.Dispatch<lil::KeyPressedEvent>(OnKeyPressed);
       dispatcher.Dispatch<lil::KeyReleasedEvent>(OnKeyRelease);
}

bool OnKeyPressed(lil::KeyPressedEvent& e){
    if(e.GetKeyCode() == GLFW_KEY_W)
        Key_W = true;
    if(e.GetKeyCode() == GLFW_KEY_S)
        Key_S = true; 
    if(e.GetKeyCode() == GLFW_KEY_A)
        Key_A = true;
    if(e.GetKeyCode() == GLFW_KEY_D)
        Key_D = true;

    return true;
}

bool OnKeyRelease(lil::KeyReleasedEvent& e){
    if(e.GetKeyCode() == GLFW_KEY_W)
        Key_W = false;
    if(e.GetKeyCode() == GLFW_KEY_S)
        Key_S = false; 
    if(e.GetKeyCode() == GLFW_KEY_A)
        Key_A = false;
    if(e.GetKeyCode() == GLFW_KEY_D)
        Key_D = false; 


    return true;
}
