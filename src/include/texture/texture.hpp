#ifndef BADRAY_TEXTURE_TEXTURE_HPP
#define BADRAY_TEXTURE_TEXTURE_HPP

#include "../intensity.hpp"
class Texture {
public:
    Texture() {}
    virtual ~Texture() {}
    virtual Intensity get_texture(Point &p) = 0;

};

#endif