#include <iostream>
#include <cstdlib>

#include "badray.hpp"

int main(int argc, char **argv)
{
    using namespace std;
    cout << "Bad Ray Running!" << endl;

    Scene scene;
    Sphere ball(Point(0, 10, 3), 5);
    Ray r(Point(0, 0, 0), Vec(0, 1, 0));
    ShapeIntersectInfo info = ball.intersect(r);

    cout << info.t << endl;
    cout << info.n.x << " " << info.n.y << " " << info.n.z << endl;

    return 0;
}