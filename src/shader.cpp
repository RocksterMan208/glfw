#include "../include/shader.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

std::string loadShaderSource(const char* filePath){

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
    
}