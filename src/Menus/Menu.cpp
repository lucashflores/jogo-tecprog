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
    background->update(Coordinates::Vector<float>(640.f, 360.f));
}

void Menu::renderItems() {
    background->render();
    for (int i = 0; i < buttons.size(); i++) {
        buttons[i]->render();
    }

}

void Menu::moveDown() {
    buttons[buttonSelected]->setSelected(false);
    buttonSelected++;
    if (buttonSelected > buttons.size() - 1)
        buttonSelected = 0;
    buttons[buttonSelected]->setSelected(true);
}

void Menu::moveUp() {
    buttons[buttonSelected]->setSelected(false);
    buttonSelected--;
    if (buttonSelected < 0)
        buttonSelected = buttons.size() - 1;
    buttons[buttonSelected]->setSelected(true);
}



void Menu::updateButtons() {
    control->notify();
    for (int i = 0; i < buttons.size(); i++) {
        buttons[i]->update();
    }
}
