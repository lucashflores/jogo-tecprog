#include "States/GameStateMachine.h"
using namespace States;

NewStage2MenuState::NewStage2MenuState(GameStateMachine* pGM) {
    if (pGM)
        pGameStateMachine = pGM;
    createButtons();
    buttons[buttonSelected]->setSelected(true);
    pInputManager = Managers::InputManager::getInstance();
}

NewStage2MenuState::~NewStage2MenuState() {
    pGameStateMachine = NULL;
}

void NewStage2MenuState::createButtons() {
    Menus::Button* b = NULL;
    b = new Menus::Button(Coordinates::Vector<float>(200.f, 120.f), "One Player");
    buttons.push_back(b);
    b = NULL;
    b = new Menus::Button(Coordinates::Vector<float>(200.f, 250.f), "Two Players");
    buttons.push_back(b);
    b = NULL;
}


void NewStage2MenuState::update(float dt) {
    updateButtons();
    render();
}

void NewStage2MenuState::render() {
    renderItems();
}

void NewStage2MenuState::exec() {
    if (buttonSelected == 0)
        pGameStateMachine->setTwoPlayers(false);
    else if (buttonSelected == 1)
        pGameStateMachine->setTwoPlayers(true);
    changeState("CreatingStage2State");
}

void NewStage2MenuState::select() {
    exec();
}

void NewStage2MenuState::reset() {
    buttons[buttonSelected]->setSelected(false);
    buttonSelected = 0;
    buttons[buttonSelected]->setSelected(true);
    pInputManager->clearKeyPressedInFrame();
    updateButtons();
    render();
}

void NewStage2MenuState::back() {
    changeState("MainMenuState");
}