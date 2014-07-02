#ifndef BADRAY_COLOR_HPP
#define BADRAY_COLOR_HPP

#include "math.hpp"

typedef double intensity_t;

struct Intensity {
    Intensity(intensity_t _r = 0, intensity_t _g = 0, intensity_t _b = 0) : r(_r), g(_g), b(_b) {}
    Intensity(const Intensity &i): r(i.r), g(i.g), b(i.b) {}

    Intensity& operator += (const Intensity &i) {
        r += i.r, g += i.g, b += i.b;
        return *this;
    }
    Intensity& operator *= (real_t t) {
        r *= t, g *= t, b *= t;
        return *this;
    }

#if 0
    void maxify() {
        intensity_t a = r;
        if (g > a) a = g;
        if (b > a) a = b;
        if (eq(a, 0)) return;
        a = 1 / a;
        r *= a;
        g *= a;
        b *= a;
    }
#endif
    
    intensity_t r, g, b;
};

#endif