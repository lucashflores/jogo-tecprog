#pragma once

#include "Id.h"
#include "List/List.h"
#include "Entities/Tile.h"
#include "EntityList.h"

class Wall {
private:

    EntityList* pEntityList;
    List::List<Entities::Tile*> TileList;

public:
    Wall(Id::ids id, Coordinates::Vector<float> pos, int size, EntityList* pEL);
    ~Wall();
};