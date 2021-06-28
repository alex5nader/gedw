#include <stdio.h>

#include <GL/glew.h>

#include "gfx/core.h"

namespace gedw::gfx {

    OpenGLInstance OpenGLInstance::FAILED = { .window = nullptr };

    bool OpenGLInstance::isRunning() const {
        return !glfwWindowShouldClose(window);
    }

    bool OpenGLInstance::failed() const {
        return this->window == nullptr;
    }

    void OpenGLInstance::end() {
        glfwDestroyWindow(this->window);
        *this = OpenGLInstance::FAILED;
        glfwTerminate();
    }

    OpenGLInstance init(uint width, uint height, const char* title) {
        if (!glfwInit()) {
            printf("Failed to initialize GLFW, aborting...\n");
            glfwTerminate();
            return OpenGLInstance::FAILED;
        }

        glfwWindowHint(GLFW_RESIZABLE, false);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_CORE_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        glfwMakeContextCurrent(window);

        if (!window) {
            printf("Window creation failed, aborting...\n");
            glfwTerminate();
            return OpenGLInstance::FAILED;
        }

        glewExperimental = GL_TRUE;
        if (glewInit()) {
            printf("Failed to initialize GLEW, aborting...\n");
            glfwDestroyWindow(window);
            glfwTerminate();
            return OpenGLInstance::FAILED;
        }

        glClearColor(0.3f, 0.0f, 0.5f, 1.0f);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glfwSetWindowSizeCallback(window, [](GLFWwindow* w, int width, int height) {
            glViewport(0, 0, width, height);
        });

        return { .window = window };
    }

}
