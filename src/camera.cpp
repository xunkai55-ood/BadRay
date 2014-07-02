#include "camera.hpp"
#include "random.hpp"

Ray Camera::generate_ray(int i, int j) {

    Vec raw = o + cursor + j * cell_x * right - i * cell_y * up;
    raw += (rand_real() - 0.5) * cell_x * right + (rand_real() - 0.5) * cell_y * up;
    raw.norm();
    return Ray(o, raw);
}