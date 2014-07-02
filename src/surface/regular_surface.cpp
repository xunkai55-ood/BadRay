#include "surface/regular_surface.hpp"
#include "random.hpp"

RegularSurface::RegularSurface(real_t _k_reflect, real_t _k_refract, real_t _ratio) :
    k_refract(_k_refract), k_reflect(_k_reflect), refract_ratio(_ratio)
{
}

real_t RegularSurface::get_reflection(const Vec &vi, const Vec &vn, Vec &vr, bool inner){
    vr = vi + vn + vn;
    vr.norm();
    return k_reflect;
}

real_t RegularSurface::get_refraction(const Vec &vi, const Vec &vn, Vec &vr, bool inner){
    register real_t ratio = inner ? (refract_ratio) : (1 / refract_ratio);
    Vec vp = (vi + vn * (-vn.dot(vi))) * ratio;
    // coder should ensure that full reflection has been detected
    vr = vn * (-sqrt(1 - vp.length2())) + vp;
    return k_refract;
}

bool RegularSurface::is_full_reflection(const Vec &vi, const Vec &vn, bool inner) {
    register real_t ratio = inner ? (refract_ratio) : (1 / refract_ratio);
    Vec vp = (vi + vn * (-vn.dot(vi))) * ratio;
    if (gt(vp.length2(), 1))
        return true;
    else
        return false;
}

Ray RegularSurface::generate_ray(const Point &p, const Vec &vi, const Vec &vn, real_t ipw) {
    real_t r = rand_real(), pw;
    Vec vr(0, 0, 0);
    if (r * (k_refract + k_reflect) > k_reflect) {
        pw = get_refraction(vi, vn, vr);
    } else {
        pw = get_reflection(vi, vn, vr);
    }
    return Ray(p, vr.norm(), ipw * pw);
}