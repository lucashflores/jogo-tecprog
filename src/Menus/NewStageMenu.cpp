#include "Menus/NewStageMenu.h"
using namespace Menus;

NewStageMenu::NewStageMenu() {
    player1Sprite = new Animation("../assets/spriteSheets/players/biker.png", Coordinates::Vector<float>(700.f, 700.f), Coordinates::Vector<unsigned int>(6,8), 0.5f);
    player2Sprite = new Animation("../assets/spriteSheets/players/cyborg.png", Coordinates::Vector<float>(700.f, 700.f), Coordinates::Vector<unsigned int>(6,8), 0.5f);
}

NewStageMenu::~NewStageMenu() {
    if (player1Sprite)
        delete player1Sprite;
    if (player2Sprite)
        delete player2Sprite;
}