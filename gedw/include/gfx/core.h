#pragma once

#include <GLFW/glfw3.h>

#include "util.h"

namespace gedw::gfx {
    struct Color {
        float r = 0.0f, g = 0.0f, b = 0.0f;
    };
    
    struct WindowOptions {
        Color clear = {};
        bool resizable = false;
    };

    struct OpenGLInstance {
        static OpenGLInstance FAILED;

        GLFWwindow* window;

        bool isRunning() const;
        bool failed() const;
        void end();
    };

    OpenGLInstance init(uint width, uint height, const char* title, const WindowOptions& options = {});
}
