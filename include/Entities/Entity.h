#pragma once

#include "Managers/GraphicManager.h"
#include "Managers/EventManager.h"
#include "Id.h"
#include "Coordinates/VectorFloat.h"



namespace Entities {

    class EntityList;

    class Entity {
    protected:
        Id::ids id;
        Animation* sprite;
        Managers::GraphicManager *pGraphicM;
        sf::RectangleShape body;
        sf::Texture *texture;
        Coordinates::VectorFloat position;
        EntityList* pEntityList;
        Coordinates::VectorFloat hitBox;
    public:
        Entity(Id::ids i, sf::RectangleShape shape, Coordinates::VectorFloat hit, Coordinates::VectorFloat pos);

        virtual ~Entity();

        Id::ids getId();

        void setPosition(sf::Vector2f pos);

        sf::Vector2f getPosition() const;

        void setTexture(sf::Texture* text);

        void setTextureRect(sf::IntRect rect);

        Coordinates::VectorFloat getHitBox();

        virtual void collide(Entity* pE) = 0;

        void move(Coordinates::VectorFloat pos);

        void render();
    };

}