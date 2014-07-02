#ifndef BADRAY_RAY_HPP
#define BADRAY_RAY_HPP

#include "math.hpp"

class Ray {
public:
    Point s;
    Vec d;
    real_t power;
    Ray(const Point &_s, const Vec &_d, real_t _power = 1.0) : s(_s), d(_d), power(_power) {
        if (neq(d.length(), 1.0))
            d.norm();
    }
    Ray(const Ray &r): s(r.s), d(r.d), power(r.power) {}
};

#endif
