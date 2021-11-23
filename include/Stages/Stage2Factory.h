#pragma once

#include "StageFactory.h"
#include "Stage2.h"
#define TILES2_INSTRUCTIONS_PATH "../assets/stages/stage2/tileInstructions.txt"
#define ENEMIES2_INSTRUCTIONS_PATH "../assets/stages/stage2/enemiesInstructions.txt"
#define OBSTACLES2_INSTRUCTIONS_PATH "../assets/stages/stage2/obstaclesInstructions.txt"

namespace Stages {
    class Stage2Factory: public StageFactory {
    private:
        void makeStage(Entities::Player* player1, Entities::Player* player2);
        void makeTiles(std::string tilesInstructionsPath);
        void makeEnemies(std::string enemiesInstructionsPath);
        void makeObstacles(std::string obstaclesInstructionsPath);
    public:
        Stage2Factory();
        ~Stage2Factory();
        Stage* requestStage(Entities::Player* player1, Entities::Player* player2);
    };
}