#include "gfx/program.h"

#include <fstream>
#include <string>
#include <sstream>

#include <GL/glew.h>

using namespace gedw::gfx;


struct ShaderSources {
    std::string vertex, fragment;
};
ShaderSources INVALID_SOURCE = { .vertex = "", .fragment = "" };

ShaderSources parse(const char* fp) {
    std::ifstream in(fp);
    if (!in.is_open()) {
        printf("Error opening shader file '%s', aborting...\n", fp);
        return INVALID_SOURCE;
    }

    std::string line;
    std::stringstream streams[2];
    // 0: vertex, 1: fragment
    uint currentType = 0;

    while (getline(in, line)) {
        if (line.find("#type") != std::string::npos) {
            if (line.find("vertex") != std::string::npos) {
                currentType = 0;
            } else if (line.find("fragment") != std::string::npos) {
                currentType = 1;
            } else {
                printf("Invalid shader type on line '%s', aborting...\n", line.c_str());
                return INVALID_SOURCE;
            }
        } else {
            streams[currentType] << line << std::endl;
        }
    }

    in.close();

    return { .vertex = streams[0].str(), .fragment = streams[1].str() };
}

uint compile(const std::string& src, GLenum type) {
    uint id = glCreateShader(type);
    const char* source = src.c_str();
    glShaderSource(id, 1, &source, nullptr);
    glCompileShader(id);

    int success;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (!success) {
        printf("%s shader compilation failed, aborting...\n", (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment"));
        printf("Source:\n%s\n", src.c_str());

        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* buffer = new char[length];
        glGetShaderInfoLog(id, length, &length, buffer);
        printf("%s\n", buffer);
        delete[] buffer;

        glDeleteShader(id);
        return 0;
    }

    return id;
}


ShaderProgram::ShaderProgram(const char* fp) : GlObject(glCreateProgram()) {
    auto sources = parse(fp);
    auto vertex = compile(sources.vertex, GL_VERTEX_SHADER);
    auto fragment = compile(sources.fragment, GL_FRAGMENT_SHADER);

    glAttachShader(this->id, vertex);
    glAttachShader(this->id, fragment);
    glLinkProgram(this->id);
    glValidateProgram(this->id);

    glDeleteShader(vertex);
    glDeleteShader(fragment);

    printf("Create shader program %u\n", this->id);
}

ShaderProgram::~ShaderProgram() {
    printf("Delete shader program %u\n", this->id);
    glDeleteProgram(this->id);
}

void ShaderProgram::bind() const {
    glUseProgram(this->id);
}

void ShaderProgram::unbind() const {
    glUseProgram(0);
}

int ShaderProgram::getUniformLocation(const std::string& name) {
    auto cached = this->uniformCache.find(name);
    if (cached != this->uniformCache.end()) {
        return cached->second;
    }

    int location = glGetUniformLocation(this->id, name.c_str());
    if (location == -1) {
        printf("Uniform '%s' not found\n", name.c_str());
        return -1;
    }

    this->uniformCache[name] = location;
    return location;
}

template<typename F, typename... Args>
void ShaderProgram::setUniform(F fn, const std::string& name, Args& ... args) {
    this->bind();
    fn(this->getUniformLocation(name), args...);
}

#define UNIFORM_FN(TYPE, ...) void ShaderProgram::setUniform##TYPE(const std::string& name, __VA_ARGS__)
#define IMPL(TYPE, ...) { this->setUniform(glUniform##TYPE, name, __VA_ARGS__); }

UNIFORM_FN(1f, float f) IMPL(1f, f)
UNIFORM_FN(2f, float f1, float f2) IMPL(2f, f1, f2)
