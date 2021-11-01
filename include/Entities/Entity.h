#pragma once

#include "Managers/GraphicManager.h"
#include "Managers/EventManager.h"
#include "Animation.h"

namespace Entities {

    class Entity {
    protected:
        Managers::GraphicManager *pGraphicM;
        Managers::EventManager *pEventM;
        sf::RectangleShape body;
        sf::Texture *texture;
        sf::Vector2f position;
    public:
        Entity(sf::RectangleShape shape, sf::Vector2f pos);

        virtual ~Entity();

        sf::Vector2f getPosition() const;

        void setTexture(sf::Texture* text);

        void setGraphicManager(Managers::GraphicManager *pGM);

    };

}