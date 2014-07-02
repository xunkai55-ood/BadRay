#include "tracer.hpp"
#include <cstdio>

Intensity Tracer::trace(Ray incident, int depth = 0) {
    if (incident.power < TRACER_MIN_POWER || depth >= TRACER_MAX_DEPTH)
        return Intensity(0, 0, 0);

    IntersectInfo ci = get_closest_intersect(incident);
    if (ci.ok == false) {
        return Intensity(0, 0, 0);
    }

    Point p = incident.s + ci.t * incident.d - ci.item_ptr->center();
    if (ci.item_ptr->is_emissive()) {
        return ci.item_ptr->surface->get_emission(p);
    }

    // Intensity texture = ci.item_ptr->get_texture(p);

    Intensity full(0, 0, 0);
    
    // full += texture;

    return full;
}

IntersectInfo Tracer::get_closest_intersect(Ray r) {
    IntersectInfo ci;
    for (int i = 0; i < scene->items.size(); i++) {
        IntersectInfo tmp_info = scene->items[i]->intersect(r);
        if (tmp_info.ok && (!ci.ok || tmp_info.t < ci.t)) ci = tmp_info;
    }
    return ci;
}

void Tracer::paint(Intensity *map) {

    for (int i = 0; i < camera->h; i++)
        for (int j = 0; j < camera->w; j++)
            map[i * camera->w + j] = Intensity(0, 0, 0);
    for (int tc = 0; tc < samples; tc++) {
        fprintf(stderr, "%d / %d\n", tc + 1, samples);
        for (int i = 0; i < camera->h; i++)
            for (int j = 0; j < camera->w; j++)
                map[i * camera->w + j] += trace(camera->generate_ray(i, j));
    }
    real_t alpha = 1 / samples;
    for (int i = 0; i < camera->h; i++)
        for (int j = 0; j < camera->w; j++)
            map[i * camera->w +j] *= alpha;
}
