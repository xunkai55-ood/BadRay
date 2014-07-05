#ifndef BADRAY_CAMERA_HPP
#define BADRAY_CAMERA_HPP

#include "math.hpp"
#include "ray.hpp"

#include <cstdio>

class Camera {
public:
    Camera(Point _o, Vec _dist, Vec _right, Vec _up, int _w, int _h): o(_o), right(_right), up(_up), w(_w), h(_h), dist(_dist) {

        cell_x = 2 * right.length() / w;
        cell_y = 2 * up.length() / h;
        right.norm();
        up.norm();
        fprintf(stderr, "cell_x %lf cell_y %lf\n", cell_x, cell_y);
        cursor = dist - (w - 1) * 0.5 * cell_x * right + (h - 1) * 0.5 * up * cell_y; 
    }
    Ray generate_ray(int x, int y);

    Point o;
    Vec dist, right, up, cursor;
    int w, h;
    real_t cell_x, cell_y;
};

#endif 