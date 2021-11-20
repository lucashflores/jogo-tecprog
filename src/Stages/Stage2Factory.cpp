#include "Stages/Stage2Factory.h"
using namespace Stages;

Stage2Factory::Stage2Factory(): StageFactory(2) {

}

Stage2Factory::~Stage2Factory() {}

void Stage2Factory::makeTiles(std::string tilesInstructionsPath) {
    tileFactory->readAndExecuteInstructions(tilesInstructionsPath);
}

void Stage2Factory::makeObstacles(std::string obstaclesInstructionsPath) {
    obstacleFactory->readAndExecuteInstructions(obstaclesInstructionsPath);
}

void Stage2Factory::makeEnemies(std::string enemiesInstructionsPath) {
    enemyFactory->readAndExecuteInstructions(enemiesInstructionsPath);
}

void Stage2Factory::makeStage(Entities::Player* player1, Entities::Player* player2) {
    entityList->addEntity(player1);
    if (player2)
        entityList->addEntity(player2);
    makeTiles(TILES_INSTRUCTIONS_PATH);
    makeObstacles(OBSTACLES_INSTRUCTIONS_PATH);
    makeEnemies(ENEMIES_INSTRUCTIONS_PATH);
}

Stage* Stage2Factory::requestStage(Entities::Player* player1, Entities::Player* player2) {
    makeStage(player1, player2);
    Stage2* stage = new Stage2(entityList, player1, player2);
    return static_cast<Stage*>(stage);
}