#pragma once

#include "Entity.h"
#include <list>

namespace Entities {
    class EntityList {
    private:
        std::list<Entity*> entityList;
        std::list<Entity*>::iterator it;
        static EntityList* instance;
        EntityList();
    public:
        ~EntityList();
        static EntityList* getInstance();
        void addEntity(Entity* pE);
        std::list<Entity*>::iterator begin();
        std::list<Entity*>::iterator end();
        std::list<Entity*>::iterator current();
        void next();
        void removeEntity();
        void renderAllEntities();
    };
}