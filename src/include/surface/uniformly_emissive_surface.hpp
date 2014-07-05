#ifndef BADRAY_SURFACE_UNIFORMLY_EMISSIVE_SURFACE
#define BADRAY_SURFACE_UNIFORMLY_EMISSIVE_SURFACE

#include "emissive_surface.hpp"

class UniformlyEmissiveSurface : public EmissiveSurface {
public:
    UniformlyEmissiveSurface(Intensity _luminance) : EmissiveSurface(), luminance(_luminance) {}
    Intensity luminance;
    Intensity get_emission(const Point &p) {
        return luminance;
    }
};

namespace surface {
    inline Surface *Light(Intensity _luminance) {
        return new UniformlyEmissiveSurface(_luminance);
    }
    inline Surface *Light(intensity_t r, intensity_t g, intensity_t b) {
        return new UniformlyEmissiveSurface(Intensity(r, g, b));
    }
}


#endif