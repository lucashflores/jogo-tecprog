#pragma once

#include "StageFactory.h"
#include "Stage1.h"
#define TILES_INSTRUCTIONS_PATH "../assets/stages/stage1/tileInstructions.txt"
#define ENEMIES_INSTRUCTIONS_PATH "../assets/stages/stage1/enemiesInstructions.txt"
#define OBSTACLES_INSTRUCTIONS_PATH "../assets/stages/stage1/obstaclesInstructions.txt"

namespace Stages {
    class Stage1Factory: public StageFactory {
    private:
        void makeStage();
    public:
        Stage1Factory();
        ~Stage1Factory();
        void makeTiles(std::string tilesInstructionsPath);
        void makeEnemies(std::string enemiesInstructionsPath);
        void makeObstacles(std::string obstaclesInstructionsPath);
        Stage* requestStage(Entities::Player* player1, Entities::Player* player2);
    };
}