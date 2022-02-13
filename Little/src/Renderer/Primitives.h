#pragma once

#include <glm/glm.hpp>

#include "Buffers.h"
#include "VertexArray.h"
#include "Shader.h"

#include "src/Window.h"
namespace lil{

//----------------QUAD----------------------------
    class Quad{
    public:
        Quad(glm::vec3 color, glm::vec2 position = {0.0f, 0.0f}, glm::vec2 size = {1.0f, 1.0f}, Shader* shader = nullptr);
        ~Quad();

        VertexArray* GetVAO() { return m_VAO; }
        Shader* GetShader() { return m_shader; }

        glm::vec3 GetColor() { return m_color; }

        glm::vec2 GetSize() { return m_size; }
        glm::vec2 GetPosition() { return m_position; }
        glm::mat4 GetTransformationMat() { return m_transform; }

        void SetPosition(glm::vec2 position);
        void SetSize(glm::vec2 size);

        void MoveBy(glm::vec2 distance);
        void ScaleBy(glm::vec2 scale);

        void CalculateTransform();

    private:
        unsigned int m_id;

        VertexArray* m_VAO;
        IndexBuffer* m_IBO;
        VertexBuffer* m_VBO;

        Shader* m_shader;

        glm::mat4 m_transform = glm::mat4(1.0f);

        glm::vec2 m_position;
        glm::vec2 m_size;  
    
        glm::vec3 m_color;
    };
//----------------------------------------------------------------------

//--------------CIRCLE-------------------------------------------------

    class Circle{
    public:
        Circle(glm::vec3 color, glm::vec2 position = {0.0f, 0.0f}, glm::vec2 size = {1.0f, 1.0f}, Shader* shader = nullptr);
        ~Circle();

        VertexArray* GetVAO() { return m_VAO; }
        Shader* GetShader() { return m_shader; }

        glm::vec3 GetColor() { return m_color; }

        glm::vec2 GetSize() { return m_size; }
        glm::vec2 GetPosition() { return m_position; }
        glm::mat4 GetTransformationMat() { return m_transform; }

        void SetPosition(glm::vec2 position);
        void SetSize(glm::vec2 size);

        void MoveBy(glm::vec2 distance);
        void ScaleBy(glm::vec2 scale);

        void CalculateTransform();

    private:
        unsigned int m_id;

        VertexArray* m_VAO;
        IndexBuffer* m_IBO;
        VertexBuffer* m_VBO;

        Shader* m_shader;

        glm::mat4 m_transform = glm::mat4(1.0f);

        glm::vec2 m_position;
        glm::vec2 m_size;  
    
        glm::vec3 m_color;
    };
//-----------------------------------------------------------------------------
}