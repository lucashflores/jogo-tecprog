#include <iostream>
#include <SFML/Graphics.hpp>
#include "GraphicManager.h"



int main()
{
    GraphicManager* instance = GraphicManager::getInstance();
    sf::RenderWindow* window = instance->getWindow();

    sf::RectangleShape sprite(sf::Vector2f (100.f, 100.f));
    sf::Texture* texture = instance->loadTexture("d:/repositories/jogo-tecprog/assets/biker.png");
    sprite.setTexture(texture);
    sf::IntRect rectSprite(0, 0, 48 ,48);
    sprite.setTextureRect(rectSprite);

    sf::Texture* backgroundtex = instance->loadTexture("d:/repositories/jogo-tecprog/assets/background.png");
    sf::RectangleShape background(sf::Vector2f(1280.f, 720.f));
    background.setTexture(backgroundtex);

    float velocity = 0.2f;

    while (instance->isWindowOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                instance->closeWindow();


        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            sprite.move(sf::Vector2f(0.f, velocity));
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            sprite.move(sf::Vector2f(0.f, -velocity));
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            sprite.move(sf::Vector2f(-velocity, 0.f));
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            sprite.move(sf::Vector2f(velocity, 0.f));


        instance->centerView(sprite.getPosition());
        instance->clear();
        instance->render(&background);
        instance->render(&sprite);
        instance->display();

    }


}
