#include "Ent.h"

Ent::Ent(const Id::ids i, Coordinates::VectorFloat size, Coordinates::VectorFloat pos): id(i) {
    std::string path;
    int imageCntX = 6;
    int imageCntY = 8;

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
            imageCntX = 1;
            imageCntY = 1;
            path = BACKGROUND1_TEXTURE_PATH;
            break;
        case Id::background2:
            imageCntX = 1;
            imageCntY = 1;
            path = BACKGROUND2_TEXTURE_PATH;
            break;
        case Id::tile1:
            imageCntX = 1;
            imageCntY = 1;
            path = TILE_TEXTURE_PATH;
            break;
        default:
            path = TILE_TEXTURE_PATH;
            break;
    }


    sprite = new Animation(path, size, sf::Vector2u(imageCntX, imageCntY), 0.2f);
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

