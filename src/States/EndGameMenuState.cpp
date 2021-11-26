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