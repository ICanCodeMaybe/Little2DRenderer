#pragma once

#include <glad/glad.h>

#include <vector>

#include "Buffers.h"

namespace lil{

    enum class TYPES{
        None = 0,
        Float,
        Int,
        Bool,
        FloatX2,
        FloatX3,
        FloatX4,
        IntX2,
        IntX3,
        IntX4,
        BoolX2,
        BoolX3,
        BoolX4,
    };

    
    class VertexArray{
    public:
        VertexArray();

        void AddVertexAttribute(TYPES type, bool normalized = false);
        void EnableVertexAttributes();

        void Bind();
        void Unbind();
        
        void AddIBO(IndexBuffer* IBO) { m_IBO = IBO; }
        IndexBuffer* GetIBO() { return m_IBO; }

    private:
        unsigned int GetNumOfComponents(unsigned int index);
        GLenum GetGLEnum(unsigned int index);
        unsigned int GetStride();
        unsigned int GetOffset(unsigned int index);
        unsigned int GetSize(unsigned int index);
        
    private:
        unsigned int m_id;

        unsigned int m_index = 0;
        unsigned int m_stride;
        std::vector<TYPES> m_types;
        std::vector<bool> m_normalized;

        IndexBuffer* m_IBO;
    };
}