#include "gfx/renderobject.h"

using namespace gedw;
using namespace gedw::gfx;

RenderObject::RenderObject(const Slice<float>& vertices, const std::initializer_list<uint>& groups) :
    vertexArray(vertices, groups),
    indexBuffer(this->vertexArray)
{}

void RenderObject::bind() const {
    this->vertexArray.bind();
    this->indexBuffer.bind();
}

uint RenderObject::getIndexCount() const {
    return this->indexBuffer.getCount();
}
