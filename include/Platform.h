#pragma once

#include "Id.h"
#include "List/List.h"
#include "Entities/Tile.h"

    class Platform {
        private:
            List::List<Entities::Tile> TileList;
        public:
            Platform(Id::ids id, int size);
            ~Platform();
    };