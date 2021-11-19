#include <iostream>
#include <Entities/Enemy.h>
#include <Entities/SmokerEnemy.h>
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


    float dt;
    sf::Clock clock;

    while (instance->isWindowOpen()) {

        sf::Event event;

        eventInstance->PollEvents(event);

        dt = clock.restart().asSeconds();

        if (dt > 0.0167)
            dt = 0.0167;


        instance->clear();
        background->update(player->getPosition());
        pCollisionManager->collideAllEntities();
        background->render();
        entityList->renderAllEntities();
        entityList->updateAllEntities(dt);
        instance->display();

    }

    return 0;

}
