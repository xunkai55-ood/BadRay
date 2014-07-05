#ifndef BADRAY_ITEM_HPP
#define BADRAY_ITEM_HPP

#include "shape.hpp"
#include "surface.hpp"
#include "texture.hpp"
#include "ray.hpp"

class Item;

struct IntersectInfo : ShapeIntersectInfo {
    Item *item_ptr;
    IntersectInfo(): item_ptr(0), ShapeIntersectInfo() {}
    IntersectInfo(Item *_p, const ShapeIntersectInfo &s): item_ptr(_p), ShapeIntersectInfo(s) {}
    IntersectInfo(Item *_p, real_t _t, Vec _n, bool _i): item_ptr(_p), ShapeIntersectInfo(_t, _n, _i) {}
};

class Item {
public:
    Item(int id_, Shape *_shape, Surface *_surface, Texture *_texture) : 
        id(id_), shape(_shape), surface(_surface), texture(_texture) {}
    virtual ~Item() {
        delete shape;
        delete surface;
        delete texture;
    }
    inline bool is_emissive() {
        return surface->is_emissive();
    }
    inline Point center() {
        return shape->o;
    }
    IntersectInfo intersect(Ray r) {
        return IntersectInfo(this, shape->intersect(r));
    }
    bool ems;
    int id;

    Shape *shape;
    Surface *surface;
    Texture *texture;
};

#endif