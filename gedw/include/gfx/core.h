#pragma once

#include <GLFW/glfw3.h>

#include "util/types.h"

namespace gedw::gfx {
    struct Color {
        float r = 0.0f, g = 0.0f, b = 0.0f;
    };
    
    struct WindowOptions {
        Color clear = {};
        bool resizable = false;
        bool debug = true;
    };

    class GlInstance {
    public:
        static GlInstance FAILED;

        static GlInstance init(uint width, uint height, const char* title, const WindowOptions& options = {});
        ~GlInstance();

        GLFWwindow* const window;

        bool isRunning() const;
        bool failed() const;
    
    private:
        GlInstance(GLFWwindow* window);
    };
}
