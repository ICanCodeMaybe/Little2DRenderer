cmake_minimum_required(VERSION 3.18.1)
project(glad)

add_library(${PROJECT_NAME} src/glad.c include/glad/glad.h)

target_include_directories(${PROJECT_NAME} PUBLIC include/glad/ PUBLIC include/)
target_link_directories(${PROJECT_NAME} PUBLIC src/)