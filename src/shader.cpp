#include "../include/shader.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

std::string loadShaderSource(const char* filePath)
{

    std::ifstream file(filePath);
    std::stringstream buffer;

    if (!file.is_open()){

        std::cout << "File failed to open." << std::endl;
        return "";   
    }

    buffer << file.rdbuf();
    return buffer.str();
}

GLuint compileShader(const char* filePath, GLenum shaderType)
{
    std::string src = loadShaderSource(filePath);
    const char* sourceC = src.c_str();

    GLuint shader = glCreateShader(shaderType);
    glShaderSource(shader, 1, &sourceC, nullptr);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        char log[512];
        glGetShaderInfoLog(shader, 512, nullptr, log);
        std::cout << "Shader compiling error" << std::endl;
    }

    return shader;
}

GLuint createShaderProgram(const char* vertexPath, const char* fragmentPath)
{
    GLuint v = compileShader(vertexPath, GL_VERTEX_SHADER);
    GLuint f = compileShader(fragmentPath, GL_FRAGMENT_SHADER);
    
    GLuint program = glCreateProgram();
    glAttachShader(program, v);
    glAttachShader(program, f);
    glLinkProgram(program);

    glDeleteShader(v);
    glDeleteShader(f);

    return program;
}