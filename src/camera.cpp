#include "camera.hpp"
#include "random.hpp"

#include <cstdio>

Ray Camera::generate_ray(int i, int j) {

    Vec raw = cursor + j * cell_x * right - i * cell_y * up;
    
    // if (i == 0 && j == 0)
    //     fprintf(stderr, "%lf %lf %lf\n", raw.x, raw.y, raw.z);
    // if (i == 299 && j == 399)
    //     fprintf(stderr, "%lf %lf %lf\n", raw.x, raw.y, raw.z);
    // if (i == 599 && j == 799)
    //     fprintf(stderr, "%lf %lf %lf\n", raw.x, raw.y, raw.z);
    
    raw += (rand_real() - 0.5) * cell_x * right + (rand_real() - 0.5) * cell_y * up;
    raw.norm();
    return Ray(o, raw);
}