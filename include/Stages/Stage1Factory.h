#pragma once

#include "StageFactory.h"
#include "Stage1.h"
#define TILES1_INSTRUCTIONS_PATH "../assets/stages/stage1/tileInstructions.txt"
#define ENEMIES1_INSTRUCTIONS_PATH "../assets/stages/stage1/enemyInstructions.txt"
#define OBSTACLES1_INSTRUCTIONS_PATH "../assets/stages/stage1/obstacleInstructions.txt"

namespace Stages {
    class Stage1Factory: public StageFactory {
    private:
        void makeStage(Entities::Player* player1, Entities::Player* player2);
        void makeTiles(std::string tilesInstructionsPath);
        void makeEnemies(std::string enemiesInstructionsPath);
        void makeObstacles(std::string obstaclesInstructionsPath);
    public:
        Stage1Factory();
        ~Stage1Factory();
        Stage* requestStage(Entities::Player* player1, Entities::Player* player2);
    };
}