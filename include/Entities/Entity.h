#pragma once

#include "Managers/GraphicManager.h"
#include "Managers/EventManager.h"
#include "Id.h"



namespace Entities {

    class EntityList;

    class Entity {
    protected:
        Id::ids id;
        Managers::GraphicManager *pGraphicM;
        Managers::EventManager *pEventM;
        sf::RectangleShape body;
        sf::Texture *texture;
        sf::Vector2f position;
        EntityList* pEntityList;
    public:
        Entity(Id::ids i, sf::RectangleShape shape, sf::Vector2f pos);

        virtual ~Entity();

        Id::ids getId();

        void setPosition(sf::Vector2f pos);

        sf::Vector2f getPosition() const;

        void setTexture(sf::Texture* text);

        void setTextureRect(sf::IntRect rect);

        void setGraphicManager(Managers::GraphicManager *pGM);

        virtual sf::FloatRect getHitBox();

        virtual void collide(Entity* pE) = 0;

        void move(sf::Vector2f p);

        void render();
    };

}