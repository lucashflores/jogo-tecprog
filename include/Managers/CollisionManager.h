#pragma once

#include "EntityList.h"
#include "Collisions/CollisionChooser.h"
#include <math.h>

namespace Managers {

    class CollisionManager {
    private:
        EntityList* pEntityList;
        Collisions::CollisionChooser* collisionChooser;

        CollisionManager();

        static CollisionManager* instance;
    public:
        ~CollisionManager();

        void setEntityList(EntityList* pEL);

        static CollisionManager* getInstance();

        void collideAllEntities();
    };

}