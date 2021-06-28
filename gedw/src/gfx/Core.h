#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include <stdio.h>

typedef uint32_t uint;

namespace gfx {
    struct OpenGLInstance {
        static OpenGLInstance FAILED;

        GLFWwindow* window;

        bool isRunning() const;
        bool failed() const;
    };

    static OpenGLInstance init(uint width, uint height, const char* title);
    static void end(OpenGLInstance& instance);
}
