#pragma once

#include "util/types.h"

namespace gedw::gfx {
    class GlObject {
    public:
        GlObject(const GlObject& other) = delete;
        GlObject(GlObject&& other) = delete;

        virtual ~GlObject() = 0;

        virtual void bind() const = 0;
        virtual void unbind() const = 0;

        uint getId() const;

    protected:
        GlObject(uint id);

        uint id;
    };
}