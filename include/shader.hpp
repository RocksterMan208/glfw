#pragma once

#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <glm/glm.hpp>

std::string loadShaderSource(const char* filepath);
GLuint compileShader(GLenum type, const char* source);
unsigned int createShaderProgram(const char* vertPath, const char* fragPath);