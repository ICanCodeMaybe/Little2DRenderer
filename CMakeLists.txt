cmake_minimum_required(VERSION 3.18.1)

project(Sandbox)

add_executable(${PROJECT_NAME} Sandbox/src/main.cpp)

add_subdirectory(Little/src)

target_link_libraries(${PROJECT_NAME} Little)