cmake_minimum_required(VERSION 3.16)
project(OpenGLProject LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- Include directories ----
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/external/glad/include
)

# ---- Source files ----
set(SOURCES
    src/main.cpp
    src/shader.cpp
    external/glad/src/glad.c
)

# ---- Create executable ----
add_executable(opengl_app ${SOURCES})

# ---- Link system libraries (Arch Linux) ----
find_package(glfw3 REQUIRED)
target_link_libraries(opengl_app
    glfw
    dl       # glad needs this on Linux
    GL       # OpenGL on Linux
)

# ---- Copy shaders to build directory for runtime ----
file(COPY shaders DESTINATION ${CMAKE_BINARY_DIR})