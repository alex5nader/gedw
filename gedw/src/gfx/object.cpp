#include "gfx/object.h"

namespace gedw::gfx {
    GlObject::GlObject(uint id) : id(id) {}

    GlObject::~GlObject() {}

    uint GlObject::getId() const {
        return this->id;
    }
}