#include "gfx/buffer/index.h"

#include <stdio.h>

#include "util/types.h"

using namespace gedw;
using namespace gedw::gfx;

constexpr uint offsets[] = {
    0, 1, 2,
    0, 2, 3
};

IndexBuffer::IndexBuffer(const VertexArray& va) : Buffer(va.getVertexCount() * 6 / 4) {
    printf("Create IB %u\n", this->id);

    Slice<uint> temp(this->count);
    for (uint i = 0; i < this->count; i++) {
        temp[i] = offsets[i % 6] + i / 6 * 4;
    }
    this->write(temp);
}

IndexBuffer::~IndexBuffer() {
    printf("Delete IB %u\n", this->id);
}
