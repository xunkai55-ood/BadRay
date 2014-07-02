#include <iostream>
#include <cstdlib>

#include "badray.hpp"

int main(int argc, char **argv)
{
    using namespace std;
    cout << "Bad Ray Running!" << endl;

    rand_init();

#if 0 
    // TEST: BALL

    Scene scene;
    Sphere ball(Point(0, 10, 3), 5);
    Ray r(Point(0, 0, 0), Vec(0, 1, 0));
    ShapeIntersectInfo info = ball.intersect(r);

    cout << info.t << endl;
    cout << info.n.x << " " << info.n.y << " " << info.n.z << endl;
#endif

    // TEST: a single emissive ball in the space

    Scene scene;
    scene.add_item(new Item(
        new Sphere(Point(0, 100, 30), 15),
        new UniformlyEmissiveSurface(1.0),
        new Monocolor(Intensity(1, 1, 1))
    ));

    Camera camera(
        Point(0, 0, 0), // center
        Vec(0, 1.2, 0), // deep-dir vector
        Vec(2, 0, 0),   // 1/2 right
        Vec(0, 0, 1.5), // 1/2 up
        800, 600        // pixel
    ); 

    Tracer tracer(
        &camera,
        &scene,
        100 // samples count
    );

    PPMRenderer renderer(
        &tracer,
        "result.ppm",
        800, 600
    );

    renderer.work();

    return 0;
}