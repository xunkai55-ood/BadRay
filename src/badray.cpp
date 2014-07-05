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
    scene.add_item(new Item(1,
        new Sphere(Point(-1e5 - 30, 0, 0), 1e5),
        surface::SolidRough(),
        new Monocolor(Intensity(0.75, 0.25, 0.25))
    ));

    scene.add_item(new Item(2,
        new Sphere(Point(-1e5 + 30, 0, 0), 1e5),
        surface::SolidRough(),
        new Monocolor(Intensity(0.25, 0.25, 0.75))
    ));

    scene.add_item(new Item(3,
        new Sphere(Point(0, 30, 1e5 + 30), 1e5),
        surface::SolidRough(),
        new Monocolor(Intensity(0.6, 0.8, 0.25))
    ));

    scene.add_item(new Item(4,
        new Sphere(Point(0, 30, -1e5 - 30), 1e5),
        surface::SolidRough(),
        new ChessBoard(10)
    ));

    scene.add_item(new Item(5,
        new Sphere(Point(0, 1e5 + 50, 0), 1e5),
        surface::SolidRough(),
        new Monocolor(Intensity(0.75, 0.75, 0.75))
    ));

    scene.add_item(new Item(6,
        new Sphere(Point(0, -1e5 - 22, 0), 1e5),
        surface::SolidRough(),
        new Monocolor(Intensity(0, 0, 0))
    ));

    scene.add_item(new Item(7,
        new Sphere(Point(0, 20, 630 - 0.1), 600),
        surface::Light(12, 12, 12),
        new Monocolor(Intensity(1, 1, 1))
    ));

    scene.add_item(new Item(8,
        new Sphere(Point(15, 38, 3), 12),
        surface::Mirror(),
        new Monocolor(Intensity(0.9, 0.9, 0.9))
    ));

    scene.add_item(new Item(8,
        new Sphere(Point(-11, 27, -16), 8),
        surface::Glass(),
        new Monocolor(Intensity(0.9, 0.9, 0.9))
    ));


    scene.add_item(new Item(8,
        new Sphere(Point(0, 20, -31), 8),
        surface::Metal(),
        new Monocolor(Intensity(0.8, 0.6, 0.25))
    ));

    Camera camera(
        Point(0, -20, 0), // center
        Vec(0, 1.8, 0), // deep-dir vector
        Vec(2, 0, 0),   // 1/2 right
        Vec(0, 0, 1.5), // 1/2 up
        800, 600        // pixel
    );

    Renderer *renderer = new PPMRenderer;

    Tracer tracer(
        &camera,
        &scene,
        renderer,
        30, // samples count
        30
    );

    tracer.paint();

    return 0;
}