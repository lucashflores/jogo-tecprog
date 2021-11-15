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

        void setEntityList(EntityList* pEL);

        static CollisionManager* getInstance();

        void collideAllEntities();
    };

}