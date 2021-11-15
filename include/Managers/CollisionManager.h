#pragma once

#include "EntityList.h"

namespace Managers {

    class CollisionManager {
    private:
        EntityList* pEntityList;

        CollisionManager();

        static CollisionManager* instance;
    public:
        ~CollisionManager();

        static CollisionManager* getInstance();

        void collideAllEntities();
    };

}