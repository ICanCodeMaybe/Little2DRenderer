#include "VertexArray.h"




namespace lil{

    VertexArray::VertexArray(){
        glGenVertexArrays(1, &m_id);
        glBindVertexArray(m_id);
    }

    void VertexArray::Bind(){
        glBindVertexArray(m_id);
    }

    void VertexArray::Unbind(){
        glBindVertexArray(0);
    }

    void VertexArray::AddVertexAttribute(TYPES type, bool normalized){
        m_types.emplace_back(type);
        m_normalized.emplace_back(normalized);
        m_index++;
    }

    void  VertexArray::EnableVertexAttributes(){
        m_stride = GetStride();

        for(int i = 0; i < m_index; i++){
            glVertexAttribPointer(i, GetNumOfComponents(i), GetGLEnum(i),
                    m_normalized[i], m_stride, (void*)GetOffset(i));     
            glEnableVertexAttribArray(i);
        }
    }

    unsigned int VertexArray::GetNumOfComponents(unsigned int index){
        switch(m_types[index]){
            case TYPES::Float:    { return 1; }
            case TYPES::Int:      { return 1; }
            case TYPES::Bool:     { return 1; }
            case TYPES::FloatX2:  { return 2; }
            case TYPES::IntX2:    { return 2; }
            case TYPES::BoolX2:   { return 2; }
            case TYPES::FloatX3:  { return 3; }
            case TYPES::IntX3:    { return 3; }
            case TYPES::BoolX3:   { return 3; }
            case TYPES::FloatX4:  { return 4; }
            case TYPES::IntX4:    { return 4; }
            case TYPES::BoolX4:   { return 4; }
        }
    }

    GLenum VertexArray::GetGLEnum(unsigned int index){
        switch(m_types[index]){
            case TYPES::Float:    { return GL_FLOAT; }
            case TYPES::Int:      { return GL_INT; }
            case TYPES::Bool:     { return GL_BOOL; }
            case TYPES::FloatX2:  { return GL_FLOAT; }
            case TYPES::IntX2:    { return GL_INT; }
            case TYPES::BoolX2:   { return GL_BOOL; }
            case TYPES::FloatX3:  { return GL_FLOAT; }
            case TYPES::IntX3:    { return GL_INT; }
            case TYPES::BoolX3:   { return GL_BOOL; }
            case TYPES::FloatX4:  { return GL_FLOAT; }
            case TYPES::IntX4:    { return GL_INT; }
            case TYPES::BoolX4:   { return GL_BOOL; }
        }
    }

    unsigned int VertexArray::GetSize(unsigned int index){
        switch(m_types[index]){
            case TYPES::Float:    { return 1 * sizeof(float); }
            case TYPES::Int:      { return 1 * sizeof(int); }
            case TYPES::Bool:     { return 1 * sizeof(bool); }
            case TYPES::FloatX2:  { return 2 * sizeof(float); }
            case TYPES::IntX2:    { return 2 * sizeof(int); }
            case TYPES::BoolX2:   { return 2 * sizeof(bool); }
            case TYPES::FloatX3:  { return 3 * sizeof(float); }
            case TYPES::IntX3:    { return 3 * sizeof(int); }
            case TYPES::BoolX3:   { return 3 * sizeof(bool); }
            case TYPES::FloatX4:  { return 4 * sizeof(float); }
            case TYPES::IntX4:    { return 4 * sizeof(int); }
            case TYPES::BoolX4:   { return 4 * sizeof(bool); }
        }
    }

    unsigned int VertexArray::GetStride(){
        unsigned int stride = 0;
        unsigned int index = 0;
        for(TYPES type : m_types){
            stride += GetSize(index);
            index++;
        }
        return stride;
    }

    unsigned int VertexArray::GetOffset(unsigned int index){
        unsigned int offset = 0;
        for(int i = 0; i < index; i++){
            offset += GetSize(i);
        }

        return offset;
    }
}