#include "Stages/StageFactory.h"
using namespace Stages;

StageFactory::StageFactory(int stg):stage(stg) {
    entityList = new EntityList();
    enemyFactory = new EnemyFactory(entityList);
    obstacleFactory = new ObstacleFactory(entityList);
    tileFactory = new TileFactory(stage, entityList);
}

StageFactory::~StageFactory() {
    if (enemyFactory)
        delete enemyFactory;
    if (obstacleFactory)
        delete obstacleFactory;
    if (tileFactory)
        delete tileFactory;
    entityList = NULL;
}
