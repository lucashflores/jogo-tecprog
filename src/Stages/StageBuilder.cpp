#include "Stages/StageBuilder.h"
#include "Stages/InstructionsTranslator.h"
using namespace Stages;

StageBuilder::StageBuilder(EntityList *pEL) {
    pEntityList = NULL;
    if (pEL)
        pEntityList = pEL;

    enemySpawner = new EnemySpawner(pEntityList);
    tileMaker = new TileMaker(pEntityList);
    obstacleBuilder = new ObstacleBuilder(pEntityList);
}

StageBuilder::~StageBuilder() {
    pEntityList = NULL;
    if (enemySpawner)
        delete enemySpawner;
    if (obstacleBuilder)
        delete obstacleBuilder;
    if (tileMaker)
        delete tileMaker;
}

void StageBuilder::setStage(int stg) {
    stage = stg;
    if (stage != 1 && stage != 2)
        stage = 1;
    tileMaker->setStage(stage);
}

void StageBuilder::buildStage(std::string stageInstructionsPath) {
    InstructionsTranslator* translator = new InstructionsTranslator(this);
    translator->translateInstructions(stageInstructionsPath);
}

void StageBuilder::makePlatform(Coordinates::Vector<float> initialPos, unsigned int size) {
    tileMaker->makePlatform(initialPos, size);
}

void StageBuilder::makeRoof(Coordinates::Vector<float> initialPos, unsigned int size) {
    tileMaker->makeRoof(initialPos, size);
}

void StageBuilder::makeWall(Coordinates::Vector<float> initialPos, unsigned int size, bool right) {
    tileMaker->makeWall(initialPos, size, right);
}

void StageBuilder::makeTileBackground(Coordinates::Vector<float> initialPos, Coordinates::Vector<unsigned int> size) {
    tileMaker->makeTileBackground(initialPos, size);
}

void StageBuilder::spawnSmokerEnemy(Coordinates::Vector<float> pos) {
    enemySpawner->spawnSmokerEnemy(pos);
}

/*
void StageBuilder::spawnDogEnemy(Coordinates::Vector<float> pos) {
    enemySpawner->spawnDogEnemy(pos);
}

void StageBuilder::spawnBoss(Coordinates::Vector<float> pos) {
    enemySpawner->spawnBoss(pos)
}
 */

void StageBuilder::buildFire(Coordinates::Vector<float> pos) {
    obstacleBuilder->buildFire(pos);
}

void StageBuilder::buildSign(Coordinates::Vector<float> pos) {
    obstacleBuilder->buildSign(pos);
}

void StageBuilder::buildBarrel(Coordinates::Vector<float> pos) {
    obstacleBuilder->buildBarrel(pos);
}

void StageBuilder::buildOilTile(Coordinates::Vector<float> pos) {
    obstacleBuilder->buildOilTile(pos);
}