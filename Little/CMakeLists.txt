cmake_minimum_required(VERSION 3.18.1)
project(Little)

set(LITTLE_HEADERS 
    src/log.h src/Application.h 
    src/Events/KeyboardEvent.h src/Events/MouseEvent.h 
    src/Events/Event.h)

set(LITTLE_CPP
    src/Application.cpp)
add_library(${PROJECT_NAME} ${LITTLE_CPP} ${LITTLE_HEADERS})

add_subdirectory(../external/glfw glfw/)


target_include_directories(${PROJECT_NAME}
    PUBLIC .
    PUBLIC src/
    PRIVATE ../external/glad/include/glad/
    PRIVATE ../external/glfw/include/
)

target_link_directories(${PROJECT_NAME}
    PUBLIC .
    PUBLIC src/     
    PRIVATE ../external/glad/include/glad/
    PRIVATE ../external/glfw/src/
)

target_link_libraries(${PROJECT_NAME} glfw)