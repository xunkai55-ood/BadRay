#ifndef BADRAY_COLOR_HPP
#define BADRAY_COLOR_HPP

#include "math.hpp"

typedef double intensity_t;

struct Intensity {
    Intensity(): r(0), g(0), b(0) {}
    Intensity(intensity_t _r, intensity_t _g, intensity_t _b) : r(_r), g(_g), b(_b) {}
    Intensity(const Intensity &i): r(i.r), g(i.g), b(i.b) {}

    Intensity& operator += (const Intensity &i) {
        r += i.r; g += i.g; b += i.b;
        return *this;
    }
    Intensity operator + (const Intensity &i) {
        return Intensity(r + i.r, g + i.g, b + i.b);
    }
    Intensity& operator *= (real_t t) {
        r *= t; g *= t; b *= t;
        return *this;
    }
    Intensity& operator *= (const Intensity &i) {
        r *= i.r; g *= i.g; b *= i.b;
        return *this;
    }
    Intensity operator * (const Intensity &i) {
        return Intensity(r * i.r, g * i.g, b * i.b);
    }
    Intensity operator * (real_t t) {
        return Intensity(r * t, g * t, b * t);
    }
    Intensity clamp() {
        return Intensity(r > 1 ? 1 : r, g > 1 ? 1 : g, b > 1 ? 1 : b);
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