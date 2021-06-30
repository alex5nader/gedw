#include "gfx/renderer.h"

#include <GL/glew.h>

using namespace gedw::gfx;

Renderer::Renderer(const char* fp) : program(fp) {}

void Renderer::clear() const {
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::draw(const RenderObject& obj) const {
    obj.bind();
    this->program.bind();
    glDrawElements(GL_TRIANGLES, obj.getIndexCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::render(const GlInstance& gl) const {
    glfwSwapBuffers(gl.window);
    glfwPollEvents();
}

ShaderProgram& Renderer::getProgram() const {
    return this->program;
}
