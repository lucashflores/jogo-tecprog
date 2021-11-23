#include "Stages/StageFactory.h"
using namespace Stages;

StageFactory::StageFactory(int stg):stage(stg) {
    entityList = new EntityList();
    enemyInstructionsReader = new EnemyInstructionsReader(entityList);
    obstacleInstructionsReader = new ObstacleInstructionsReader(entityList);
}

StageFactory::~StageFactory() {

    entityList = NULL;
}
