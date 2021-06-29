#include <iostream>

#include <GL/glew.h>

#include "gfx/core.h"
#include "math/core.h"

int main() {
    auto gl = gedw::gfx::init(800, 600, "Title", {
        .clear = { .r = 0.4f, .g = 0.3f, .b = 0.5f },
    });


    uint va;
    glGenVertexArrays(1, &va);
    glBindVertexArray(va);

    uint vbo;
    glGenBuffers(1, &vbo);
    float vertices[] = {
        -.5f, -.5f,
         .5f, -.5f,
         .5f,  .5f,
        -.5f,  .5f,
    };
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, gedw::math::arraySize(vertices), vertices, GL_STATIC_DRAW);


    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (const void*) 0);


    uint ibo;
    glGenBuffers(1, &ibo);
    uint indices[] = {
        0, 1, 2,
        0, 2, 3,
    };
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, gedw::math::arraySize(indices), indices, GL_STATIC_DRAW);


    uint vertex = glCreateShader(GL_VERTEX_SHADER);
    uint fragment = glCreateShader(GL_FRAGMENT_SHADER);

    const char* vertexSource =
        "#version 330 core\n"
        "layout(location = 0) in vec2 i_Position;\n"
        "\n"
        "void main() {\n"
        "    gl_Position = vec4(i_Position, 0, 1);\n"
        "}\n";
    
    const char* fragmentSource =
        "#version 330 core\n"
        "layout(location = 0) out vec4 o_Color;\n"
        "\n"
        "void main() {\n"
        "    o_Color = vec4(0.4, 0.5, 0.3, 1);\n"
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
        glBindVertexArray(va);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        glDrawElements(GL_TRIANGLES, gedw::math::arrayLength(indices), GL_UNSIGNED_INT, nullptr);

        glfwSwapBuffers(gl.window);
        glfwPollEvents();
    }

    gl.end();
    return 0;
}
