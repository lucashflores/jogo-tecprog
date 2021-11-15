#pragma once

#include "Entity.h"

namespace Entities {

    class Character: public Entity {
    protected:
        Coordinates::Vector<float> velocity;
        unsigned char life;
        unsigned char damage;
        bool isFacingLeft;
        bool isWalking;
        bool isOnGround;
    public:
        Character(Id::ids i, unsigned int l, unsigned int d, Coordinates::Vector<float> size, Coordinates::Vector<float> hit, Coordinates::Vector<float> pos);

        virtual ~Character();

        void setAnimation(Animation* pAnimation);

        void setVelocity(Coordinates::Vector<float> v);

        Coordinates::Vector<float> getVelocity() const;

        void setLife(unsigned int l);

        unsigned int getLife() const;

        void setDamage(unsigned int d);

        unsigned int getDamage() const;

        void setIsFacingLeft(bool facingLeft);

        void setIsWalking(bool walking);

        void setIsOnGround(bool isOnGround);

        virtual void collide(Entity* pE, Coordinates::Vector<float> collision)=0;

        virtual void update(float dt) = 0;
    };
}