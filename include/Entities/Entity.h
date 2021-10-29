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
        Entity(sf::RectangleShape shape, sf::Texture *text, sf::Vector2f pos, sf::Vector2f v);

        virtual ~Entity();

        sf::Vector2f getPosition();

        void setGraphicManager(Managers::GraphicManager *pGM);

        void setEventManager(Managers::EventManager *pEM);
    };

}