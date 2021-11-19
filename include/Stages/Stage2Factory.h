#pragma once

#include "StageFactory.h"
#include "Stage2.h"
#define TILES_INSTRUCTIONS_PATH "../assets/stages/stage2/tileInstructions.txt"
#define ENEMIES_INSTRUCTIONS_PATH "../assets/stages/stage2/enemiesInstructions.txt"
#define OBSTACLES_INSTRUCTIONS_PATH "../assets/stages/stage2/obstaclesInstructions.txt"

namespace Stages {
    class Stage2Factory: public StageFactory {
    private:
        void makeStage();
    public:
        Stage2Factory();
        ~Stage2Factory();
        void makeTiles(std::string tilesInstructionsPath);
        void makeEnemies(std::string enemiesInstructionsPath);
        void makeObstacles(std::string obstaclesInstructionsPath);
        Stage* requestStage(Entities::Player* player1, Entities::Player* player2);
    };
}