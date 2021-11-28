#pragma once
#include "Button.h"
#include "Background.h"
#include "Text.h"
#include "Managers/InputManager.h"

#include <vector>

namespace Menus {

    class Menu {

    private:
        class MenuControl {
            friend class Menu;
        private:
            std::map<std::string, std::string> controls;
            Menu* menu;
            Managers::InputManager* pInputManager;
        public:
            MenuControl(Menu* m);
            ~MenuControl();
            void initializeControls();
            void notify();
        };

    protected:
        std::vector<Button*> buttons;
        Background* background;
        int buttonSelected;
        MenuControl* control;
        Text* menuTitle;
    public:
        Menu();
        virtual ~Menu();
        virtual void createButtons() = 0;
        void createBackground();
        void renderItems();
        void updateButtons();
        void moveUp();
        void moveDown();
        virtual void select() = 0;
        virtual void back() = 0;
    };

}