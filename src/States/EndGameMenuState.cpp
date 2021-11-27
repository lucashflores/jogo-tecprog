#include "States/GameStateMachine.h"
using namespace States;

EndGameMenuState::EndGameMenuState(GameStateMachine *pGM) {
    if (pGM)
        pGameStateMachine = pGM;
    menuTitle = new Menus::Text(Coordinates::Vector<float>(640.f, 150.f), "GAME OVER");
    menuTitle->setSize(100);
    createButtons();
}

EndGameMenuState::~EndGameMenuState() {
    pGameStateMachine = NULL;
}

void EndGameMenuState::createButtons() {
    textInput = new Menus::TextInput(Coordinates::Vector<float>(640.f, 480.f), "Enter your nickcname:");
}

void EndGameMenuState::update(float dt) {
    control->notify();
    textInput->update();
    render();
}

void EndGameMenuState::render() {
    renderItems();
    menuTitle->render();
    textInput->render();
}

void EndGameMenuState::reset() {
    if (pGameStateMachine->getStage()) {
        if (pGameStateMachine->getStage()->getIsStageDone())
            menuTitle->setText("VICTORY");
    }
    pGameStateMachine->setGameViewSize(Coordinates::Vector<float>(1280.f, 720.f));
    pGameStateMachine->centerGameView(Coordinates::Vector<float>(640.f ,360.f));
    textInput->reset();
    render();
}

void EndGameMenuState::exec() {
    if (textInput->getCurrentText().size() > 0) {
        pGameStateMachine->setName(textInput->getCurrentText());
        changeState("SavingLeaderBoardState");
    }
    else
        return;
}

void EndGameMenuState::select() {
    exec();
}

void EndGameMenuState::back() {
    return ;
}