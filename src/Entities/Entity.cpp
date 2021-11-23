#include "Entities/Entity.h"

using namespace Entities;

Entity::Entity(Id::ids i, Coordinates::Vector<float> hit, Coordinates::Vector<float> pos):
Ent(i), hitBox(hit), position(pos), isAlive(true) {

}

Entity::~Entity() {

}

void Entity::setPosition(Coordinates::Vector<float> pos) {
    position = pos;
}

void Entity::setDamage(unsigned int dmg) {
    if (dmg < 0)
        dmg = 0;
    damage = dmg;
}

unsigned int Entity::getDamage() const {
    return damage;
}

void Entity::eliminate() {
    isAlive = false;
}

bool Entity::getIsAlive() {
    return isAlive;
}

const Coordinates::Vector<float> Entity::getPosition() const {
    return position;
}

const Coordinates::Vector<float> Entity::getHitBox() const {
    return hitBox;
}

<<<<<<< HEAD
void Entity::save() {
    //Serializer.serialize(this)
    //
}

=======
void Entity::saveEntityInfo(std::ofstream& out) const {
    out <<  (int)getId()           << " " <<
            getHitBox().getX()     << " " <<
            getHitBox().getY()     << " " <<
            getPosition().getX()   << " " <<
            getPosition().getX()   << " " <<
            getDamage()            << " ";
}

const bool Entity::restoreEntityInfo(std::ifstream& in) {
    int i;
    float positionX, positionY, hitBoxX, hitBoxY;

    try {
        in >>
            i >>
            hitBoxX >>
            hitBoxY >>
            positionX >>
            positionY >>
            damage;
    }
    catch(std::invalid_argument e){
        std::cerr << "Error: Could not load entity info!" << std::endl;
        return false;
    }

    Id::ids identifier = static_cast<Id::ids>(i);
    hitBox.setX(hitBoxX);
    hitBox.setY(hitBoxY);
    position.setX(positionX);
    position.setY(positionY);
}

void Entity::saveEntity(std::ofstream& out) const {

}

void Entity::restoreEntity(std::ifstream& in) {

}
>>>>>>> 765ea23d113b3e3f487d8ce05effd29b43c74d28
