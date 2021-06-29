#pragma once

#include <cmath>
#include <stdio.h>
#include <string>

#include "util.h"

#define CAST(T, x) (static_cast<T>(x))
#define PUN(T, x) (*(T*)&x)

namespace gedw::math {
    constexpr float PI = 3.14159265359f;
    constexpr float E = 2.71828182846f;

    template<typename T>
    T abs(const T& t) {
        return t < 0 ? -t : t;
    }

    template<typename T>
    const T& min(const T& x, const T& y) {
        return x < y ? x : y;
    }
    template<typename T>
    const T& max(const T& x, const T& y) {
        return x > y ? x : y;
    }
    template<typename T>
    const T& clamp(const T& t, const T& min, const T& max) {
        return t < min ? min :
               t > max ? max :
               t;
    }

    template<typename T>
    T sqrt(const T& t) {
        return std::sqrt(t);
    }

    template<typename T>
    T sin(const T& t) { return std::sin(t); }
    template<typename T>
    T cos(const T& t) { return std::cos(t); }
    template<typename T>
    T tan(const T& t) { return std::tan(t); }
    template<typename T>
    T asin(const T& t) { return std::asin(t); }
    template<typename T>
    T acos(const T& t) { return std::acos(t); }
    template<typename T>
    T atan(const T& x, const T& y) { return std::atan(y, x); }

    template<typename T>
    T dist(const T& x1, const T& y1, const T& x2, const T& y2) {
        const T dx = x1 - x2;
        const T dy = y1 - y2;
        return sqrt(dx * dx + dy * dy);
    }

    extern float EPSILON;
    void setEpison(float f);
    template<typename T>
    bool isZero(const T& t) { return abs(t) <= EPSILON; }

    template<typename T>
    T toRadians(const T& degrees) { return degrees * 180 / PI; }
    template<typename T>
    T toDegrees(const T& radians) { return radians * PI / 180; }

    template<typename T, uint N>
    constexpr uint arrayLength(const T(&arr)[N]) { return N; }
    template<typename T, uint N>
    constexpr uint arraySize(const T(&arr)[N]) { return N * sizeof(T); }

    void toLower(std::string& s);
    bool equalsIgnoreCase(const std::string& a, const std::string& b);
}
