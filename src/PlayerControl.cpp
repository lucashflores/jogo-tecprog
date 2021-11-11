#include "PlayerControl.h"
#include "Entities/Player.h"

PlayerControl::PlayerControl(Entities::Player* p): controls() {
    pInputManager = Managers::InputManager::getInstance();
    if (p)
        player = p;
    if (player->getId() == Id::player1) {
        controls["left"] = "A";
        controls["right"] = "D";
        controls["jump"] = "W";
    }
}

PlayerControl::~PlayerControl() {
    pInputManager = NULL;
}

void PlayerControl::notify() {

    //Is walking?
    if (pInputManager->isKeyDown(controls.at("left")) || pInputManager->isKeyDown(controls.at("right"))) {
        if (pInputManager->isKeyDown(controls.at("left")))
            player->walk(true);
        else
            player->walk(false);
    }
    else
        player->setIsWalking(false);

    //Jump
    if (pInputManager->wasKeyPressed(controls.at("jump")))
        player->jump();

}
