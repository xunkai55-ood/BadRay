#ifndef BADRAY_MATH_HPP
#define BADRAY_MATH_HPP

#include <cmath>

typedef double real_t;

const real_t EPS = 1e-6;

inline bool eq(const real_t &a, const real_t &b) {
    register real_t d = a - b;
    return -EPS < d && d < EPS;
}
inline bool neq(const real_t &a, const real_t &b) {
    return !eq(a, b);
}
inline bool le(const real_t &a, const real_t &b) {
    return a < b + EPS;
}
inline bool ge(const real_t &a, const real_t &b) {
    return b < a + EPS;
}
inline bool gt(const real_t &a, const real_t &b) {
    return b + EPS < a;
}
inline bool lt(const real_t &a, const real_t &b) {
    return a + EPS < b;
}

struct Vec {
    real_t x, y, z;
    Vec(real_t _x = 0, real_t _y = 0, real_t _z = 0): x(_x), y(_y), z(_z) {}

    inline Vec operator - () {
        return Vec(-x, -y, -z);
    }
    

    inline Vec operator + (const Vec &b) const { 
        return Vec(x + b.x, y + b.y, z + b.z); 
    }
    inline Vec operator - (const Vec &b) const { 
        return Vec(x - b.x, y - b.y, z - b.z);
    }
    inline Vec operator * (real_t b) const {
        return Vec(b * x, b * y, b * z);
    }
    inline Vec operator / (real_t b) const {
        register real_t c = 1.0 / b;
        return Vec(c * x, c * y, c * z);
    }

    inline Vec& operator += (const Vec &b) {
        x += b.x, y += b.y, z += b.z;
        return *this;
    }
    inline Vec& operator -= (const Vec &b) {
        x -= b.x, y -= b.y, z -= b.z;
        return *this;
    }
    inline Vec& operator *= (real_t b) {
        x *= b, y *= b, z *= b;
        return *this;
    }
    inline Vec& operator /= (real_t b) {
        register real_t c = 1.0 / b;
        x *= c, y *= c, z *= c;
        return *this;
    }

    inline bool operator == (const Vec &b) {
        return eq(x, b.x) && eq(y, b.y) && eq(z, b.z);
    }

    inline real_t dot(const Vec &v) const {
        return x * v.x + y * v.y + z * v.z;
    }

    inline Vec cross(const Vec &v) const {
        return Vec(y * v.z - z * v.y,
                   z * v.x - x * v.z,
                   x * v.y - y * v.x);
    }

    inline real_t length2() const {
        return x * x + y * y + z * z;
    }
    inline real_t length() const {
        return sqrt(x * x + y * y + z * z);
    }
    inline Vec& norm() {
        return *this /= length();
    }

};

inline Vec operator * (real_t b, const Vec &v) {
    return v * b;
}

typedef Vec Point;

#endif