#include "States/GameStateMachine.h"
using namespace States;

NewGameMenuState::NewGameMenuState(GameStateMachine* pGM) {
    if (pGM)
        pGameStateMachine = pGM;
    createButtons();
    buttons[buttonSelected]->setSelected(true);
    pInputManager = Managers::InputManager::getInstance();
}

NewGameMenuState::~NewGameMenuState() {
    pGameStateMachine = NULL;
}

void NewGameMenuState::createButtons() {
    Menus::Button* b = NULL;
    b = new Menus::Button(Coordinates::Vector<float>(640.f, 230.f), "One Player");
    buttons.push_back(b);
    b = NULL;
    b = new Menus::Button(Coordinates::Vector<float>(640.f, 490.f), "Two Players");
    buttons.push_back(b);
    b = NULL;
}


void NewGameMenuState::update(float dt) {
    updateButtons();
    render();
}

void NewGameMenuState::render() {
    renderItems();
}

void NewGameMenuState::exec() {
    if (buttonSelected == 0)
        pGameStateMachine->setTwoPlayers(false);
    else if (buttonSelected == 1)
        pGameStateMachine->setTwoPlayers(true);
    changeState("CreatingStage1State");
}

void NewGameMenuState::select() {
    exec();
}

void NewGameMenuState::reset() {
    buttonSelected = 0;
    pInputManager->clearKeyPressedInFrame();
    updateButtons();
    render();
}

void NewGameMenuState::back() {
    changeState("MainMenuState");
}