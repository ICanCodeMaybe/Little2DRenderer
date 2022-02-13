cmake_minimum_required(VERSION 3.18.1)
project(Little)

set(LITTLE_HEADERS 
    src/log.h src/Application.h 
#event headers
    src/Events/KeyboardEvent.h src/Events/MouseEvent.h 
    src/Events/Event.h
#window header
    src/Window.h
#renderer
    src/Renderer/Buffers.h src/Renderer/Shader.h
    src/Renderer/VertexArray.h src/Renderer/RendererCommand.h
    src/Renderer/OrthoCam.h src/Renderer/Renderer.h
    src/Renderer/Primitives.h)

set(LITTLE_CPP
    src/Application.cpp 
#window
    src/Window.cpp
#renderer
    src/Renderer/Buffers.cpp  src/Renderer/VertexArray.cpp
    src/Renderer/RendererCommand.cpp src/Renderer/OrthoCam.cpp
    src/Renderer/Renderer.cpp src/Renderer/Primitives.cpp)

add_library(${PROJECT_NAME} ${LITTLE_CPP} ${LITTLE_HEADERS})

add_subdirectory(../external/glfw glfw/)
add_subdirectory(../external/glad glad/)
add_subdirectory(../external/glm glm/)

target_include_directories(${PROJECT_NAME}
    PUBLIC .
    PUBLIC src/
    PUBLIC ../external/glad/include/
    PUBLIC ../external/glfw/include/
    PUBLIC ../external/glm/
)

target_link_directories(${PROJECT_NAME}
    PUBLIC .
    PUBLIC src/     
    PUBLIC ../external/glad/include/glad/
    PUBLIC../external/glad/src/
    PUBLIC ../external/glfw/src/
)

target_link_libraries(${PROJECT_NAME} glfw glad glm)