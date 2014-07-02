#ifndef BADRAY_SURFACE_REGULAR_SURFACE_HPP
#define BADRAY_SURFACE_REGULAR_SURFACE_HPP

#include "surface.hpp"

class RegularSurface : public Surface {

public:
    RegularSurface(real_t _k_reflect = 0, real_t _k_refract = 0, real_t _ratio = 1);
    virtual ~RegularSurface() {}

    real_t k_reflect, k_refract, refract_ratio, fr_angle;

    virtual real_t get_reflection(const Vec &vi, const Vec &vn, Vec &vr, bool inner = false);
    virtual real_t get_refraction(const Vec &vi, const Vec &vn, Vec &vt, bool inner = false);

    virtual Ray generate_ray(const Point &p, const Vec &vi, const Vec &vn, real_t ipw = 1.0);

    bool is_full_reflection(const Vec &vi, const Vec &vn, bool inner);
};

#endif