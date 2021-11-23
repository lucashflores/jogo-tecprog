#include <iostream>
#include <Entities/Enemy.h>
#include <Entities/SmokerEnemy.h>
#include <Entities/DogEnemy.h>
#include "Entities/PunkBoss.h"
#include "Entities/Projectile.h"
#include "Managers/GraphicManager.h"
#include "Managers/EventManager.h"
#include "Animation.h"
#include "Entities/Entity.h"
#include "Entities/Player.h"
#include "Entities/Obstacle.h"
#include "Stages/TileInstructionsReader.h"
#include "Stages/ObstacleInstructionsReader.h"
#include "Stages/EnemyInstructionsReader.h"
#include "EntityList.h"
#include "Managers/CollisionManager.h"
#include "Background.h"
#include "Id.h"
#include "Coordinates/MathVector.h"

int main() {
    srand(time(NULL));

    Managers::GraphicManager *instance = Managers::GraphicManager::getInstance();

    Managers::EventManager *eventInstance = Managers::EventManager::getInstance();

    Managers::CollisionManager* pCollisionManager = Managers::CollisionManager::getInstance();

    EntityList* entityList = new EntityList();

    pCollisionManager->setEntityList(entityList);

    Background* background = new Background(Id::background1);


    /*
    Entities::SmokerEnemy* smoker = new Entities::SmokerEnemy(Coordinates::Vector<float>(700.f, 0.f));
    entityList->addEntity(smoker);


    Entities::DogEnemy* dog1 = new Entities::DogEnemy(Coordinates::Vector<float>(900.f, 0.f));
    entityList->addEntity(dog1);


    Entities::PunkBoss* boss = new Entities::PunkBoss(Coordinates::Vector<float>(100.f, 0.f));
    entityList->addEntity(boss);
    boss->setEntityList(entityList);
    */


    Entities::Player* player = new Entities::Player(true);
    entityList->addEntity(player);

    /*
    Entities::Player* player2 = new Entities::Player(false);
    entityList->addEntity(player2);
    */


    /*
    Entities::Projectile* fireball = new Entities::Projectile(Coordinates::Vector<float>(0.f, 0.f), false);
    entityList->addEntity(fireball);
    */

    //smoker->setPlayer(player);
    //dog1->setPlayer(player);
    //boss->setPlayer(player);



    Stages::TileInstructionsReader* tileFactory = new Stages::TileInstructionsReader(1, entityList);
    tileFactory->readInstructions("../assets/stages/stage1/tileInstructions.txt");

    Stages::ObstacleInstructionsReader* obstacleFactory = new Stages::ObstacleInstructionsReader(entityList);
    obstacleFactory->readInstructions("../assets/stages/stage1/obstacleInstructions.txt");

    Stages::EnemyInstructionsReader* enemyInstructionsReader = new Stages::EnemyInstructionsReader(entityList);
    enemyInstructionsReader->readInstructions("../assets/stages/stage1/enemyInstructions.txt");


    float dt;
    sf::Clock clock;

    while (instance->isWindowOpen()) {

        sf::Event event;

        eventInstance->PollEvents(event);

        dt = clock.restart().asSeconds();

        if (dt > 0.0100)
            dt = 0.0100;


        entityList->removeNeutralizedEntities();
        entityList->updateAllEntities(dt);
        background->update(player->getPosition());
        pCollisionManager->collideAllEntities();
        instance->clear();
        background->render();
        entityList->renderAllEntities();
        instance->display();
    }

    return 0;

}
