// definitions

#include "glad/glad.h"

#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


// main program

int main(){
    if (!glfwInit()){
        std::cout << "Initialisation of GLFW failed." << std::endl; // Initialising and testing GLFW.
    }

    // window create
    GLFWwindow* window = glfwCreateWindow(800, 600, "First Window", NULL, NULL); // Creating the environment
    if (!window){
        std::cout << "Creation of the window has failed." << std::endl; // Weird ahh print statement
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window); // tells opengl where to draw the stuff
    glfwSwapInterval(1); // VSync toggle

    // glad initialisation

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){ // If statement to initialise and check glad
        std::cout << "Failed to initialise GLAD" << std::endl;
        glfwTerminate();
        return -1;
    }

    glClearColor(0.0f, 0.5f, 0.5f, 1.0f);

    while (!glfwWindowShouldClose(window)){ // Loops window events until closed.
        
        glClear(GL_COLOR_BUFFER_BIT); // Clears the current screen to render next frame.
        glfwSwapBuffers(window); // Basically re-renders the frame.
        glfwPollEvents(); // Processes shit like inputs and allat
    }
    glfwTerminate(); // Closes the window

    return 0;
}

// Be sure to do "./compile.sh" in terminal to auto-compile the shit.