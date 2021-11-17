#include "Ent.h"

Ent::Ent(const Id::ids i, Coordinates::Vector<float> size, Coordinates::Vector<float> pos): id(i) {
}

Ent::~Ent() {
    if (sprite)
        delete sprite;
}

const Id::ids Ent::getId() const{
    return id;
}

void Ent::render() {
    sprite->render();
}

