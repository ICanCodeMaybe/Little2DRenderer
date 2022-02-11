#include "OrthoCam.h"
#include <glm/gtc/matrix_transform.hpp>

namespace lil{

        OrthoCamera::OrthoCamera(float left, float right, float down, float top)
            : m_projectionMatrix(glm::ortho(left, right, down, top, 1.0f, -1.0f)){

        }

        void OrthoCamera::SetPosition(glm::vec3 position){
            m_position = position;
            CalculateViewProjection();
        }
        
        void OrthoCamera::SetRotation(float angle){
            m_rotation = angle;
            CalculateViewProjection();
        }

        void OrthoCamera::CalculateViewProjection(){
            glm::mat4 transform = glm::mat4(1.0f);
            transform = glm::translate(glm::mat4(1.0f), m_position)
                        * glm::rotate(glm::mat4(1.0f), glm::radians(m_rotation), glm::vec3(0.0f, 0.0f, 1.0f));

            m_viewMatrix = glm::inverse(transform);

            m_viewPorojectionMatrix = m_projectionMatrix * m_viewMatrix;    
        }

}