#include "Ent.h"

Ent::Ent(const Id::ids i, Coordinates::Vector<float> size, Coordinates::Vector<float> pos): id(i) {
    std::string path;
    Coordinates::Vector<unsigned int> imageCnt = Coordinates::Vector<unsigned int>(6, 8);

    /*
    if (id == Id::player1)
        path = "PLAYER1_TEXTURE_PATH";
    else if ()
    */

    switch (id) {
        case Id::player1:
            path = PLAYER1_TEXTURE_PATH;
            break;
        case Id::player2:
            path = PLAYER2_TEXTURE_PATH;
            break;
        case Id::background1:
            imageCnt.setX(1);
            imageCnt.setY(1);
            path = BACKGROUND1_TEXTURE_PATH;
            break;
        case Id::background2:
            imageCnt.setX(1);
            imageCnt.setY(1);
            path = BACKGROUND2_TEXTURE_PATH;
            break;
        case Id::tile1:
            imageCnt.setX(1);
            imageCnt.setY(1);
            path = TILE_TEXTURE_PATH;
            break;
        case Id::enemy1:
            imageCntX = 6;
            imageCntY = 3;
            path = ENEMY_TEXTURE_PATH;
            break;
        default:
            path = TILE_TEXTURE_PATH;
            break;
    }


    sprite = new Animation(path, size, imageCnt, 0.2f);
    sprite->changePosition(pos);
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

