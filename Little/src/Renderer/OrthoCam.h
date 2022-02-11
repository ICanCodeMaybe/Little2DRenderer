#pragma once

#include <glm/glm.hpp>


namespace lil{

    class OrthoCamera{
    public:
        OrthoCamera(float left, float right, float near, float far);

        void SetPosition(glm::vec3 position);
        glm::vec3 GetPosition() { return m_position; }
        
        void SetRotation(float angle);
        float GetRotation() { return m_rotation; }

        glm::mat4 GetViewProjectionMatrix() { return m_viewPorojectionMatrix; }
        glm::mat4 GetViewMatrix() { return m_viewMatrix; }
        glm::mat4 GetProjectionMatrix() { return m_projectionMatrix; }
    private:
        void CalculateViewProjection();
    private:

        glm::vec3 m_position = glm::vec3(0.0f);
        float m_rotation = 0.0f;

        glm::mat4 m_projectionMatrix = glm::mat4(1.0f);
        glm::mat4 m_viewMatrix = glm::mat4(1.0f);
        glm::mat4 m_viewPorojectionMatrix = glm::mat4(1.0f);
    };

}   