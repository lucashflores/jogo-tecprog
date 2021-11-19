#include "Stages/Stage1Factory.h"
using namespace Stages;

Stage1Factory::Stage1Factory(): StageFactory(1) {

}

Stage1Factory::~Stage1Factory() {}

void Stage1Factory::makeTiles(std::string tilesInstructionsPath) {
    tileFactory->readAndExecuteInstructions(tilesInstructionsPath);
}

void Stage1Factory::makeObstacles(std::string obstaclesInstructionsPath) {
    obstacleFactory->readAndExecuteInstructions(obstaclesInstructionsPath);
}

void Stage1Factory::makeEnemies(std::string enemiesInstructionsPath) {
    enemyFactory->readAndExecuteInstructions(enemiesInstructionsPath);
}

void Stage1Factory::makeStage() {
    makeTiles(TILES_INSTRUCTIONS_PATH);
    makeObstacles(OBSTACLES_INSTRUCTIONS_PATH);
    makeEnemies(ENEMIES_INSTRUCTIONS_PATH);
}

Stage* Stage1Factory::requestStage(Entities::Player* player1, Entities::Player* player2) {
    makeStage();
    Stage1* stage = new Stage1(entityList, player1, player2);
    return static_cast<Stage*>(stage);
}