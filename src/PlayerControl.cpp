#include "PlayerControl.h"
#include "Entities/Player.h"

PlayerControl::PlayerControl(Entities::Player* p): controls() {
    pInputManager = Managers::InputManager::getInstance();
    if (p)
        player = p;
    if (player->getId() == Id::player1) {
        controls["left"] = PLAYER1_LEFT;
        controls["right"] = PLAYER1_RIGHT;
        controls["jump"] = PLAYER1_JUMP;
        controls["attack"] = PLAYER1_ATTACK;
    }
    else {
        controls["left"] = PLAYER2_LEFT;
        controls["right"] = PLAYER2_RIGHT;
        controls["jump"] = PLAYER2_JUMP;
        controls["attack"] = PLAYER2_ATTACK;
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
    else
        player->setIsWalking(false);

    //Jump
    if (pInputManager->wasKeyPressed(controls.at("jump")))
        player->jump();

    if (pInputManager->wasKeyPressed(controls.at("attack")))
        player->setIsAttacking(true);



}
