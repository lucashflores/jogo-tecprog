#include "Stages/Stage.h"
using namespace Stages;

Stage::Stage(EntityList* pEL, Entities::Player *p1, Entities::Player *p2):
pGraphicManager(Managers::GraphicManager::getInstance()),
pCollisionManager(Managers::CollisionManager::getInstance()),
isStageDone(false), entityList(pEL), player1(p1), player2(p2)
{
    pCollisionManager->setEntityList(entityList);
}

Stage::~Stage() {
    entityList->removeEntity(player1);
    entityList->removeEntity(player2);
    player1 = NULL;
    player2 = NULL;
    if (entityList)
        delete entityList;
}

void Stage::setScore(unsigned int scr) {
    score = scr;
}

unsigned int Stage::getScore() {
    return score;
}

void Stage::renderEntities() {
    entityList->renderAllEntities();
}

void Stage::updateEntities(float dt) {
    entityList->updateAllEntities(dt);
}

void Stage::centerView() {
    float posX = 0.f;
    float posY = 0.f;
    if (player2) {
        posX = player1->getPosition().getX() - player2->getPosition().getX();
        posY = player1->getPosition().getY() - player2->getPosition().getY();
        posY += 70.f;
        if (posX < 0)
            posX = -posX;
        if (posY < 0)
            posY = -posY;
    }
    else {
        posX = player1->getPosition().getX();
        posY = player1->getPosition().getY() + 70.f;
    }
    pGraphicManager->centerView(Coordinates::Vector<float>(posX, posY));
}


void Stage::collideEntities() {
    pCollisionManager->collideAllEntities();
}

void Stage::exec(float dt) {
    removedNeutralizedEntities();
    updateEntities(dt);
    collideEntities();
    renderEntities();
    if (player2) {
        if (player1->getPosition().getX() >= 10000.f && player2->getPosition().getX() >= 10000.f)
            isStageDone = true;
    }
    else {
        if (player1->getPosition().getX() >= 10000.f) {
            isStageDone = true;
        }
    }


}

void Stage::removedNeutralizedEntities() {
    Entities::Entity* pE = NULL;
    for (int i = 0; i < entityList->getSize(); i++) {
        pE = entityList->operator[](i);
        if (pE) {
            if (!pE->getIsAlive())
                entityList->removeAndDeleteEntity(pE);
        }
    }
}