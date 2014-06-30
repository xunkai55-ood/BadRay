#include "scene.hpp"

Scene& Scene::add_object(Item *itm) {
    items.push_back(itm);
    if (itm->is_emissive())
        emissive_items.push_back(itm);
    return *this;
}