#pragma once

#include <initializer_list>

#include "gfx/object.h"
#include "gfx/buffer/vertex.h"
#include "util/slice.h"

namespace gedw::gfx {
    class VertexArray : public GlObject {
    public:
        VertexArray(const VertexArray& other) = delete;
        VertexArray(VertexArray&& other) = delete;

        VertexArray(const Slice<float>& vertices, const std::initializer_list<uint>& groups);
        ~VertexArray();

        void bind() const override;
        void unbind() const override;

        uint getVertexCount() const;

    private:
        VertexBuffer buffer;
        uint vertexSize;
    };
}