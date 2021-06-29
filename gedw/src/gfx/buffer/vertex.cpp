#include "gfx/buffer/vertex.h"

#include <stdio.h>

using namespace gedw::gfx;

VertexBuffer::VertexBuffer(const Slice<float>& data) : Buffer(data.len) {
    printf("Create VB %u\n", this->id);
    
    this->write(data);
}

VertexBuffer::~VertexBuffer() {
    printf("Delete VB %u\n", this->id);
}
