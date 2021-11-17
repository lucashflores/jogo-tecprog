#pragma once

#include "TEXTURE_PATHS.h"
#include "Animation.h"
#include "Id.h"

class Ent {
protected:

    const Id::ids id;
    Animation* sprite;

public:
    Ent(Id::ids i);
    virtual ~Ent();
    const Id::ids getId() const;

    virtual void initializeSprite() = 0;
    void render();
};