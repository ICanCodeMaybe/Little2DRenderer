add_library(Little src/Application.cpp src/log.h src/Application.h src/Events/KeyboardEvent.h src/Events/MouseEvent.h src/Events/Event.h)

#add_subdirectory(${PROJECT_NAME} ../external/glfw)

#MUSÍM PŘEDĚLAT CMAKE, ABY LITTLE BYL PROKEKT

target_include_directories(${PROJECT_NAME} 
    PRIVATE .
    PRIVATE ../external/glad/include/glad/
)

target_link_directories(${PROJECT_NAME}     
    PRIVATE ../external/glad/include/glad/
)

target_link_libraries(${PROJECT_NAME} glfw)