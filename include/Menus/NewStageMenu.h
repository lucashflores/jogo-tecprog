#pragma once

#include "Menu.h"

namespace Menus {

    class NewStageMenu: public Menu{
    protected:
        Animation* player1Sprite;
        Animation* player2Sprite;
    public:
        NewStageMenu();
        ~NewStageMenu();
    };
}
