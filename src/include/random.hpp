#ifndef BADRAY_RANDOM_HPP
#define BADRAY_RANDOM_HPP

#include <cstdlib>
#include <ctime>

#include "math.hpp"

namespace {
unsigned short x[3];
}

inline void rand_init() {
    srand(time(0));
    x[0] = rand();
    x[1] = rand();
    x[2] = rand();
}
inline real_t rand_real() {
    return erand48(x);
}

#endif