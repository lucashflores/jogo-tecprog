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
            path = TILE1_TEXTURE_PATH;
            break;
        case Id::tile2:
            imageCnt.setX(1);
            imageCnt.setY(1);
            path = TILE2_TEXTURE_PATH;
            break;
        case Id::tile3:
            imageCnt.setX(1);
            imageCnt.setY(1);
            path = TILE3_TEXTURE_PATH;
            break;
        case Id::tile4:
            imageCnt.setX(1);
            imageCnt.setY(1);
            path = TILE4_TEXTURE_PATH;
            break;
        case Id::enemy1:
            imageCnt.setX(6);
            imageCnt.setY(3);
            path = ENEMY1_TEXTURE_PATH;
            break;
        case Id::enemy2:
            imageCnt.setX(6);
            imageCnt.setY(5);
            path = ENEMY2_TEXTURE_PATH;
            break;
        default:
            path = TILE1_TEXTURE_PATH;
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

