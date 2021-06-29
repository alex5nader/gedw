#pragma once

#include "gfx/array.h"
#include "gfx/buffer.h"

namespace gedw::gfx {
    class IndexBuffer : public Buffer<GL_ELEMENT_ARRAY_BUFFER> {
    public:
        IndexBuffer(const IndexBuffer& other) = delete;
        IndexBuffer(IndexBuffer&& other) = delete;

        IndexBuffer(const VertexArray& va);
        ~IndexBuffer();
    };
}