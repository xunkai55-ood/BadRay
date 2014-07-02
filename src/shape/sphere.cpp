#include "shape/sphere.hpp"

ShapeIntersectInfo Sphere::intersect(Ray r) {
    Vec a = o - r.s;
    real_t at = a.dot(r.d);
    real_t d2 = a.length2() - at * at;
    real_t r2 = radius * radius;
    if (d2 > r2)
        return ShapeIntersectInfo(false);
    real_t rest = at - sqrt(r2 - d2);
    if (rest < 0) {
        rest = at - sqrt(r2 - d2);
        if (rest < 0)
            return ShapeIntersectInfo(false);   
        else {
            Vec resn = a - rest * r.d;
            resn.norm();
            return ShapeIntersectInfo(rest, resn, true);
        }
    }
    Vec resn = rest * r.d - a;
    resn.norm();
    return ShapeIntersectInfo(rest, resn, false);
}