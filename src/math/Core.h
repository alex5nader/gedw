#pragma once

#include <cmath>
#include <inttypes.h>
#include <stdio.h>
#include <string>

typedef uint8_t uchar;
typedef uint16_t ushort;
typedef uint32_t uint;
typedef uint64_t ulong;

#define CAST(T, x) (static_cast<T>(x))
#define PUN(T, x) (*(T*)&x)

namespace math {
    constexpr static float PI = 3.14159265359f;
    constexpr static float E = 2.71828182846f;


    template<typename T>
    static T abs(const T& t) {
        return t < 0 ? -t : t;
    }


    template<typename T>
    static const T& min(const T& x, const T& y) {
        return x < y ? x : y;
    }

    template<typename T>
    static const T& max(const T& x, const T& y) {
        return x > y ? x : y;
    }

    template<typename T>
    static const T& clamp(const T& t, const T& min, const T& max) {
        return t < min ? min :
               t > max ? max :
               t;
    }


    template<typename T>
    static T sqrt(const T& t) {
        return std::sqrt(t);
    }


    template<typename T>
    static T sin(const T& t) {
        return std::sin(t);
    }

    template<typename T>
    static T cos(const T& t) {
        return std::cos(t);
    }

    template<typename T>
    static T tan(const T& t) {
        return std::tan(t);
    }

    template<typename T>
    static T asin(const T& t) {
        return std::asin(t);
    }

    template<typename T>
    static T acos(const T& t) {
        return std::acos(t);
    }

    template<typename T>
    static T atan(const T& x, const T& y) {
        return std::atan(y, x);
    }

    template<typename T>
    static T dist(const T& x1, const T& y1, const T& x2, const T& y2) {
        const T dx = x1 - x2;
        const T dy = y1 - y2;
        return sqrt(dx * dx + dy * dy);
    }

    static float EPSILON = 0.0001f;

    static void setEpison(float f) {
        EPSILON = f;
    }

    template<typename T>
    static bool isZero(const T& t) {
        return abs(t) <= EPSILON;
    }


    template<typename T>
    static T toRadians(const T& degrees) {
        return degrees * 180 / PI;
    }

    template<typename T>
    static T toDegrees(const T& radians) {
        return radians * PI / 180;
    }


    template<typename T, uint N>
    constexpr static uint arrayLength(const T(&arr)[N]) {
        return N;
    }

    template<typename T, uint N>
    constexpr static uint arraySize(const T(&arr)[N]) {
        return N * sizeof(T);
    }


    static void toLower(std::string& s) {
        for (uint i = 0; i < s.size(); i++) {
            s[i] = tolower(s[i]);
        }
    }

    static bool equalsIgnoreCase(const std::string& a, const std::string& b) {
        if (a.size() != b.size()) {
            return false;
        }

        for (uint i = 0; i < a.size(); i++) {
            if (tolower(a[i]) != tolower(b[i])) {
                return false;
            }
        }

        return true;
    }
}
