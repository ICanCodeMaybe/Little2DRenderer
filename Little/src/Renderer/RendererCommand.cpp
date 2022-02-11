#include "RendererCommand.h"

#include <glad/glad.h>

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
}