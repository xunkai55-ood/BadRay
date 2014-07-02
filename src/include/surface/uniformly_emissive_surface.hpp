#ifndef BADRAY_SURFACE_UNIFORMLY_EMISSIVE_SURFACE
#define BADRAY_SURFACE_UNIFORMLY_EMISSIVE_SURFACE

#include "emissive_surface.hpp"

class UniformlyEmissiveSurface : public EmissiveSurface {
public:
    UniformlyEmissiveSurface(real_t _luminance) : EmissiveSurface() {
        if (_luminance > 1)
            luminance = 1.0;
        else if (_luminance < 0)
            luminance = 0;
        else
            luminance = _luminance;
    }
    real_t luminance;
    real_t get_emission(const Point &p) {
        return luminance;
    }
};


#endif