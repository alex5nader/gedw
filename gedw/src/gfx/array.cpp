#include "gfx/array.h"

#include <functional>
#include <numeric>
#include <stdio.h>

#include <GL/glew.h>

#include "util/types.h"

using namespace gedw;
using namespace gedw::gfx;

uint genVertexArrays(uint count) {
    uint id;
    glGenVertexArrays(count, &id);
    return id;
}


VertexArray::VertexArray(const Slice<float>& vertices, const std::initializer_list<uint>& attributeSizes) :
    GlObject(genVertexArrays(1)),
    buffer(vertices),
    vertexSize(std::accumulate(attributeSizes.begin(), attributeSizes.end(), 0))
{
    printf("Create VA %u\n", this->id);

    this->bind();
    this->buffer.bind();

    const uint stride = vertexSize * sizeof(float);
    uint offset = 0, i = 0;
    for (uint attributeSize : attributeSizes) {
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, attributeSize, GL_FLOAT, GL_FALSE, stride, (const void*)(offset * sizeof(float)));
        offset += attributeSize;
        i += 1;
    }
}

void VertexArray::bind() const {
    glBindVertexArray(this->id);
}
void VertexArray::unbind() const {
    glBindVertexArray(0);
}

uint VertexArray::getVertexCount() const {
    return this->buffer.getCount() / this->vertexSize;
}

VertexArray::~VertexArray() {
    printf("Delete VA %u\n", this->id);

    glDeleteVertexArrays(1, &this->id);
}
