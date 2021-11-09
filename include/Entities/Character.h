#pragma once

#include "Entity.h"
#include "Animation.h"

namespace Entities {

    class Character: public Entity {
    protected:
        Animation *animation;
        sf::Vector2f velocity;
        unsigned char life;
        unsigned char damage;
        bool isFacingLeft;
        bool isWalking;
    public:
        Character(Id::ids id, unsigned char l, unsigned char d, sf::Vector2f v);

        virtual ~Character();

        void setAnimation(Animation* pAnimation);

        void setVelocity(sf::Vector2f v);

        sf::Vector2f getVelocity() const;

        void setLife(unsigned char l);

        unsigned char getLife() const;

        void setDamage(unsigned char d);

        unsigned char getDamage() const;

        void setIsFacingLeft(bool facingLeft);

        void setIsWalking(bool walking);

        virtual void collide(Entity* pE)=0;

        virtual void update(float dt) = 0;
    };
}