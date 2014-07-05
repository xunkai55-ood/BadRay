#include "surface/surface.hpp"
#include "random.hpp"
#include <cassert>
#include <cstdio>

real_t Surface::d_reflection(const Vec &vi, const Vec &vn, Vec &vr, bool inner) {
    // fprintf(stderr, "diffuse reflection\n");
    double r1 = 2 * M_PI * rand_real(), r2 = rand_real(), r2s = sqrt(r2);
    Vec w = vn.dot(vi) < 0 ? vn : -1 * vn;
    Vec u = real_abs(w.x) > 0.1 ? Vec(0, 1, 0) : Vec(1, 0, 0);
    u.norm();
    Vec v = w.cross(u);
    vr = u * cos(r1) * r2s + v * sin(r1) * r2s + w * sqrt(1 - r2);
    vr.norm();

    // fprintf(stderr, "I: %lf %lf %lf\n", vi.x, vi.y, vi.z);
    // fprintf(stderr, "N: %lf %lf %lf\n", vn.x, vn.y, vn.z);
    // fprintf(stderr, "R: %lf %lf %lf\n", vr.x, vr.y, vr.z);
    return 1;
}

real_t Surface::d_transmission(const Vec &vi, const Vec &vn, Vec &vr, bool inner) {
    fprintf(stderr, "diffuse transmission\n");
    vr.x = vi.x;
    vr.y = vi.y;
    vr.z = vi.z;
    vr.norm();
    if (vr.dot(vn) > 0)
        vr *= -1;
    return real_abs(vr.dot(vi));
}

real_t Surface::i_reflection(const Vec &vi, const Vec &vn, Vec &vr, bool inner){
    vr = vi + vn + vn;
    vr.norm();
    return real_abs(vr.dot(vi));
}

real_t Surface::i_transmission(const Vec &vi, const Vec &vn, Vec &vr, bool inner){
    register real_t ratio = inner ? (ra) : (1 / ra);
    Vec vp = (vi + vn * (-vn.dot(vi))) * ratio;
    assert(vp.length2() <= 1);
    // coder should ensure that full reflection has been detected
    vr = vn * (-sqrt(1 - vp.length2())) + vp;
    return real_abs(vr.dot(vi));
}

bool Surface::is_full_reflection(const Vec &vi, const Vec &vn, bool inner) {
    register real_t ratio = inner ? (ra) : (1 / ra);
    Vec vp = (vi + vn * (-vn.dot(vi))) * ratio;
    if (gt(vp.length2(), 1))
        return true;
    else
        return false;
}

Ray Surface::generate_ray(const Point &p, const Vec &vi, const Vec &vn, bool &inner, real_t ipw) {
    real_t seed = rand_real() * k_prefix_sum[3], pw = 1;
    Vec dir;
    if (seed <= k_prefix_sum[0]) {
        pw = 0;
        dir = vi;
    } else if (seed <= k_prefix_sum[1]) { // ideal reflection
        pw = i_reflection(vi, vn, dir, inner);
    } else if (seed <= k_prefix_sum[2]) { // ideal refraction
        if (is_full_reflection(vi, vn, inner)){
            pw = i_reflection(vi, vn, dir, inner);
        }
        else {
            pw = i_transmission(vi, vn, dir, inner);
            inner = inner ? false : true;
        }
    } else if (seed <= k_prefix_sum[3]) {
        pw = d_reflection(vi, vn, dir, inner);
    } else if (seed <= k_prefix_sum[4]) {
        pw = d_transmission(vi, vn, dir, inner);
        inner = inner ? false : true;
    }
    // fprintf(stderr, "%lf * %lf = %lf\n", pw, ipw, ipw * pw);
    return Ray(EPS * dir + p, dir, pw * ipw);
}