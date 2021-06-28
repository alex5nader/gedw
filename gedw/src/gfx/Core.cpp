#include "Core.h"

gfx::OpenGLInstance gfx::OpenGLInstance::FAILED = { .window = nullptr };

bool gfx::OpenGLInstance::isRunning() const {
    return !glfwWindowShouldClose(window);
}

bool gfx::OpenGLInstance::failed() const {
    return this->window == nullptr;
}

static gfx::OpenGLInstance gfx::init(uint width, uint height, const char* title) {
    if (!glfwInit()) {
        printf("Failed to initialize GLFW, aborting...\n");
        glfwTerminate();
        return gfx::OpenGLInstance::FAILED;
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
        return gfx::OpenGLInstance::FAILED;
    }

    glewExperimental = GL_TRUE;
    if (glewInit()) {
        printf("Failed to initialize GLEW, aborting...\n");
        glfwDestroyWindow(window);
        glfwTerminate();
        return gfx::OpenGLInstance::FAILED;
    }

    glClearColor(0.3f, 0.0f, 0.5f, 1.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glfwSetWindowSizeCallback(window, [](GLFWwindow* w, int width, int height) {
        glViewport(0, 0, width, height);
    });
}

static void gfx::end(OpenGLInstance& instance) {
    glfwDestroyWindow(instance.window);
    instance = gfx::OpenGLInstance::FAILED;
    glfwTerminate();
}
