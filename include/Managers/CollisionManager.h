#pragma once

#include "Entities/EntityList.h"

namespace Managers {

    class CollisionManager {
    private:
        Entities::EntityList *pEntityList;

        CollisionManager();

        static CollisionManager *instance;
    public:
        ~CollisionManager();

        static CollisionManager *getInstance();

        void collideAllEntities();
    };

}