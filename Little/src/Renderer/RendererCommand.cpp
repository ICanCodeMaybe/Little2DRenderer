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

    void RendererCommand::DrawIndexed(VertexArray& VAO){
        VAO.Bind();
        glDrawElements(GL_TRIANGLES, VAO.GetIBO()->GetCount(), GL_UNSIGNED_INT, 0);
    }
}