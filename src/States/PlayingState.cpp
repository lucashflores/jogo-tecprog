#include "States/GameStateMachine.h"
using namespace States;

PlayingState::PlayingState(GameStateMachine* pGM) {
    if (pGM)
        pGameStateMachine = pGM;
    pInputManager = Managers::InputManager::getInstance();
    score = new Menus::Text(Coordinates::Vector<float>(640.f, 50.f), "SCORE: 0");
}

PlayingState::~PlayingState() {
    pGameStateMachine = NULL;
}

void PlayingState::update(float dt) {
    (pGameStateMachine->getStage())->exec(dt);


    if (pInputManager->wasKeyPressedInFrame("Escape"))
        back();

    if (pGameStateMachine->getTwoPlayers()) {
        if (pGameStateMachine->getPLayer1()->getIsAlive() == false || pGameStateMachine->getPLayer2()->getIsAlive() == false) {
            pGameStateMachine->setScore(pGameStateMachine->getScore() + (pGameStateMachine->getStage())->getScore());
            pGameStateMachine->setCurrentStage(0);
            exec();
        }

    }
    else {
        if (pGameStateMachine->getPLayer1()->getIsAlive() == false) {
            pGameStateMachine->setScore(pGameStateMachine->getScore() + (pGameStateMachine->getStage())->getScore());
            pGameStateMachine->setCurrentStage(0);
            exec();
        }

    }

    if ((pGameStateMachine->getStage())->getIsStageDone()) {
        pGameStateMachine->setScore(pGameStateMachine->getScore() + (pGameStateMachine->getStage())->getScore());
        exec();
    }
}

void PlayingState::exec() {
    if (pGameStateMachine->getCurrentStage() == 1)
        changeState("CreatingStage2State");
    else
        changeState("EndGameMenuState");
}

void PlayingState::reset() {
    pGameStateMachine->setGameViewSize(Coordinates::Vector<float>(640.f, 480.f));
    pGameStateMachine->centerGameView(Coordinates::Vector<float>(320.f ,240.f));
    pInputManager->clearKeyPressedInFrame();
}

void PlayingState::render() {
}

void PlayingState::back() {
    changeState("PauseMenuState");
}

