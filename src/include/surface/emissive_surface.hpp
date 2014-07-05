#ifndef BADRAY_SURFACE_EMISSIVE_SURFACE
#define BADRAY_SURFACE_EMISSIVE_SURFACE

#include "surface.hpp"

class EmissiveSurface : public Surface {
public:
    EmissiveSurface() : Surface(0, 0, 0, 0.05, 0) {}
    inline bool is_emissive() {
        return true;
    }
};

#endif