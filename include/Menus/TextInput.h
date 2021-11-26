#pragma once
#include "TextControl.h"
#include "Ent.h"

#define BUTTON_PATH "../assets/button.png"
#define FONT_PATH "../assets/font.ttf"

namespace Menus {
    class TextInput: public Ent {
    private:
        Managers::GraphicManager* pGraphicM;
        std::string currentText;
        sf::Text* label;
        sf::Text* text;
        sf::Font* font;
        TextControl* textControl;
    public:
        TextInput(Coordinates::Vector<float> pos, std::string labelText);
        ~TextInput();
        std::string getCurrentText() const;
        void initializeSprite();
        void render();
        void update();
        void erase();
    };
}