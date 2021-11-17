#pragma once


#include "EntityList.h"
#include "EnemySpawner.h"
#include "ObstacleBuilder.h"
#include "TileMaker.h"

namespace Stages {
    class InstructionsTranslator;

    class StageBuilder {
    private:
        EntityList* pEntityList;
        EnemySpawner* enemySpawner;
        ObstacleBuilder* obstacleBuilder;
        TileMaker* tileMaker;
        int stage;
    public:
        StageBuilder(EntityList* pEL);
        ~StageBuilder();
        void setStage(int stg);
        void buildStage(std::string stageInstructionsPath);
        void makePlatform(Coordinates::Vector<float> initialPos, unsigned int size);
        void makeRoof(Coordinates::Vector<float> initialPos, unsigned int size);
        void makeWall(Coordinates::Vector<float> initialPos, unsigned int size, bool right);
        void makeTileBackground(Coordinates::Vector<float> initialPos, Coordinates::Vector<unsigned int> size);
        void spawnSmokerEnemy(Coordinates::Vector<float> pos);
        void spawnDogEnemy(Coordinates::Vector<float> pos);
        void spawnBoss(Coordinates::Vector<float> pos);
        void buildBarrel(Coordinates::Vector<float> pos);
        void buildOilTile(Coordinates::Vector<float> pos);
        void buildFire(Coordinates::Vector<float> pos);
        void buildSign(Coordinates::Vector<float> pos);
    };
}