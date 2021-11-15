#pragma once

#include "Entities/Entity.h"
#include "List/List.h"
#include <list>

class EntityList {
private:
    std::vector<Entities::Entity*> entityList;
public:
    EntityList();
    ~EntityList();
    int getSize();
    Entities::Entity* operator[](int pos);
    void addEntity(Entities::Entity* pE);
    void removeEntity(Entities::Entity* pE);
    void renderAllEntities();
};
