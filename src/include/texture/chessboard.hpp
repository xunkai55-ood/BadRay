#ifndef BADRAY_TEXTURE_CHESSBOARD_HPP
#define BADRAY_TEXTURE_CHESSBOARD_HPP

#include "texture.hpp"
#include "../intensity.hpp"

class ChessBoard : public Texture {
public:
    ChessBoard(real_t cell_a_) : cell_a(cell_a_) {}
    Intensity get_texture(Point &p) {
        int k1 = real_abs(p.x) / cell_a;
        if (p.x < 0) k1 = 1 - k1;
        int k2 = real_abs(p.y) / cell_a;
        if (p.y < 0) k2 = 1 - k2;
        if ((k1 + k2) % 2 == 0)
            return Intensity(0, 0, 0);
        else
            return Intensity(1, 1, 1);
    }

    real_t cell_a;
};

#endif