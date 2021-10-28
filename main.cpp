#include <iostream>
#include <SFML/Graphics.hpp>
#include "Managers/GraphicManager.h"
#include "Managers/EventManager.h"
#include "Animation.h"
#include "Managers/InputManager.h"

int main()
{

    Managers::GraphicManager* instance = Managers::GraphicManager::getInstance();
    sf::RenderWindow* window = instance->getWindow();

    Managers::EventManager* eventInstance = Managers::EventManager::getInstance();
    eventInstance->setGraphicManagerInstance(instance);

    Managers::InputManager* inputInstance = Managers::InputManager::getInstance();
    eventInstance->setInputManagerInstance(inputInstance);

    sf::RectangleShape sprite(sf::Vector2f (100.f, 100.f));
    sf::Texture* player = instance->loadTexture("./assets/biker.png");
    sprite.setTexture(player);
    sf::IntRect rectSprite(0, 0, 48 ,48);
    sprite.setTextureRect(rectSprite);

    sf::Texture* player_left = instance->loadTexture("./assets/biker_idle_left.png");
    sf::IntRect rectSpriteLeft(144, 0, 48, 48);

    sf::Texture* playerRun = instance->loadTexture("./assets/biker_running.png");
    sf::Texture* playerRunLeft = instance->loadTexture("./assets/biker_run_left.png");
    Animation* animation = new Animation(playerRun, sf::Vector2u(6, 1), 0.2f);
    Animation* animationl = new Animation(playerRun, sf::Vector2u(6, 1), 0.2f);

    sf::Texture* backgroundtex = instance->loadTexture("./assets/background.png");
    sf::RectangleShape background(sf::Vector2f(1280.f, 720.f));
    background.setTexture(backgroundtex);

    float dt;
    sf::Clock clock;

    while (instance->isWindowOpen())
    {

        sf::Event event;

        eventInstance->PollEvents(event);


        float velocity = SPEED;
        if (inputInstance->isKeyDown(sf::Keyboard::S))
            sprite.move(sf::Vector2f(0.f, velocity));
        else if (inputInstance->isKeyDown(sf::Keyboard::W))
            sprite.move(sf::Vector2f(0.f, -velocity));
        else if (inputInstance->isKeyDown(sf::Keyboard::A))
            sprite.move(sf::Vector2f(-velocity, 0.f));
        else if (inputInstance->isKeyDown(sf::Keyboard::D))
            sprite.move(sf::Vector2f(velocity, 0.f));


        dt = clock.restart().asSeconds();
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




        instance->clear();
        instance->centerView(sprite.getPosition());
        //background.setPosition(sprite.getPosition() - sf::Vector2f((window->getSize().x)/2, (window->getSize().y)/2));
        instance->render(&background);
        instance->render(&sprite);
        instance->display();

    }


}
