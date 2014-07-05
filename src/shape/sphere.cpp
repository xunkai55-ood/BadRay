#include "shape/sphere.hpp"
#include <cstdio>

ShapeIntersectInfo Sphere::intersect(Ray r) {
    Vec a = o - r.s, n;
    real_t t, b = a.dot(r.d), det = b * b - a.dot(a) + radius * radius;
    
    if (det < 0)
        return ShapeIntersectInfo();
    det = sqrt(det);
    t = b - det;
    int inner = false;
    if (t <= EPS) {
        t = b + det;
        n = a - t * r.d;
        inner = true;
        if (t <= EPS) 
            return ShapeIntersectInfo();
    } else {
        n = t * r.d - a;
    }
    n.norm();

    return ShapeIntersectInfo(t, n, inner);
}