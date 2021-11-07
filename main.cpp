#include <iostream>
#include "Managers/GraphicManager.h"
#include "Managers/EventManager.h"
#include "Animation.h"
#include "Entities/Entity.h"
#include "Entities/Player.h"
#include "Entities/Obstacle.h"
#include "Stages/PlatformMaker.h"
#include "Entities/EntityList.h"
#include "Managers/CollisionManager.h"
#include "Entities/Background.h"
#include "Id.h"

int main() {

    Managers::GraphicManager *instance = Managers::GraphicManager::getInstance();

    Managers::EventManager *eventInstance = Managers::EventManager::getInstance();
    eventInstance->setGraphicManagerInstance(instance);

    Managers::InputManager *inputInstance = Managers::InputManager::getInstance();
    eventInstance->setInputManagerInstance(inputInstance);

    Entities::EntityList* pEntityList = Entities::EntityList::getInstance();

    Managers::CollisionManager* pCollisionManager = Managers::CollisionManager::getInstance();

    Entities::Background* background = new Entities::Background(Id::background1);

    Entities::Player* player = new Entities::Player(true);

    Stages::PlatformMaker* platformMaker = new Stages::PlatformMaker();
    platformMaker->makePlatform(sf::Vector2f(0.f, 100.f), 10);
    platformMaker->makePlatform(sf::Vector2f(400.f, 150.f), 8);


    float dt;
    sf::Clock clock;

    while (instance->isWindowOpen()) {

        sf::Event event;

        eventInstance->PollEvents(event);

        dt = clock.restart().asSeconds();

        if (dt > 0.0167)
            dt = 0.0167;


        instance->clear();
        player->update(dt);
        background->update(player->getPosition());
        pCollisionManager->collideAllEntities();
        pEntityList->renderAllEntities();
        instance->display();

    }

    return 0;

}
