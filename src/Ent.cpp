#include "Ent.h"

Ent::Ent(const Id::ids i): id(i) { }

Ent::~Ent() {
    if(sprite)
        delete sprite;
}

const Id::ids Ent::getId() const{
    return id;
}

void Ent::render() {
    sprite->render();
}

