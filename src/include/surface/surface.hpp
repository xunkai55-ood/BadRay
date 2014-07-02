#ifndef BADRAY_SURFACE_SURFACE_HPP
#define BADRAY_SURFACE_SURFACE_HPP

#include "../math.hpp"
#include "../ray.hpp"
#include "../intensity.hpp"

class Surface {
public:
    // Defualt: all diffuse and no transmission
    Surface() {}
    virtual ~Surface() {}

    virtual real_t get_reflection(const Vec &vi, const Vec &vn, Vec &vr, bool inner = false){
        return 0;
    }
    virtual real_t get_refraction(const Vec &vi, const Vec &vn, Vec &vt, bool inner = false){
        return 0;
    }
    inline virtual bool is_emissive() {
        return false;
    }
    virtual real_t get_emission(const Point &p){
        return 0;
    }
    virtual Ray generate_ray(const Point &p, const Vec &vi, const Vec &vn, real_t ipw = 1) {
        return Ray(Point(0, 0, 0), Vec(0, 0, 0));
    }
};

#endif