#pragma once

#include "gfx/buffer.h"

namespace gedw::gfx {
    class VertexBuffer : public Buffer<GL_ARRAY_BUFFER> {
    public:
        VertexBuffer(const VertexBuffer& other) = delete;
        VertexBuffer(VertexBuffer&& other) = delete;

        VertexBuffer(const Slice<float>& data);
        ~VertexBuffer();
    };
}
