#include "scene.hpp"

Scene& Scene::add_item(Item *itm) {
    items.push_back(itm);
    if (itm->is_emissive())
        emissive_items.push_back(itm);
    return *this;
}

Scene::~Scene() {
    for (int i = 0; i < items.size(); i++)
        delete items[i];
    items.clear();
    emissive_items.clear();
}