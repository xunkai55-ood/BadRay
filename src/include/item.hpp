#ifndef BADRAY_ITEM_HPP
#define BADRAY_ITEM_HPP

class Item {
public:
    Item() {}
    inline bool is_emissive() {
        return ems;
    }
    bool ems;

};

#endif