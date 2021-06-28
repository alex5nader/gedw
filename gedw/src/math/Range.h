#pragma once

#define MATH_OPERATOR_SCALAR(OP) \
    Range<T> operator OP (const T& t) const { \
        return Range<T>(this->_min + t, this->_max + t); \
    }

namespace math {
    struct RangeInclusivity {
        bool min = false, max = false;
    };
    struct RangeOverlapInclusivity {
        RangeInclusivity left = {}, right = {};
    };

    template<typename T>
    class Range {
    public:
        Range(const T& min, const T& max) : min(min), max(max) {
            if (min > max) {
                printf("Range min must be less than max\n");
            }
        }
        Range(const Range<T>& other) { this = other; }
        Range(Range<T>&& other) { this = other; }

        bool operator==(const Range<T>& other) const {
            return isZero(this->min - other.min) && isZero(this->max - other.max);
        }
        bool operator!=(const Range<T>& other) const {
            return !(this == other);
        }

        MATH_OPERATOR_SCALAR(+)
        MATH_OPERATOR_SCALAR(-)
        MATH_OPERATOR_SCALAR(*)
        MATH_OPERATOR_SCALAR(/)

        bool contains(const T& t, const RangeInclusivity& inclusivity = {}) const {
            return (inclusivity.min ? t >= this->min : t > this->min)
                && (inclusivity.max ? t <= this->max : t < this->max);
        }
        bool overlaps(const Range<T>& other, const RangeOverlapInclusivity& inclusivity = {}) const {
            return this->contains(other.min, inclusivity.left) || this->contains(other.max, inclusivity.right);
        }
        
        const T& getMin() const {
            return this->min;
        }
        const T& getMax() const {
            return this->max;
        }

        T clamp(const T& t) const {
            return math::clamp(t, this->min, this->max);
        }

        T getSpan() const {
            return this->max - this->min;
        }
        
    private:
        T min, max;
    };
}