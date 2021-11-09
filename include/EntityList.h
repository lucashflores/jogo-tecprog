#pragma once

#include "Entities/Entity.h"
#include <list>

namespace Entities {
    class EntityList {
    private:
        std::list<Entity*> entityList;
        static EntityList* instance;
        EntityList();
    public:
        ~EntityList();
        static EntityList* getInstance();
        void addEntity(Entity* pE);
        std::list<Entity*>::iterator begin();
        std::list<Entity*>::iterator end();
        void removeEntity(Entity* pE);
        void renderAllEntities();
    };
}