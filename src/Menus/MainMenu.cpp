#include "Menus/MainMenu.h"
using namespace Menus;

MainMenu::MainMenu() {
    bossSprite = new Animation("../assets/bossMenuAnimation.png", Coordinates::Vector<float>(900.f, 900.f), Coordinates::Vector<unsigned int>(4, 1), 0.5f);
    bossSprite->changePosition(Coordinates::Vector<float>(800.f, 600.f));
    menuTitle = new Text(Coordinates::Vector<float>(780.f, 130.f), "TEC PUNK");
    menuTitle->setSize(230);
    menuTitle->changeColorToOffWhite();
}

MainMenu::~MainMenu() {
    if (bossSprite)
        delete bossSprite;
}

