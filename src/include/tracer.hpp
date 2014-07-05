#ifndef BADRAY_TRACER_HPP
#define BADRAY_TRACER_HPP

#include "scene.hpp"
#include "ray.hpp"
#include "intensity.hpp"
#include "camera.hpp"
#include "renderer.hpp"

const double TRACER_MIN_POWER = 0;
const int TRACER_MAX_DEPTH = 5;

class Tracer {
public:
    Tracer(Camera *_c, Scene *_s, Renderer *_ren, int _r, int _g): 
        camera(_c), scene(_s), renderer(_ren), samples(_r), gap(_g) {}
    ~Tracer() {}
    Intensity trace(Ray r, bool innner, int depth);
    IntersectInfo get_closest_intersect(Ray r);
    void paint();

    Camera *camera;
    Scene *scene;
    Renderer *renderer;
    int samples, gap;
};

#endif