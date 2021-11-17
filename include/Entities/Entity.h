#pragma once


#include "Ent.h"
#include "Defines/stdafx.h"

namespace Entities {


    class Entity: public Ent {
    protected:

        Coordinates::Vector<float> position;
        Coordinates::Vector<float> hitBox;

    public:
        Entity(Id::ids i, Coordinates::Vector<float> hit, Coordinates::Vector<float> pos);

        virtual ~Entity();

        void setPosition(Coordinates::Vector<float> pos);

        const Coordinates::Vector<float> getPosition() const;

        const Coordinates::Vector<float> getHitBox() const;

        virtual void collide(Entity* pE, Coordinates::Vector<float> collision) = 0;

        virtual void update(float dt) = 0;
    };

}