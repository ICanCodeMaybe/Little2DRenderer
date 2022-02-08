#include "Buffers.h"

#include <glad/glad.h>

namespace lil{

//---------Vertex Buffer------------------

    VertexBuffer::VertexBuffer(float* data, int size){
        glGenBuffers(1, &m_id);
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }

    void VertexBuffer::Bind(){
        glBindBuffer(GL_ARRAY_BUFFER, m_id);
    }

    void VertexBuffer::Unbind(){
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }


//--------Index Buffer---------------------

    IndexBuffer::IndexBuffer(unsigned int* indecies, unsigned int count)
        :m_count(count)
    {
        glGenBuffers(1, &m_id);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned), indecies, GL_STATIC_DRAW);
    }

    void IndexBuffer::Bind(){
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
    }

    void IndexBuffer::Unbind(){
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}