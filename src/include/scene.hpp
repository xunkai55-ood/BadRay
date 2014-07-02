#ifndef BADRAY_SCENE_HPP
#define BADRAY_SCENE_HPP

#include <vector>

#include "shape.hpp"
#include "item.hpp"

class Scene
{
public:
    ~Scene();
    Scene &add_item(Item* item);

    std::vector< Item* > items;
    std::vector< Item* > emissive_items;
};

#endif
