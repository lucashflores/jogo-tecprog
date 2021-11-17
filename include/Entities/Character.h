#pragma once

#include "Entity.h"

namespace Entities {

    class Character: public Entity {
    protected:
        Coordinates::Vector<float> velocity;
        int life;
        int damage;
        bool isFacingLeft;
        bool isWalking;
        bool isOnGround;
        bool isAttacking;
    public:
        Character(Id::ids i, unsigned int l, unsigned int d, Coordinates::Vector<float> hit, Coordinates::Vector<float> pos);

        virtual ~Character();

        void setAnimation(Animation* pAnimation);

        void setVelocity(Coordinates::Vector<float> v);

        Coordinates::Vector<float> getVelocity() const;

        void setLife(unsigned int l);

        int getLife() const;

        void setDamage(unsigned int d);

        int getDamage() const;

        void eliminate();

        void setIsFacingLeft(bool facingLeft);

        void setIsWalking(bool walking);

        void setIsOnGround(bool isOnGround);

        void setIsAttacking(bool attacking);

        virtual void attack(Character* pChar) = 0;

        virtual void collide(Entity* pE, Coordinates::Vector<float> collision)=0;

        virtual void update(float dt) = 0;
    };
}