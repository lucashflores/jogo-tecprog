#pragma once

#include "Entity.h"

namespace Entities {

    class Character: public Entity {
    protected:
        Animation *animation;
        Animation *animationl;
        sf::Vector2f velocity;
        unsigned char life;
        unsigned char damage;
    public:
        Character(unsigned char l, unsigned char d, sf::Vector2f v);
        virtual ~Character();
        void setAnimation(Animation* pAnimation);
        void setLife(unsigned char l);
        unsigned char getLife() const;
        void setDamage(unsigned char d);
        unsigned char getDamage() const;

    };
}