#pragma once

#include <glm/glm.hpp>

#include "src/log.h"
#include "VertexArray.h"

namespace lil{

    class RendererCommand{
    public:
        static RendererCommand* Get() { return s_instance; }

        void SetClearColor(glm::vec4 color);
        void Clear();

        void DrawIndexed(VertexArray& VAO);

    private:
        RendererCommand();

    private:
        static RendererCommand* s_instance;
    };

}