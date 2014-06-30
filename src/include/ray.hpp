#ifndef BADRAY_RAY_HPP
#define BADRAY_RAY_HPP

#include "math.hpp"

class Ray {
public:
    Point s;
    Vec d;
    real_t energy;
    Ray(const Point &_s, const Vec &_d, real_t _energy = 1.0) : s(_s), d(_d), energy(_energy) {
        if (neq(d.length(), 1.0))
            d.norm();
    }
};

#endif
