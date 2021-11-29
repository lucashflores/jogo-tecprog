#include "Stages/Stage.h"
using namespace Stages;
#include "Concurrent/BossThread.h"

Stage::Stage(EntityList *pEL):
pGraphicManager(Managers::GraphicManager::getInstance()),
pCollisionManager(Managers::CollisionManager::getInstance()),
isStageDone(false), entityList(pEL)
{
    pCollisionManager->setEntityList(entityList);
}



Stage::Stage(EntityList* pEL, Entities::Player *p1, Entities::Player *p2):
pGraphicManager(Managers::GraphicManager::getInstance()),
pCollisionManager(Managers::CollisionManager::getInstance()),
isStageDone(false), entityList(pEL), player1(p1), player2(p2)
{
    score = 0;
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

bool Stage::getIsStageDone() {
    return isStageDone;
}

void Stage::setIsStageDone(bool iSD) {
    isStageDone = iSD;
}

void Stage::renderEntities() {
    background->render();
    entityList->renderAllEntities();
}

void Stage::updateEntities(float dt) {
    entityList->updateAllEntities(dt);
    centerView();
}

void Stage::centerView() {
    float posX = 0.f;
    float posY = 0.f;

    if (player2) {
        posX = (player1->getPosition().getX() + player2->getPosition().getX()) / 2.f;
        posY = (player1->getPosition().getY() + player2->getPosition().getY()) / 2.f;
        posY += 70.f;
        if (posX < 0)
            posX = -posX;
        if (posY < 0)
            posY = -posY;
    }
    else {

        posX = player1->getPosition().getX();
        posY = player1->getPosition().getY() - 10.f;
    }
    background->update(Coordinates::Vector<float>(posX, posY));
    pGraphicManager->centerView(Coordinates::Vector<float>(posX, posY));
}


void Stage::collideEntities() {
    pCollisionManager->collideAllEntities();
}

void Stage::exec(float dt) {

    Concurrent::BossThread::lock();
    pGraphicManager->setViewSize(Coordinates::Vector<float>(640.f, 480.f));
    removedNeutralizedEntities();
    updateEntities(dt);
    collideEntities();
    Concurrent::BossThread::unlock();
    renderEntities();
    if (player2) {
        if (player1->getPosition().getX() >= 2650.f && player2->getPosition().getX() >= 2650.f)
            setIsStageDone(true);
    }
    else {
        if (player1->getPosition().getX() >= 2650.f) {
            setIsStageDone(true);
        }
    }

}

void Stage::removedNeutralizedEntities() {

    Entities::Entity* pE = NULL;
    for (int i = 0; i < entityList->getSize(); i++) {
        pE = entityList->operator[](i);
        if (pE) {
            if (!pE->getIsAlive()) {
                if (static_cast<Entities::Character*>(pE)->getLife() == 0) {
                    if (pE->getId() == Id::smoker) {
                        setScore(getScore() + 100);
                    }
                    else if (pE->getId() == Id::dog) {
                        setScore(getScore() + 250);
                    }
                    else if (pE->getId() == Id::punk) {
                        dynamic_cast<Concurrent::BossThread*>(pE)->stop();
                        dynamic_cast<Concurrent::BossThread*>(pE)->join();
                        setScore(getScore() + 1000);
                        setIsStageDone(true);
                    }
                }
                entityList->removeAndDeleteEntity(pE);
            }
        }
    }

}

void Stage::save() {

    std::ofstream player1SavesFile (PLAYER1_SAVE_PATH, std::ios::out);
    std::ofstream player2SavesFile (PLAYER2_SAVE_PATH, std::ios::out);
    std::ofstream obstacleSavesFile (OBSTACLE_SAVE_PATH, std::ios::out);
    std::ofstream projectilesSavesFile (PROJECTILE_SAVE_PATH, std::ios::out);
    std::ofstream enemySavesFile (ENEMY_SAVE_PATH, std::ios::out);
    std::ofstream stageSavesFile (STAGE_SAVE_PATH, std::ios::out);


    if(!player1SavesFile){
        std::cerr << "Could not open Player1 Saves file" << std::endl;
        exit(1);
    }
    if(!player2SavesFile){
        std::cerr << "Could not open Player2 Saves file" << std::endl;
        exit(1);
    }
    if(!obstacleSavesFile){
        std::cerr << "Could not open Obstacle Saves file" << std::endl;
        exit(1);
    }
    if(!projectilesSavesFile){
        std::cerr << "Could not open Projectile Saves file" << std::endl;
        exit(1);
    }
    if(!enemySavesFile){
        std::cerr << "Could not open Enemy Saves file" << std::endl;
        exit(1);
    }
    if(!stageSavesFile){
        std::cerr << "Could not open Stage Saves file" << std::endl;
        exit(1);
    }

    std::string num =std::to_string(getStageNumber());

    if (player2) {
        stageSavesFile <<
           num << " " <<
           getScore() << " " << "1";
    }
    else {
        stageSavesFile <<
           num << " " <<
           getScore() << " " << "0";
    }

    for (int i = 0; i < entityList->getSize(); i++){

        if ((entityList->operator[](i))->getId() == Id::player1)
            (entityList->operator[](i)->saveEntity(player1SavesFile));
        else if ((entityList->operator[](i))->getId() == Id::player2)
            (entityList->operator[](i)->saveEntity(player2SavesFile));
        else if (((int)(entityList->operator[](i))->getId()) >= 10 && ((int)(entityList->operator[](i))->getId()) <= 30)
            (entityList->operator[](i)->saveEntity(enemySavesFile));
        else if ((entityList->operator[](i))->getId() == Id::projectile || (entityList->operator[](i))->getId() == Id::smoke)
            (entityList->operator[](i)->saveEntity(projectilesSavesFile));
        else if (((int)(entityList->operator[](i))->getId()) >= 300 && ((int)(entityList->operator[](i))->getId()) <= 600)
            (entityList->operator[](i)->saveEntity(obstacleSavesFile));
    }
    player1SavesFile.close();
    player2SavesFile.close();
    enemySavesFile.close();
    obstacleSavesFile.close();
    projectilesSavesFile.close();
    stageSavesFile.close();

}

int Stage::getStageNumber() {
    if (background->getId() == Id::background2)
        return 2;
    else
        return 1;
}
