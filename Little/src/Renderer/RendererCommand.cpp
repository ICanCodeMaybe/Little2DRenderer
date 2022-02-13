#include "RendererCommand.h"

#include <glad/glad.h>


#include "Renderer.h"

namespace lil{
    RendererCommand* RendererCommand::s_instance = new RendererCommand();

    RendererCommand::RendererCommand(){

    }

    void RendererCommand::SetClearColor(glm::vec4 color){
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void RendererCommand::Clear(){
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void RendererCommand::DrawIndexed(Shader& shader, VertexArray& VAO){
        shader.Bind();
        VAO.Bind();
        glDrawElements(GL_TRIANGLES, VAO.GetIBO()->GetCount(), GL_UNSIGNED_INT, 0);
    }

    void RendererCommand::DrawIndexed(Shader& shader, VertexArray& VAO, glm::mat4& transform){
        shader.Bind();
        shader.setMat4x("model", transform);
        VAO.Bind();
        glDrawElements(GL_TRIANGLES, VAO.GetIBO()->GetCount(), GL_UNSIGNED_INT, 0);
    }

    void RendererCommand::DrawQuad(Quad& quad){
        quad.GetShader()->setMat4x("vp", Renderer::Get()->GetOrthCam()->GetViewProjectionMatrix());
        quad.GetShader()->Bind();
        quad.GetShader()->set3xFloat("color", quad.GetColor());
        quad.GetShader()->setMat4x("model", quad.GetTransformationMat());
        quad.GetVAO()->Bind();
        glDrawElements(GL_TRIANGLES, quad.GetVAO()->GetIBO()->GetCount(), GL_UNSIGNED_INT, 0);
    }

    void RendererCommand::DrawCircle(Circle& circle){
        circle.GetShader()->setMat4x("vp", Renderer::Get()->GetOrthCam()->GetViewProjectionMatrix());

        circle.GetShader()->Bind();
        circle.GetShader()->setMat4x("model", circle.GetTransformationMat());

        circle.GetShader()->set2xFloat("WidthHeight", { Renderer::Get()->GetWindow()->GetWindowSpecification()->width,
                                                        Renderer::Get()->GetWindow()->GetWindowSpecification()->height});

        circle.GetVAO()->Bind();
        glDrawElements(GL_TRIANGLES, circle.GetVAO()->GetIBO()->GetCount(), GL_UNSIGNED_INT, 0);
    }
}