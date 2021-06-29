#include <iostream>
#include <filesystem>

#include <GL/glew.h>

#include "gfx/buffer/index.h"
#include "gfx/buffer/vertex.h"
#include "gfx/core.h"
#include "math/core.h"

using namespace gedw;
using namespace gedw::gfx;

int main() {
    auto gl = GlInstance::init(800, 600, "Title", {
        .clear = { .r = 0.4f, .g = 0.3f, .b = 0.5f },
    });
    
    Slice<float> vertices({
        -.5f, -.5f,  1.0f, 0.0f, 0.0f,
         .5f, -.5f,  0.0f, 1.0f, 0.0f,
         .5f,  .5f,  0.0f, 0.0f, 1.0f,
        -.5f,  .5f,  1.0f, 1.0f, 1.0f,
    });
    VertexArray va(vertices, { 2, 3 });
    IndexBuffer ibo(va);


    uint vertex = glCreateShader(GL_VERTEX_SHADER);
    uint fragment = glCreateShader(GL_FRAGMENT_SHADER);

    const char* vertexSource =
        "#version 330 core\n"
        "layout(location = 0) in vec2 i_Position;\n"
        "layout(location = 1) in vec3 i_Color;\n"
        "\n"
        "out vec3 v_Color;\n"
        "\n"
        "void main() {\n"
        "    v_Color = i_Color;\n"
        "    gl_Position = vec4(i_Position, 0, 1);\n"
        "}\n";
    
    const char* fragmentSource =
        "#version 330 core\n"
        "in vec3 v_Color;\n"
        "\n"
        "out vec4 o_Color;\n"
        "\n"
        "void main() {\n"
        "    o_Color = vec4(v_Color, 1);\n"
        "}\n";
    
    glShaderSource(vertex, 1, &vertexSource, nullptr);
    glShaderSource(fragment, 1, &fragmentSource, nullptr);
    glCompileShader(vertex);
    glCompileShader(fragment);

    uint program = glCreateProgram();
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vertex);
    glDeleteShader(fragment);


    while (gl.isRunning()) {
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(program);
        va.bind();
        ibo.bind();
        glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_INT, nullptr);

        glfwSwapBuffers(gl.window);
        glfwPollEvents();
    }

    return 0;
}
