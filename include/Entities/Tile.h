#pragma once
#include "Obstacle.h"
#include "Defines/tileafx.h"
#include <map>



namespace Entities {
    class Tile : public Obstacle {
    private:
        std::map<Id::ids, std::string> tileTextureMap;
    public:
        Tile(Id::ids tileId, Coordinates::Vector<float> pos);

        ~Tile();

        void createTileTextureMap();

        void collide(Entity* pE, Coordinates::Vector<float> collision);

        void initializeSprite();
    };
}