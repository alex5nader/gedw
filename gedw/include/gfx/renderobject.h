#pragma once

#include "gfx/buffer/index.h"
#include "gfx/array.h"

namespace gedw::gfx {
    class RenderObject {
    public:
        RenderObject(const RenderObject& other) = delete;
        RenderObject(RenderObject&& other) = delete;

        RenderObject(const Slice<float>& vertices, const std::initializer_list<uint>& groups);

        void bind() const;
        
        uint getIndexCount() const;
    private:
        VertexArray vertexArray;
        IndexBuffer indexBuffer;
    };
}