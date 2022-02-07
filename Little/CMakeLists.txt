cmake_minimum_required(VERSION 3.18.1)
project(Little)

set(LITTLE_HEADERS 
    src/log.h src/Application.h 
#event headers
    src/Events/KeyboardEvent.h src/Events/MouseEvent.h 
    src/Events/Event.h
#window header
    src/Window.h)

set(LITTLE_CPP
    src/Application.cpp 
#window
    src/Window.cpp)

add_library(${PROJECT_NAME} ${LITTLE_CPP} ${LITTLE_HEADERS})

add_subdirectory(../external/glfw glfw/)
add_subdirectory(../external/glad glad/)

target_include_directories(${PROJECT_NAME}
    PUBLIC .
    PUBLIC src/
    PRIVATE ../external/glad/include/
    PRIVATE ../external/glfw/include/
)

target_link_directories(${PROJECT_NAME}
    PUBLIC .
    PUBLIC src/     
    PRIVATE ../external/glad/include/glad/
    PRIVATE ../external/glad/src/
    PRIVATE ../external/glfw/src/
)

target_link_libraries(${PROJECT_NAME} glfw glad)