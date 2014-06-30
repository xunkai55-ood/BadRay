#ifndef BADRAY_SHAPE_SPHERE_HPP
#define BADRAY_SHAPE_SPHERE_HPP

#include "shape.hpp"

class Sphere : public Shape
{
public:
    Sphere(const Point &_o, real_t _radius) : o(_o), radius(_radius) {}
    Point o;
    real_t radius;

    ShapeIntersectInfo intersect(Ray r);
};

#endif