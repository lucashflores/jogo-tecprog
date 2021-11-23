#include "Menus/Menu.h"
using namespace Menus;

Menu::Menu(): buttons() {
    control = new MenuControl(this);
    buttonSelected = 0;
    createBackground();
}

Menu::~Menu() {
    delete control;
    delete background;
}

void Menu::createBackground() {
    background = new Background(Id::menuBackground);
}

void Menu::renderItems() {
    for (int i = 0; i < buttons.size(); i++) {
        buttons[i]->render();
    }
    background->render();
}

void Menu::moveDown() {
    if (buttonSelected + 1 > buttons.size() - 1)
        return ;
    else {
        buttons[buttonSelected]->setSelected(false);
        buttonSelected++;
        buttons[buttonSelected]->setSelected(true);
    }
}

void Menu::moveUp() {
    if (buttonSelected - 1 < 0)
        return ;
    else {
        buttons[buttonSelected]->setSelected(false);
        buttonSelected--;
        buttons[buttonSelected]->setSelected(true);
    }
}



void Menu::update() {
    control->notify();
    for (int i = 0; i < buttons.size(); i++) {
        buttons[i]->update();
    }
    renderItems();
}

int Menu::select() {
    return buttonSelected;
}