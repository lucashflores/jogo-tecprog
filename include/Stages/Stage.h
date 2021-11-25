#pragma once

#include "Managers/CollisionManager.h"
#include "Entities/Player.h"
#include "Background.h"
#include "ProjectileMaker.h"

#define STAGE_SAVE_PATH "../saves/stageSave.txt"
#define ENEMY_SAVE_PATH "../saves/enemySave.txt"
#define OBSTACLE_SAVE_PATH "../saves/obstacleSave.txt"
#define PROJECTILE_SAVE_PATH "../saves/projectileSave.txt"
#define PLAYER1_SAVE_PATH "../saves/player1Save.txt"
#define PLAYER2_SAVE_PATH "../saves/player2Save.txt"

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
        Stage(EntityList* pEL);
        Stage(EntityList* pEL, Entities::Player* p1, Entities::Player* p2);
        virtual ~Stage();
        virtual int getStageNumber();
        unsigned int getScore();
        void setScore(unsigned int scr);
        void exec(float dt);
        void updateEntities(float dt);
        void renderEntities();
        void centerView();
        void collideEntities();
        void removedNeutralizedEntities();
        void save();
    };
}