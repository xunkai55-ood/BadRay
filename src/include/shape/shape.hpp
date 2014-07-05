#ifndef BADRAY_SHAPE_SHAPE_HPP
#define BADRAY_SHAPE_SHAPE_HPP

// Describe the Shapes that may exist in the scene

#include "../math.hpp"
#include "../ray.hpp"

struct ShapeIntersectInfo
{
    ShapeIntersectInfo(const ShapeIntersectInfo &s) {
        t = s.t, n = s.n, ok = s.ok, inner = s.inner;
    }
    ShapeIntersectInfo(real_t _t, Vec _n, bool _i): t(_t), n(_n), ok(true), inner(_i) {}
    ShapeIntersectInfo(): ok(false) {}
    real_t t;
    Vec n;
    bool ok;
    bool inner;
};


/* Shape: abstract object */
class Shape
{
public:
    Shape(Point _o): o(_o) {}
    virtual ~Shape() {}
    virtual ShapeIntersectInfo intersect(Ray r) = 0;
    Point o;
};

#endif