#pragma once

#include <string>
#include <unordered_map>

#include "gfx/globject.h"

#define UNIFORM_FN(TYPE, ...) void setUniform##TYPE(const std::string& name, __VA_ARGS__)

namespace gedw::gfx {
    class ShaderProgram : public GlObject {
    public:
        ShaderProgram(const ShaderProgram& other) = delete;
        ShaderProgram(ShaderProgram&& other) = delete;

        ShaderProgram(const char* fp);
        ~ShaderProgram();

        void bind() const override;
        void unbind() const override;

        UNIFORM_FN(1f, float f);
        UNIFORM_FN(2f, float f1, float f2);
    
    private:
        std::unordered_map<std::string, int> uniformCache;

        template<typename T, typename... Args>
        void setUniform(T fn, const std::string& name, Args& ... args);
        int getUniformLocation(const std::string& name);
    };
}

#undef UNIFORM_FN
