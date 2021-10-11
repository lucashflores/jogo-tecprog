#include "Entities.h"

Entities::Entities(float v, unsigned char l) {
    if (v > 0)
        velocity = v;
    if (l > 0)
        life = l;
}

Entities::~Entities() {

}

void Entities::move() {

}