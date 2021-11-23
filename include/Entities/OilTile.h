#pragma once
#include "Tile.h"

namespace Entities {
    class OilTile: public Tile {
    public:
        OilTile(Coordinates::Vector<float> pos);

        ~OilTile();
<<<<<<< HEAD
=======

        void initializeSprite();

        void saveEntity(std::ofstream& out);

        void restoreEntity(std::ifstream& in);
>>>>>>> 765ea23d113b3e3f487d8ce05effd29b43c74d28
    };
}