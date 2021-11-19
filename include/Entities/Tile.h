#pragma once
#include "Obstacle.h"



namespace Entities {
    class Tile : public Obstacle {
    public:
        Tile(Id::ids tileId, Coordinates::Vector<float> pos);
        ~Tile();
        void collide(Entity* pE, Coordinates::Vector<float> collision);
    };
}