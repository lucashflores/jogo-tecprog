#include <iostream>
#include <Entities/Enemy.h>
#include <Entities/SmokerEnemy.h>
#include <Entities/DogEnemy.h>
#include "Managers/GraphicManager.h"
#include "Managers/EventManager.h"
#include "Animation.h"
#include "Entities/Entity.h"
#include "Entities/Player.h"
#include "Entities/Obstacle.h"
#include "Stages/PlatformMaker.h"
#include "EntityList.h"
#include "Managers/CollisionManager.h"
#include "Entities/Background.h"
#include "Id.h"
#include "Coordinates/VectorTemplate.h"

int main() {

    Managers::GraphicManager *instance = Managers::GraphicManager::getInstance();

    Managers::EventManager *eventInstance = Managers::EventManager::getInstance();

    Managers::CollisionManager* pCollisionManager = Managers::CollisionManager::getInstance();

    EntityList* entityList = new EntityList();

    pCollisionManager->setEntityList(entityList);

    Entities::Background* background = new Entities::Background(Id::background1);


    Entities::Player* player = new Entities::Player(true);
    entityList->addEntity(player);


    Entities::SmokerEnemy* smoker = new Entities::SmokerEnemy(Coordinates::Vector<float>(0.f, 0.f));
    smoker->setPlayer(player);
    entityList->addEntity(smoker);

    Entities::DogEnemy* dog1 = new Entities::DogEnemy(Coordinates::Vector<float>(500.f, 0.f));
    dog1->setPlayer(player);
    entityList->addEntity(dog1);


    Stages::PlatformMaker* platformMaker = new Stages::PlatformMaker(entityList);
    platformMaker->makePlatform(Id::tile2, Coordinates::Vector<float>(0.f, 150.f), 10);
    platformMaker->makePlatform(Id::tile1 ,Coordinates::Vector<float>(320.f, 100.f), 40);

    float dt;
    sf::Clock clock;

    while (instance->isWindowOpen()) {

        sf::Event event;

        eventInstance->PollEvents(event);

        dt = clock.restart().asSeconds();

        if (dt > 0.0167)
            dt = 0.0167;


        instance->clear();
        entityList->updateAllEntities(dt);
        background->update(player->getPosition());
        pCollisionManager->collideAllEntities();
        background->render();
        entityList->renderAllEntities();
        instance->display();

    }

    return 0;

}
