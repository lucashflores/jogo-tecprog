#include "States/GameStateMachine.h"
using namespace States;

GameStateMachine::GameStateMachine() {
    pGraphicM = Managers::GraphicManager::getInstance();
    pEventM = Managers::EventManager::getInstance();
    pInputM = Managers::InputManager::getInstance();
    pStage = NULL;
    player1 = new Entities::Player(true);
    player2 = new Entities::Player(false);
    currentStage = 1;
}

GameStateMachine::~GameStateMachine() {
    pGraphicM = NULL;
    pEventM = NULL;
    pInputM = NULL;
    pStage = NULL;
    delete player1;
    delete player2;
}

void GameStateMachine::exec() {
    return ;
}

void GameStateMachine::save() {

}

void GameStateMachine::setCurrentStage(int num) {
    currentStage = num;
}

void GameStateMachine::setStage(Stages::Stage *pS) {
    if (pS)
        pStage = pS;
}

Stages::Stage *GameStateMachine::getStage() const {
    return pStage;
}

Entities::Player *GameStateMachine::getPLayer1() {
    return player1;
}

Entities::Player *GameStateMachine::getPLayer2() {
    return player2;
}

