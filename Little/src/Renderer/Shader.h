#pragma once

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "log.h"


#include <unistd.h>

namespace lil{

    class Shader{
    public:
        Shader(const char* pathToVertex, const char* pathToFragment){\
        //READING FILES


//------!!!PATH IS RELATIVE TO LITTLE/../!!!-------------------------
            std::string vertexSource;
            std::string fragmentSource;

            std::ifstream vertexFile;
            std::ifstream fragmentFile;

            vertexFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
            fragmentFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

            std::string vertexRelativePath = "../../";
            vertexRelativePath.append(pathToVertex);
            std::string fragmentRelativePath = "../../";
            fragmentRelativePath.append(pathToFragment);

            
            try
            {
                vertexFile.open(vertexRelativePath);
                fragmentFile.open(fragmentRelativePath);

                std::stringstream vertexStream, fragmentStream;

                vertexStream << vertexFile.rdbuf();
                fragmentStream << fragmentFile.rdbuf();

                vertexFile.close();
                fragmentFile.close();

                vertexSource = vertexStream.str();
                fragmentSource = fragmentStream.str();

            }
            catch(std::ifstream::failure& e)
            {
                LIL_ERROR("SHADER CLASS: FILE WAS NOT READ SUCCESSFULLY");
            }

            const char* vertexShader = vertexSource.c_str();
            const char* fragmentShader = fragmentSource.c_str();
        //COMPILING SHADER PROGRAM
            unsigned int vertex, fragment;
            int success;
            char infoLog[512];


            //vertex shader
            vertex = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertex, 1, &vertexShader, NULL);
            glCompileShader(vertex);

            glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
            if(!success){
                glGetShaderInfoLog(vertex, GL_VERTEX_SHADER, NULL, infoLog);
                LIL_ERROR("VERTEX SHADER COMPILING FAILED: " << infoLog)
            }

            //fragment shader
            fragment = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragment, 1, &fragmentShader, NULL);
            glCompileShader(fragment);

            glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);

            if(!success){
                glGetShaderInfoLog(fragment, GL_FRAGMENT_SHADER, NULL, infoLog);
                LIL_ERROR("FRAGMENT SHADER COMPILING FAILED: " << infoLog)
            }

            //shader program

            m_id = glCreateProgram();
            glAttachShader(m_id, vertex);
            glAttachShader(m_id, fragment);

            glLinkProgram(m_id);

            glGetProgramiv(m_id, GL_LINK_STATUS, &success);
            if(!success)
            {
                glGetProgramInfoLog(m_id, 512, NULL, infoLog);
                LIL_ERROR("SHADER PROGRAM LINKING FAILED: " << infoLog)
            }

            glDeleteShader(vertex);
            glDeleteShader(fragment);
        }

        void Bind(){
            glUseProgram(m_id);
        }

        void setBool(const std::string &name, bool value) const
        {         
            glUniform1i(glGetUniformLocation(m_id, name.c_str()), (int)value); 
        }
        void setInt(const std::string &name, int value) const
        { 
            glUniform1i(glGetUniformLocation(m_id, name.c_str()), value); 
        }
        void setFloat(const std::string &name, float value) const
        { 
            glUniform1f(glGetUniformLocation(m_id, name.c_str()), value); 
        } 

        void set2xFloat(const std::string &name, glm::vec2 value) const
        { 
            glUniform2f(glGetUniformLocation(m_id, name.c_str()), value.x, value.y); 
        } 

        void set3xFloat(const std::string &name, glm::vec3 value) const
        { 
            glUniform3f(glGetUniformLocation(m_id, name.c_str()), value.x, value.y, value.z);
        } 

        void set4xFloat(const std::string &name, glm::vec4 value) const
        { 
            glUniform4f(glGetUniformLocation(m_id, name.c_str()), value.x, value.y, value.z, value.a);
        } 

        void setMat4x(const std::string &name, const glm::mat4 &mat) const
        { 
            glUniformMatrix4fv(glGetUniformLocation(m_id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
        } 
        
    private:
        unsigned int m_id;
    };
}

