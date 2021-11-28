#include "Menus/Menu.h"
using namespace Menus;

Menu::Menu(): buttons() {
    control = new MenuControl(this);
    buttonSelected = 0;
    menuTitle = NULL;
    createBackground();
}

Menu::~Menu() {
    if (menuTitle)
        delete menuTitle;
    delete control;
    delete background;
}

void Menu::createBackground() {
    background = new Background(Id::menuBackground);
    background->update(Coordinates::Vector<float>(640.f, 360.f));
}

void Menu::renderItems() {
    background->render();
    if (menuTitle)
        menuTitle->render();
    for (int i = 0; i < buttons.size(); i++) {
        buttons[i]->render();
    }

}

void Menu::moveDown() {
    if (buttons.size() > 0) {
        buttons[buttonSelected]->setSelected(false);
        buttonSelected++;
        if (buttonSelected > buttons.size() - 1)
            buttonSelected = 0;
        buttons[buttonSelected]->setSelected(true);
    }
}

void Menu::moveUp() {
    if (buttons.size() > 0) {
        buttons[buttonSelected]->setSelected(false);
        buttonSelected--;
        if (buttonSelected < 0)
            buttonSelected = buttons.size() - 1;
        buttons[buttonSelected]->setSelected(true);
    }

}



void Menu::updateButtons() {
    control->notify();
    for (int i = 0; i < buttons.size(); i++) {
        buttons[i]->update();
    }
}

//Nested MenuControl class definitions
Menu::MenuControl::MenuControl(Menu* m): controls() {
    if (m)
        menu = m;
    pInputManager = Managers::InputManager::getInstance();
    initializeControls();
}

Menu::MenuControl::~MenuControl() {
    menu = NULL;
    pInputManager = NULL;
}

void Menu::MenuControl::initializeControls() {
    controls["moveUp"] = "Up";
    controls["moveDown"] = "Down";
    controls["select"] = "Enter";
    controls["esc"] = "Escape";
}

void Menu::MenuControl::notify() {
    if (pInputManager->wasKeyPressedInFrame(controls.at("moveUp")))
        menu->moveUp();
    else if (pInputManager->wasKeyPressedInFrame(controls.at("moveDown")))
        menu->moveDown();
    else if (pInputManager->wasKeyPressedInFrame(controls.at("select")))
        menu->select();
    else if (pInputManager->wasKeyPressedInFrame(controls.at("esc")))
        menu->back();
    else
        return ;

}
