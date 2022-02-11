#include "Renderer.h"

#include "RendererCommand.h"

namespace lil{
    Renderer * Renderer::s_Instance = new Renderer;

    Renderer::Renderer(){

    }

    void Renderer::BeginScene(OrthoCamera* cam){
        m_OrthoCam = cam;
    }

    void Renderer::DrawIndexed(Shader& shader, VertexArray& VAO, glm::mat4 transform){
        shader.setMat4x("vp", Renderer::Get()->GetOrthCam()->GetViewProjectionMatrix());
        RendererCommand::Get()->DrawIndexed(shader, VAO, transform);
    }

    void Renderer::EndScene(){

    }
}