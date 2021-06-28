#pragma once

#define GLUE(X, Y) X ## Y

#define ASSIGN_OPERATOR_SCALAR(OP) \
    Vec2<T>& operator OP(const T& t) { \
        this->x OP t; \
        this->y OP t; \
        return *this; \
    }

#define ASSIGN_OPERATOR_VECTOR(OP) \
    Vec2<T>& operator OP(const Vec2<T>& other) { \
        this->x OP other.x; \
        this->y OP other.y; \
        return *this; \
    }

#define MATH_OPERATOR_SCALAR(OP) \
    Vec2<T> operator OP(const T& t) { \
        return Vec2(this->x OP t, this->y OP t); \
    }

#define MATH_OPERATOR_VECTOR(OP) \
    Vec2<T> operator OP(const Vec2<T>& other) { \
        return Vec2(this->x OP other.x, this->y OP other.y); \
    }

namespace math {
    template<typename T>
    class Vec2 {
    public:
        T x, y;

        Vec2(const T& x, const T& y) : x(x), y(y) {}
        Vec2(const Vec2<T>& other) { this = other; }
        Vec2(Vec2<T>&& other) { this = other; }

        bool operator==(const Vec2<T>& other) const {
            return isZero(this.x - other.x) && isZero(this->y - other.y);
        }
        bool operator!=(const Vec2<T>& other) const {
            return !(this == other);
        }

        T magnitude() const {
            return math::dist(0.0f, 0.0f, this->x, this->y);
        }
        Vec2<T> normalized() const {
            return this / this->magnitude();
        }
        Vec2<T>& normalize() {
            this = this.normalized();
        }

        T dot(const Vec2<T>& other) const {
            return this->x * other.x + this->y * other.y;
        }
        T angle() const {
            return math::atan(x, y);
        }
        T angleBetween(const Vec2<T>& other) const {
            return math::acos(this->dot(other) / (this->magnitude() * other.magnitude()));
        }

        ASSIGN_OPERATOR_SCALAR(=)
        ASSIGN_OPERATOR_SCALAR(+=)
        ASSIGN_OPERATOR_SCALAR(-=)
        ASSIGN_OPERATOR_SCALAR(*=)
        ASSIGN_OPERATOR_SCALAR(/=)

        ASSIGN_OPERATOR_VECTOR(=)
        ASSIGN_OPERATOR_VECTOR(+=)
        ASSIGN_OPERATOR_VECTOR(-=)
        ASSIGN_OPERATOR_VECTOR(*=)
        ASSIGN_OPERATOR_VECTOR(/=)

        MATH_OPERATOR_SCALAR(+)
        MATH_OPERATOR_SCALAR(-)
        MATH_OPERATOR_SCALAR(*)
        MATH_OPERATOR_SCALAR(/)

        MATH_OPERATOR_VECTOR(+)
        MATH_OPERATOR_VECTOR(-)
        MATH_OPERATOR_VECTOR(*)
        MATH_OPERATOR_VECTOR(/)
    };
}

#undef ASSIGN_OPERATOR_SCALAR
#undef ASSIGN_OPERATOR_VECTOR
#undef MATH_OPERATOR_SCALAR
#undef MATH_OPERATOR_VECTOR
