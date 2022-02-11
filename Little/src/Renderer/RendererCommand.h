#pragma once

#include <glm/glm.hpp>

#include "src/log.h"
#include "VertexArray.h"
#include "Shader.h"

namespace lil{

    class RendererCommand{
    public:
        static RendererCommand* Get() { return s_instance; }

        void SetClearColor(glm::vec4 color);
        void Clear();

        void DrawIndexed(Shader& shader, VertexArray& VAO);
        void DrawIndexed(Shader& shader, VertexArray& VAO, glm::mat4& transform);

    private:
        RendererCommand();

    private:
        static RendererCommand* s_instance;
    };

}