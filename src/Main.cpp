#include "pch.h"
#include <iostream>

int main() {
    int x[] = { 1, 2, 3, 4 };
    std::cout << math::arrayLength(x) << std::endl;

    glfwInit();
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    GLFWwindow* window = glfwCreateWindow(800, 600, "Window Name Here", NULL, NULL);
    glfwMakeContextCurrent(window);
    // window creation failed, terminate
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glewExperimental = GL_TRUE;
    glewInit();
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
