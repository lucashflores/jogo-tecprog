#include "Stages/Stage2Factory.h"
using namespace Stages;

Stage2Factory::Stage2Factory(): StageFactory(2) {
}

Stage2Factory::~Stage2Factory() {
    if (enemyInstructionsReader)
        delete enemyInstructionsReader;
    if (obstacleInstructionsReader)
        delete obstacleInstructionsReader;
    if (tileInstructionsReader)
        delete tileInstructionsReader;
}

void Stage2Factory::makeTiles(std::string tilesInstructionsPath) {
    tileInstructionsReader->readInstructions(tilesInstructionsPath);
}

void Stage2Factory::makeObstacles(std::string obstaclesInstructionsPath) {
    obstacleInstructionsReader->readInstructions(obstaclesInstructionsPath);
}

void Stage2Factory::makeEnemies(std::string enemiesInstructionsPath) {
    enemyInstructionsReader->readInstructions(enemiesInstructionsPath);
}

void Stage2Factory::makeStage(Entities::Player* player1, Entities::Player* player2) {
    entityList->addEntity(player1);
    if (player2)
        entityList->addEntity(player2);
    tileInstructionsReader = new TileInstructionsReader(2, entityList);
    makeTiles(TILES2_INSTRUCTIONS_PATH);
    obstacleInstructionsReader = new ObstacleInstructionsReader(entityList);
    makeObstacles(OBSTACLES2_INSTRUCTIONS_PATH);
    enemyInstructionsReader = new EnemyInstructionsReader(entityList, player1, player2, projectileMaker);
    makeEnemies(ENEMIES2_INSTRUCTIONS_PATH);
}

Stage* Stage2Factory::requestStage(Entities::Player* player1, Entities::Player* player2) {
    makeStage(player1, player2);
    Stage2* stage = new Stage2(entityList, player1, player2);
    return static_cast<Stage*>(stage);
}