#include "PlayerControl.h"
#include "Entities/Player.h"

PlayerControl::PlayerControl(Entities::Player* p): controls() {
    pInputManager = Managers::InputManager::getInstance();
    if (p)
        player = p;
    if (player->getId() == Id::player1) {
        controls["left"] = "A";
        controls["right"] = "D";
        controls["down"] = "S";
        controls["jump"] = "W";
    }
}

PlayerControl::~PlayerControl() {
    pInputManager = NULL;
}

void PlayerControl::notify() {
    player->setIsWalking(true);

    //Is walking?
    if (pInputManager->isKeyDown(controls.at("left")) || pInputManager->isKeyDown(controls.at("right"))) {
        if (pInputManager->isKeyDown(controls.at("left")))
            player->walk(true);
        else
            player->walk(false);
    }

    //Jump
    else if (pInputManager->isKeyDown(controls.at("down")))
        player->down();

    else if (pInputManager->isKeyDown(controls.at("jump")))
        player->jump();
    else
        player->setIsWalking(false);


}
