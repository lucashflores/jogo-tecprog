#pragma once
#include "Tile.h"

namespace Entities {
    class OilTile: public Tile {
    public:
        OilTile(Coordinates::Vector<float> pos);
        ~OilTile();
        void initializeSprite();
    };
}