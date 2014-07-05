#ifndef BADRAY_TRACER_HPP
#define BADRAY_TRACER_HPP

#include "scene.hpp"
#include "ray.hpp"
#include "intensity.hpp"
#include "camera.hpp"

const double TRACER_MIN_POWER = 0;
const int TRACER_MAX_DEPTH = 5;

class Tracer {
public:
    Tracer(Camera *_c, Scene *_s, int _r): camera(_c), scene(_s), samples(_r) {}
    ~Tracer() {}
    Intensity trace(Ray r, bool innner, int depth);
    IntersectInfo get_closest_intersect(Ray r);
    void paint(Intensity *map);

    Camera *camera;
    Scene *scene;
    int samples;
};

#endif