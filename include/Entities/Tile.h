#pragma once
#include "Obstacle.h"


namespace Entities {
    class Tile : public Obstacle {
    public:
        Tile(Id::ids i, Coordinates::VectorFloat pos);
        ~Tile();
        void collide(Entity* pE);
    };
}