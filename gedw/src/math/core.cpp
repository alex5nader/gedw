#include "math/core.h"

namespace gedw::math {
    float EPSILON = 0.0001f;

    void setEpsilon(float epsilon) {
        EPSILON = epsilon;
    }

    void toLower(std::string& string)  {
        for (uint i = 0; i < string.size(); i++) {
            string[i] = tolower(string[i]);
        }
    }

    bool equalsIgnoreCase(const std::string& a, const std::string& b)  {
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