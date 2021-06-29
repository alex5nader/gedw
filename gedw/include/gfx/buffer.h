#pragma once

#include "GL/glew.h"
#include "gfx/object.h"
#include "util/slice.h"

namespace gedw::gfx {
    template<GLenum TARGET>
    class Buffer : public GlObject {
    public:
        Buffer(const Buffer& other) = delete;
        Buffer(Buffer&& other) = delete;

        void bind() const override {
            glBindBuffer(TARGET, this->id);
        }
        void unbind() const override {
            glBindBuffer(TARGET, 0);
        }

        uint getCount() const {
            return this->count;
        }
    
    protected:
        uint count;

        Buffer(uint count) : GlObject(genBuffers(1)), count(count) {}

        virtual ~Buffer() {
            glDeleteBuffers(1, &this->id);
        }

        template<typename T>
        void write(const Slice<T>& items) {
            this->bind();
            glBufferData(TARGET, items.len * sizeof(T), items.data, GL_STATIC_DRAW);
        }
    
    private:
        static uint genBuffers(uint n) {
            uint id;
            glGenBuffers(n, &id);
            return id;
        }
    };
}