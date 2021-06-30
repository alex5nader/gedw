#pragma once

#include "gfx/core.h"
#include "gfx/program.h"
#include "gfx/renderobject.h"

namespace gedw::gfx {
    class Renderer {
    public:
        Renderer(const char* fp);
        Renderer(const Renderer& other) = delete;
        Renderer(Renderer&& other) = delete;

        void clear() const;
        void draw(const RenderObject& obj) const;
        void render(const GlInstance& gl) const;

        ShaderProgram& getProgram() const;

    private:
        mutable ShaderProgram program;
    };
}