cmake_minimum_required(VERSION 3.18.1)
project(Sandbox)

add_executable(${PROJECT_NAME} src/main.cpp)

add_subdirectory(../Little/ Little/)

target_include_directories(${PROJECT_NAME}
    PUBLIC ../Little/
    PUBLIC ../Little/include/
    PUBLIC ../external/glfw/include/
)

target_link_directories(${PROJECT_NAME}
    PRIVATE ../Little/
    PRIVATE ../Little/src/
    PRIVATE ../external/glfw/src/   
)

target_link_libraries(${PROJECT_NAME} Little)