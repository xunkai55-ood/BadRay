#ifndef BADRAY_SURFACE_SURFACE_HPP
#define BADRAY_SURFACE_SURFACE_HPP

#include "../math.hpp"
#include "../ray.hpp"
#include "../intensity.hpp"

class Surface {
public:
    
    // Surface(double _ar) : absorb_ratio(ar) {}
    Surface(double _kab, double _kir, double _kit, double _kdr, double _kdt, double _refract_ratio = 0.0) :
        kab(_kab), kir(_kir), kit(_kit), kdr(_kdr), kdt(_kdt), ra(_refract_ratio) {
            k_prefix_sum[0] = kab;
            k_prefix_sum[1] = k_prefix_sum[0] + kir;
            k_prefix_sum[2] = k_prefix_sum[1] + kit;
            k_prefix_sum[3] = k_prefix_sum[2] + kdr;
            k_prefix_sum[4] = k_prefix_sum[3] + kdt;
        }
    virtual ~Surface() {}

    bool is_full_reflection(const Vec &vi, const Vec &vn, bool inner);
    virtual real_t i_reflection(const Vec &vi, const Vec &vn, Vec &vr, bool inner = false);
    virtual real_t i_transmission(const Vec &vi, const Vec &vn, Vec &vt, bool inner = false);
    virtual real_t d_reflection(const Vec &vi, const Vec &vn, Vec &vr, bool inner = false);
    virtual real_t d_transmission(const Vec &vi, const Vec &vn, Vec &vt, bool inner = false);
    virtual bool is_emissive() {
        return false;
    }
    virtual Intensity get_emission(const Point &p){
        return Intensity(0, 0, 0);
    }
    virtual Ray generate_ray(const Point &p, const Vec &vi, const Vec &vn, bool &inner, real_t ipw = 1);
    // bool is_absorbed() {
    //     real_t seed = rand_real();
    //     if (seed < absorb_ratio) 
    //         return true;
    //     else
    //         return false;
    // }
    // real_t absorb_ratio;
    real_t kab, kir, kit, kdr, kdt, ra;
    real_t k_prefix_sum[5];
};

namespace surface {
    
    inline Surface* SolidRough(double kab = 0.01) {
        return new Surface(kab, 0, 0, 1, 0);
    }
    inline Surface* Glass() {
        return new Surface(0.01, 0, 1, 0.05, 0.05, 2);
    }
    inline Surface* Mirror() {
        return new Surface(0.01, 1, 0, 0.05, 0);
    }
}

#endif