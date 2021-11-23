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
#include "Stages/TileFactory.h"
#include "Stages/ObstacleFactory.h"
#include "EntityList.h"
#include "Managers/CollisionManager.h"
#include "Entities/Background.h"
#include "Id.h"
#include "Coordinates/MathVector.h"

int main() {

    Managers::GraphicManager *instance = Managers::GraphicManager::getInstance();

    Managers::EventManager *eventInstance = Managers::EventManager::getInstance();

    Managers::CollisionManager* pCollisionManager = Managers::CollisionManager::getInstance();

    EntityList* entityList = new EntityList();

    pCollisionManager->setEntityList(entityList);

    Entities::Background* background = new Entities::Background(Id::background1);


    Entities::SmokerEnemy* smoker = new Entities::SmokerEnemy(Coordinates::Vector<float>(700.f, 0.f));
    entityList->addEntity(smoker);

    Entities::DogEnemy* dog1 = new Entities::DogEnemy(Coordinates::Vector<float>(900.f, 0.f));
    entityList->addEntity(dog1);

    Entities::PunkBoss* boss = new Entities::PunkBoss(Coordinates::Vector<float>(100.f, 0.f));
    entityList->addEntity(boss);
    boss->setEntityList(entityList);

    Entities::Player* player = new Entities::Player(true);
    entityList->addEntity(player);

    Entities::Projectile* fireball = new Entities::Projectile(Coordinates::Vector<float>(0.f, 0.f), false);
    entityList->addEntity(fireball);

    smoker->setPlayer(player);
    dog1->setPlayer(player);
    boss->setPlayer(player);

    Stages::TileFactory* platformMaker = new Stages::TileFactory(1, entityList);
    platformMaker->makePlatform(Coordinates::Vector<float>(0.f, 150.f), 25);
    platformMaker->makePlatform(Coordinates::Vector<float>(320.f, 66.f), 40);
    //platformMaker->makePlatform(Coordinates::Vector<float>(315.f, 198.f), 50);
    //platformMaker->makePlatform(Coordinates::Vector<float>(315.f, 280.f), 50);

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

