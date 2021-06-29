#pragma once

#include <initializer_list>

#include "util/types.h"

namespace gedw {
    template<typename T>
    class Slice {
    public:
        Slice(const std::initializer_list<T>& init) : data(copy(init)), len(init.size()) {}
        Slice(uint const len) : data(new T[len]), len(len) {}
        Slice(T* const item, uint const len) : data(data), len(len) {}

        T* const data;
        uint const len;

        T& operator[](int index) {
            return data[index];
        }

        ~Slice() {
            delete[] data;
        }
    
    private:
        static T* copy(const std::initializer_list<T>& init) {
            T* buf = new T[init.size()];
            int i = 0;
            for (T item : init) {
                buf[i] = item;
                i += 1;
            }
            return buf;
        }
    };
}