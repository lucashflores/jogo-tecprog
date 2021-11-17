#include <iostream>
#include <Entities/Enemy.h>
#include <Entities/SmokerEnemy.h>
#include "Managers/GraphicManager.h"
#include "Managers/EventManager.h"
#include "Animation.h"
#include "Entities/Entity.h"
#include "Entities/Player.h"
#include "Entities/Obstacle.h"
#include "Stages/TileMaker.h"
#include "Stages/ObstacleBuilder.h"
#include "EntityList.h"
#include "Managers/CollisionManager.h"
#include "Entities/Background.h"
#include "Id.h"
#include "Coordinates/VectorTemplate.h"
#include "Stages/InstructionsTranslator.h"

int main() {

    Managers::GraphicManager *instance = Managers::GraphicManager::getInstance();

    Managers::EventManager *eventInstance = Managers::EventManager::getInstance();

    Managers::CollisionManager* pCollisionManager = Managers::CollisionManager::getInstance();

    EntityList* entityList = new EntityList();

    pCollisionManager->setEntityList(entityList);

    Entities::Background* background = new Entities::Background(Id::background1);

    Entities::Player* player = new Entities::Player(true);
    entityList->addEntity(static_cast<Entities::Entity*>(player));

    Entities::SmokerEnemy* smoker = new Entities::SmokerEnemy(Coordinates::Vector<float>(0.f, 0.f));
    smoker->setPlayer(player);
    entityList->addEntity(static_cast<Entities::Entity*>(smoker));

    Stages::ObstacleBuilder* obstacleBuilder = new Stages::ObstacleBuilder(entityList);
    obstacleBuilder->buildBarrel(Coordinates::Vector<float>(96.f, 121.f));
    obstacleBuilder->buildOilTile(Coordinates::Vector<float>(576.f, 100.f));
    obstacleBuilder->buildFire(Coordinates::Vector<float>(64.f, 118.f));
    obstacleBuilder->buildSign(Coordinates::Vector<float>(128.f, 118.f));



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
