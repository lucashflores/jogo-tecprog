#pragma once


#include "Coordinates/VectorFloat.h"
#include "Ent.h"



namespace Entities {

    class EntityList;

    class Entity: public Ent {
    protected:
        Coordinates::VectorFloat position;
        EntityList* pEntityList;
        Coordinates::VectorFloat hitBox;
    public:
        Entity(Id::ids i, Coordinates::VectorFloat size, Coordinates::VectorFloat hit, Coordinates::VectorFloat pos);

        virtual ~Entity();

        void setPosition(Coordinates::VectorFloat pos);

        const Coordinates::VectorFloat getPosition() const;

        const Coordinates::VectorFloat getHitBox() const;

        virtual void collide(Entity* pE) = 0;

        virtual void update(float dt) = 0;
    };

}