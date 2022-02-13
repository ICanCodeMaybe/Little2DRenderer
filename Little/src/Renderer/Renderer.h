#pragma once

#include <glm/glm.hpp>

#include "OrthoCam.h"
#include "VertexArray.h"
#include "Shader.h"

#include "Primitives.h"
#include "Window.h"
namespace lil{

    class Renderer{
    public:
        static Renderer* Get() { return s_Instance; }
        
        void BeginScene(OrthoCamera* camera);

        void DrawIndexed(Shader& shader, VertexArray& VAO, glm::mat4 transform = glm::mat4(1.0f));
        void DrawQuad(Quad& quad);
        void DrawCircle(Circle& circle);
        void EndScene();

        void SetWindow(Window* window) { m_window = window; }

        Window* GetWindow() { return m_window; }
        OrthoCamera* GetOrthCam() { return Get()->m_OrthoCam; }

    private:
        Renderer();

    private:
        static Renderer* s_Instance;

        OrthoCamera* m_OrthoCam;
        Window* m_window;
    };

}