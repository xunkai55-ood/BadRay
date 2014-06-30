#ifndef BADRAY_SHAPE_SHAPE_HPP
#define BADRAY_SHAPE_SHAPE_HPP

// Describe the Shapes that may exist in the scene

#include "../math.hpp"
#include "../ray.hpp"


struct ShapeIntersectInfo
{
    ShapeIntersectInfo(real_t _t, Vec _n): t(_t), n(_n), ok(true) {}
    ShapeIntersectInfo(bool ok): ok(false) {}
    real_t t;
    Vec n;
    bool ok;
};


/* Shape: abstract object */
class Shape
{
public:
    Shape() {}
    virtual ~Shape() {}
    virtual ShapeIntersectInfo intersect(Ray r) = 0;
};

#endif