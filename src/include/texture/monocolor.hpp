#ifndef BADRAY_TEXTURE_MONOCOLOR_HPP
#define BADRAY_TEXTURE_MONOCOLOR_HPP

#include "texture.hpp"
#include "../intensity.hpp"

class Monocolor : public Texture {
public:
    Monocolor(const Intensity &i) : color(i) {}
    Intensity color;
    Intensity get_texture(Point &p) {
        return color;
    }
};

#endif