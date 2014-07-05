#ifndef BADRAY_RENDERER_HPP
#define BADRAY_RENDERER_HPP

#include <string>
#include <cstdio>

class Renderer {
public:
    Renderer() {}

    virtual void render(int w, int h, int id, Intensity *map) = 0;
};

class PPMRenderer : public Renderer {
public:
    PPMRenderer() {}

    void render(int w, int h, int id, Intensity *map) {
        char fn[100];
        sprintf(fn, "result%d.ppm", id);
        FILE *f = fopen(fn, "w");

        fprintf(f, "P3\n%d %d\n%d\n", w, h, 255);
        for (int i = 0; i < w * h; i++)
            fprintf(f, "%d %d %d ", clamp(map[i].r), clamp(map[i].g), clamp(map[i].b));
    }

    inline int clamp(intensity_t x) {
        return (int)((x > 1 ? 1 : x) * 255);
    }
};

#endif