#pragma once

#include <GLFW/glfw3.h>

#include "util.h"

namespace gedw::gfx {
    struct OpenGLInstance {
        static OpenGLInstance FAILED;

        GLFWwindow* window;

        bool isRunning() const;
        bool failed() const;
        void end();
    };

    OpenGLInstance init(uint width, uint height, const char* title);
}
