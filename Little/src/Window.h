#pragma once
#include <functional>

#include "src/Events/Event.h"
#include <glm/glm.hpp>

struct GLFWwindow;


namespace lil{
    struct WindowSpecs
    {

        int width = 1280;
        int height = 720;
        const char* title = "Super window!";

        std::function<void(Event& e)> CallbackEventFn = nullptr;
    };

    class Window{
    public:
        Window();
        ~Window();

        void Create(WindowSpecs& WindowSpecification);

        void SwapBuffers();
        void HandleEvents();

        void ClearWithColor(glm::vec4 color);

        GLFWwindow* GetWindowPointer() { return m_window; }
    private:
        GLFWwindow* m_window;

        WindowSpecs* m_windowSpecs = nullptr;
    };
}
