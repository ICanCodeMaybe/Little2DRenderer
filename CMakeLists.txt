cmake_minimum_required(VERSION 3.18.1)

project(Sandbox)

add_executable(${PROJECT_NAME} Sandbox/src/main.cpp)

add_subdirectory(Little)
add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME} 
    PUBLIC Little/include
    PUBLIC external/glfw/include/
)

target_link_directories(${PROJECT_NAME} 
    PRIVATE Little/src/
    PRIVATE external/glfw/src/    
)
target_link_libraries(${PROJECT_NAME} Little glfw)