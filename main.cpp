#include <iostream>
#include "Managers/GraphicManager.h"
#include "Managers/EventManager.h"
#include "Animation.h"
#include "Entities/Entity.h"
#include "Entities/Player.h"

int main() {

    Managers::GraphicManager *instance = Managers::GraphicManager::getInstance();
    sf::RenderWindow* window = instance->getWindow();

    Managers::EventManager *eventInstance = Managers::EventManager::getInstance();
    eventInstance->setGraphicManagerInstance(instance);

    Managers::InputManager *inputInstance = Managers::InputManager::getInstance();
    eventInstance->setInputManagerInstance(inputInstance);

    Entities::Player* player = new Entities::Player(sf::RectangleShape(sf::Vector2f(100.f, 100.f)),
                                instance->loadTexture(PLAYER1_IDLE_TEXTURE_PATH),
                                sf::Vector2f(0, 0), sf::Vector2f(SPEED, 0));
    player->setGraphicManager(instance);
    player->setEventManager(eventInstance);
    player->setInputManager(inputInstance);

    sf::Texture *backgroundtex = instance->loadTexture("./assets/background.png");
    sf::RectangleShape background(sf::Vector2f(1280.f, 720.f));
    background.setTexture(backgroundtex);

    float dt;
    sf::Clock clock;

    while (instance->isWindowOpen()) {

        sf::Event event;

        eventInstance->PollEvents(event);


        dt = clock.restart().asSeconds();

        /*
        if (inputInstance->anyKeyPressed()) {
            animation->animationUpdate(dt);
            if (inputInstance->getKeyPressed() == sf::Keyboard::A) {
                sprite.setTexture(playerRunLeft);
                sprite.setTextureRect(animation->uvRect);
            }
            else {
                sprite.setTexture(playerRun);
                sprite.setTextureRect(animation->uvRect);
            }

        }

        else {
            if (inputInstance->getKeyPressed() == sf::Keyboard::A) {
                sprite.setTexture(player_left);
                sprite.setTextureRect(rectSprite);
            }

            else {
                sprite.setTexture(player);
                sprite.setTextureRect(rectSpriteLeft);
            }
        }
        */

        instance->clear();
        //background.setPosition(player->getPosition() - sf::Vector2f((window->getSize().x)/2, (window->getSize().y)/2));
        instance->render(&background);
        player->update(dt);
        instance->display();

    }

    return 0;

}
