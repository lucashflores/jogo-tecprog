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

    //Is facing left?
    if (pInputManager->isKeyDown(controls.at("left")) && !pInputManager->isKeyDown(controls.at("right")))
        player->setIsFacingLeft(true);
    else if (pInputManager->isKeyDown(controls.at("right")) && !pInputManager->isKeyDown(controls.at("left")))
        player->setIsFacingLeft(false);
    else {
        if (pInputManager->wasKeyPressed(controls.at("left")))
            player->setIsFacingLeft(true);
        else
            player->setIsFacingLeft(false);
    }

    //Is walking?
    if (pInputManager->isKeyDown(controls.at("left")) || pInputManager->isKeyDown(controls.at("right"))) {
        player->setIsWalking(true);
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
