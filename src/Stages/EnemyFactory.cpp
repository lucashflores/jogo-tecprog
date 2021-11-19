#include "Stages/EnemyFactory.h"
#include "Stages/EnemyInstructionsReader.h"
using namespace Stages;

EnemyFactory::EnemyFactory(EntityList *pEL) {
    pEntityList = NULL;
    if (pEL)
        pEntityList = pEL;

}

EnemyFactory::~EnemyFactory() {
    pEntityList = NULL;
}

void EnemyFactory::readAndExecuteInstructions(std::string instructionsPath) {
    EnemyInstructionsReader* instructionsReader = new EnemyInstructionsReader(this);
    instructionsReader->readInstructions(instructionsPath);
    if (instructionsReader)
        delete instructionsReader;
}

void EnemyFactory::makeSmokerEnemy(Coordinates::Vector<float> pos) {
    Entities::SmokerEnemy* smoker = NULL;
    smoker = new Entities::SmokerEnemy(pos);
    pEntityList->addEntity(static_cast<Entities::Entity*>(smoker));
    smoker = NULL;
}

/*

void EnemyFactory::makeDogEnemy(Coordinates::Vector<float> pos) {
    Entities::DogEnemy* dog = NULL;
    dog = new Entities::DogEnemy(pos);
    pEntityList->addEntity(static_cast<Entities::Entity*>(dog));
    dog = NULL;
}

 */