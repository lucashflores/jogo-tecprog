#pragma once

#include "Entities/Entity.h"
#include "List/List.h"
#include <list>

class EntityList {
private:

    List::List<Entities::Entity*> entityList;

public:
    using iterator = List::List<Entities::Entity*>::iterator;
    EntityList();
    ~EntityList();

    int getSize();

    Entities::Entity* operator[](int pos);

    void addEntity(Entities::Entity* pE);
    void removeEntity(Entities::Entity* pE);
    void removeAndDeleteEntity(Entities::Entity* pE);

    void renderAllEntities();
    void removeNeutralizedEntities();
    void updateAllEntities(float dt);

    iterator begin();
    iterator end();
};
