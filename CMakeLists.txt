cmake_minimum_required(VERSION 3.10)

project(DEA LANGUAGES C CXX)

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

# ---- Build executable ----
add_executable(fuckass ${SOURCES})

# ---- Link libraries (Arch Linux) ----
target_link_libraries(fuckass
    glfw      # the GLFW system library
    GL        # OpenGL
    dl        # needed by glad
)

# ---- Copy shaders for runtime ----
file(COPY shaders DESTINATION ${CMAKE_BINARY_DIR})