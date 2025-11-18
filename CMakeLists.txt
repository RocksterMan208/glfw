cmake_minimum_required(VERSION 3.16)
project(NEA LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(GLAD_DIR "${CMAKE_SOURCE_DIR}/external/glad")

file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp")

# GLAD
add_library(glad STATIC "${GLAD_DIR}/src/glad.c")
target_include_directories(glad PUBLIC "${GLAD_DIR}/include")

# my code
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})

# Link packages
find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
find_package(glm REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${GLFW_INCLUDE_DIRS} ${GLM_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${GLFW_LIBRARIES})
target_link_libraries(${PROJECT_NAME} PRIVATE glad ${OPENGL_LIBRARIES} glfw)

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /permissive-)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_custom_target(run
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)