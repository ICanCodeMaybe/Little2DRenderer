#include "Primitives.h"

#include <glm/gtc/matrix_transform.hpp>



static float QuadData[3 * 4] = {
     0.5f,  0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    -0.5f,  0.5f, 0.0f,
};

static unsigned int QuadIndecies[] = {
    0, 1, 2,
    0, 2, 3
};

namespace lil{
//-----------QUAD-----------------------------------------------
        Quad::Quad(glm::vec3 color, glm::vec2 position, glm::vec2 size, Shader* shader)
            : m_color(color), m_position(position), m_size(size), m_shader(shader){
            CalculateTransform();

            //Creating VBO & IBO
            m_VBO = new VertexBuffer(QuadData, sizeof(QuadData));
            m_IBO = new IndexBuffer(QuadIndecies, 6);

            //Creating VAO
            m_VAO = new VertexArray;
            m_VAO->Bind();

            //Seting vertex attributes to VAO
            m_VBO->Bind();
            m_VAO->AddVertexAttribute(TYPES::FloatX3);
            m_VAO->EnableVertexAttributes();
            
            //Setting IBO
            m_IBO->Bind();
            m_VAO->AddIBO(m_IBO);

            //Shader
            if(!m_shader)
                m_shader = new Shader("Little/src/Shaders/Quad.vert", "Little/src/Shaders/Quad.frag");
        }

        Quad::~Quad(){
            delete m_VAO;
            delete m_VBO;
            delete m_IBO;
            delete m_shader;
        }

        void Quad::SetPosition(glm::vec2 position) { m_position = position; CalculateTransform(); }
        void Quad::SetSize(glm::vec2 size) { m_size = size; CalculateTransform(); }

        void Quad::MoveBy(glm::vec2 distance) { m_position += distance; CalculateTransform(); }
        void Quad::ScaleBy(glm::vec2 scale) { m_size *= scale; CalculateTransform(); };

        void Quad::CalculateTransform() {
            m_transform = glm::translate(glm::mat4(1.0f), {m_position, 0.0f})
                        * glm::scale(glm::mat4(1.0f), {m_size, 1.0f});
        }
//--------------------------------------------------------------------------


//--------------------CIRCLE------------------------------------------------

        Circle::Circle(glm::vec3 color, glm::vec2 position, glm::vec2 size, Shader* shader)
            : m_color(color), m_position(position), m_size(size), m_shader(shader){
            CalculateTransform();

            //Creating VBO & IBO
            m_VBO = new VertexBuffer(QuadData, sizeof(QuadData));
            m_IBO = new IndexBuffer(QuadIndecies, 6);

            //Creating VAO
            m_VAO = new VertexArray;
            m_VAO->Bind();

            //Seting vertex attributes to VAO
            m_VBO->Bind();
            m_VAO->AddVertexAttribute(TYPES::FloatX3);
            m_VAO->EnableVertexAttributes();
            
            //Setting IBO
            m_IBO->Bind();
            m_VAO->AddIBO(m_IBO);

            //Shader
            if(!m_shader)
                m_shader = new Shader("Little/src/Shaders/Circle.vert", "Little/src/Shaders/Circle.frag");
        }

        Circle::~Circle(){
            delete m_VAO;
            delete m_VBO;
            delete m_IBO;
            delete m_shader;
        }

        void Circle::SetPosition(glm::vec2 position) { m_position = position; CalculateTransform(); }
        void Circle::SetSize(glm::vec2 size) { m_size = size; CalculateTransform(); }

        void Circle::MoveBy(glm::vec2 distance) { m_position += distance; CalculateTransform(); }
        void Circle::ScaleBy(glm::vec2 scale) { m_size *= scale; CalculateTransform(); };

        void Circle::CalculateTransform() {
            m_transform = glm::translate(glm::mat4(1.0f), {m_position, 0.0f})
                        * glm::scale(glm::mat4(1.0f), {m_size, 1.0f});
        }

}