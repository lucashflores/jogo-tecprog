#pragma once

#include "Stage.h"
#include "EntityList.h"
#include "EnemyInstructionsReader.h"
#include "ObstacleInstructionsReader.h"
#include "TileInstructionsReader.h"
#include "InstructionsReader.h"

namespace Stages {

    class StageFactory {
    protected:
        EntityList* entityList;
        EnemyInstructionsReader* enemyInstructionsReader;
        ObstacleInstructionsReader* obstacleInstructionsReader;
        TileInstructionsReader* tileInstructionsReader;
        ProjectileMaker* projectileMaker;
        int stage;
        virtual void makeStage(Entities::Player* player1, Entities::Player* player2) = 0;
        virtual void makeTiles(std::string tilesInstructionsPath) = 0;
        virtual void makeEnemies(std::string enemiesInstructionsPath) = 0;
        virtual void makeObstacles(std::string obstaclesInstructionsPath) = 0;
    public:
        StageFactory(int stg);
        ~StageFactory();
        virtual Stage* requestStage(Entities::Player* player1, Entities::Player* player2) = 0;
    };
}