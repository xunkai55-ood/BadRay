#ifndef BADRAY_RENDERER_HPP
#define BADRAY_RENDERER_HPP

#include "tracer.hpp"
#include <string>
#include <cstdio>

class Renderer {
public:
    Renderer(Tracer *_tracer, std::string _fn, int _w, int _h): tracer(_tracer), fn(_fn), w(_w), h(_h) {}

    Tracer *tracer;
    std::string fn;
    int w, h;

    virtual void work() = 0;
};

class PPMRenderer : Renderer {
public:
    PPMRenderer(Tracer *_tracer, std::string _fn, int _w, int _h): Renderer(_tracer, _fn, _w, _h) {}

    void work() {
        FILE *f = fopen(fn.c_str(), "w");
        fprintf(f, "P3\n%d %d\n%d\n", w, h, 255);
        Intensity *map = new Intensity[w * h];
        tracer->paint(map);
        for (int i = 0; i < w * h; i++)
            fprintf(f, "%d %d %d ", scale(map[i].r), scale(map[i].g), scale(map[i].b));
        delete map;
    }

    inline int scale(intensity_t x) {
        return (int)(x * 255);
    }
};

#endif