#pragma once

#include "Entity.h"

namespace Entities {

    class Character: public Entity {
    protected:
        Coordinates::VectorFloat velocity;
        unsigned char life;
        unsigned char damage;
        bool isFacingLeft;
        bool isWalking;
    public:
        Character(Id::ids i, unsigned int l, unsigned int d, Coordinates::VectorFloat size, Coordinates::VectorFloat hit, Coordinates::VectorFloat pos);

        virtual ~Character();

        void setAnimation(Animation* pAnimation);

        void setVelocity(Coordinates::VectorFloat v);

        Coordinates::VectorFloat getVelocity() const;

        void setLife(unsigned int l);

        unsigned int getLife() const;

        void setDamage(unsigned int d);

        unsigned int getDamage() const;

        void setIsFacingLeft(bool facingLeft);

        void setIsWalking(bool walking);

        virtual void collide(Entity* pE)=0;

        virtual void update(float dt) = 0;
    };
}