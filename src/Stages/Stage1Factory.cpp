#include "Stages/Stage1Factory.h"
using namespace Stages;

Stage1Factory::Stage1Factory(): StageFactory(1) {
    tileInstructionsReader = new TileInstructionsReader(1, entityList);
}

Stage1Factory::~Stage1Factory() {
    if (enemyInstructionsReader)
        delete enemyInstructionsReader;
    if (obstacleInstructionsReader)
        delete obstacleInstructionsReader;
    if (tileInstructionsReader)
        delete tileInstructionsReader;
}

void Stage1Factory::makeTiles(std::string tilesInstructionsPath) {
    tileInstructionsReader->readInstructions(tilesInstructionsPath);
}

void Stage1Factory::makeObstacles(std::string obstaclesInstructionsPath) {
    obstacleInstructionsReader->readInstructions(obstaclesInstructionsPath);
}

void Stage1Factory::makeEnemies(std::string enemiesInstructionsPath) {
    enemyInstructionsReader->readInstructions(enemiesInstructionsPath);
}

void Stage1Factory::makeStage(Entities::Player* player1, Entities::Player* player2) {
    entityList->addEntity(player1);
    if (player2)
        entityList->addEntity(player2);
    makeTiles(TILES1_INSTRUCTIONS_PATH);
    makeObstacles(OBSTACLES1_INSTRUCTIONS_PATH);
    makeEnemies(ENEMIES1_INSTRUCTIONS_PATH);
}

Stage* Stage1Factory::requestStage(Entities::Player* player1, Entities::Player* player2) {
    makeStage(player1,player2);
    Stage1* stage = new Stage1(entityList, player1, player2);
    return static_cast<Stage*>(stage);
}