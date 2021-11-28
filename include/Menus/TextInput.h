#pragma once
#include "Text.h"
#include "Ent.h"
#include "Managers/InputManager.h"
#include <map>
#include <string>

#define BUTTON_PATH "../assets/button.png"
#define FONT_PATH "../assets/font.ttf"

namespace Menus {
    class TextInput: public Ent {
    private:
        class TextControl {
            friend class TextInput;
        private:
            Managers::InputManager* pInputManager;
            TextInput* pTextInput;
            std::map<std::string, std::string> controls;
        public:
            TextControl(TextInput* pTI);
            ~TextControl();
            void initializeControls();
            std::string notify();
        };

    private:
        std::string currentText;
        Text* text;
        Text* label;
        TextControl* textControl;
        Coordinates::Vector<float> origin;
    public:
        TextInput(Coordinates::Vector<float> pos, std::string labelText);
        ~TextInput();
        std::string getCurrentText() const;
        void initializeSprite();
        void render();
        void update();
        void erase();
        void reset();
    };
}