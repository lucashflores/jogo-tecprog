#include "States/GameStateMachine.h"
using namespace States;

EndGameMenuState::EndGameMenuState(GameStateMachine *pGM) {
    if (pGM)
        pGameStateMachine = pGM;
    createButtons();
}

EndGameMenuState::~EndGameMenuState() {
    pGameStateMachine = NULL;
}

void EndGameMenuState::createButtons() {
    textInput = new Menus::TextInput(Coordinates::Vector<float>(640.f, 360.f), "Enter your nickcname:");
}

void EndGameMenuState::update(float dt) {
    textInput->update();
    render();
}

void EndGameMenuState::render() {
    renderItems();
    textInput->render();
}

void EndGameMenuState::reset() {
    pGameStateMachine->setGameViewSize(Coordinates::Vector<float>(1280.f, 720.f));
    pGameStateMachine->centerGameView(Coordinates::Vector<float>(640.f ,360.f));
    render();
}

void EndGameMenuState::exec() {
    if (textInput->getCurrentText() != " " && textInput->getCurrentText() != "") {
        pGameStateMachine->setName(textInput->getCurrentText());
        changeState("LeaderBoardMenuState");
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