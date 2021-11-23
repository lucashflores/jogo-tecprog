#pragma once

#include "Managers/CollisionManager.h"
#include "Entities/Player.h"
#include "Background.h"

namespace Stages {
    class Stage {
    protected:
        Managers::GraphicManager* pGraphicManager;
        Managers::CollisionManager* pCollisionManager;
        EntityList* entityList;
        Entities::Player* player1;
        Entities::Player* player2;
        Background* background;
        unsigned int score;
        bool isStageDone;
    public:
        Stage(EntityList* pEL, Entities::Player* p1, Entities::Player* p2);
        ~Stage();
        unsigned int getScore();
        void setScore(unsigned int scr);
        void exec(float dt);
        void updateEntities(float dt);
        void renderEntities();
        void centerView();
        void collideEntities();
        void removedNeutralizedEntities();
    };
}