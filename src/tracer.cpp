#include "tracer.hpp"
#include <cstdio>
#include "random.hpp"

Intensity Tracer::trace(Ray incident, bool inner, int depth = 0, int x = -1, int y = -1) {
    if (incident.power < TRACER_MIN_POWER || depth >= TRACER_MAX_DEPTH)
        return Intensity(0, 0, 0);

    // fprintf(stderr, "Ray(%lf,%lf,%lf)--(%lf,%lf,%lf)--> : %lf\n", incident.s.x, incident.s.y, incident.s.z, incident.d.x, incident.d.y, incident.d.z, incident.power);

    IntersectInfo ci = get_closest_intersect(incident);

    if (depth == 0) {
        real_t scene_depth = camera->dist.dot((incident.s + (ci.t * incident.d)) - camera->o);
        // fprintf(stderr, "%lf\n", scene_depth);
        // here we focus on 30
        if (scene_depth < 80) {
            real_t ratio = (80 - scene_depth) * 15 / 80;
            // fprintf(stderr, "haha %lf\n", ratio);
            incident = camera->generate_ray(x, y, ratio);
            ci = get_closest_intersect(incident);
        }
    }

    // fprintf(stderr, "%d\n", ci.ok);
    if (ci.ok == false) {
        return Intensity(0, 0, 0);
    }

    Point rp = incident.s + ci.t * incident.d;
    Point p = rp - ci.item_ptr->center();

    // fprintf(stderr, "collapse %lf %lf %lf\n", rp.x, rp.y, rp.z);
    Intensity ems = ci.item_ptr->surface->get_emission(p);
    // fprintf(stderr, "EMS: %lf %lf %lf\n", ems.r, ems.g, ems.b);

    bool new_inner = inner;
    Intensity txt(ci.item_ptr->texture->get_texture(p));
    Ray new_r(ci.item_ptr->surface-> \
        generate_ray(rp, incident.d, ci.n, new_inner, incident.power));
    // fprintf(stderr, "Gen Ray(%lf,%lf,%lf)--(%lf,%lf,%lf)--> : %lf\n", new_r.s.x, new_r.s.y, new_r.s.z, new_r.d.x, new_r.d.y, new_r.d.z, new_r.power);

    Intensity light(trace(new_r, new_inner, depth + 1));

    return txt * light + ems;
}

IntersectInfo Tracer::get_closest_intersect(Ray r) {
    IntersectInfo ci;
    for (int i = 0; i < scene->items.size(); i++) {
        IntersectInfo tmp_info = scene->items[i]->intersect(r);
        if (tmp_info.ok && (!ci.ok || tmp_info.t < ci.t)) ci = tmp_info;
    }
    return ci;
}

void Tracer::paint() {

    // trace(camera->generate_ray(400, 300), false);
    Intensity *map = new Intensity[camera->w * camera->h];
    Intensity *mapcpy = new Intensity[camera->w * camera->h];
    for (int i = 0; i < camera->h; i++)
        for (int j = 0; j < camera->w; j++)
            map[i * camera->w + j] = Intensity(0, 0, 0);
    for (int tc = 1; tc <= samples; tc++) {
        fprintf(stderr, "%d / %d\n", tc, samples);
        for (int i = 0; i < camera->h; i++)
            for (int j = 0; j < camera->w; j++)
                map[i * camera->w + j] += trace(camera->generate_ray(i, j), false, 0, i, j);

        if (tc % gap == 0) {
            real_t alpha = 1.0 / tc;
            for (int i = 0; i < camera->h; i++)
                for (int j = 0; j < camera->w; j++)
                    mapcpy[i * camera->w + j] = map[i * camera->w + j] * alpha;
            renderer->render(camera->w, camera->h, tc / gap, mapcpy);
        }

        if (tc % (gap * 20) == 0) {
            scene->items[6]->shape->o += 2;
        }
    }
    delete mapcpy;
}
