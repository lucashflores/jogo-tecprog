#pragma once
#include "Managers/GraphicManager.h"

#define FONT_PATH "../assets/font.ttf"

namespace Menus {
    class Text {
    private:
        static Managers::GraphicManager* pGraphicM;
        sf::Text* text;
        static sf::Font* font;
    public:
        Text(Coordinates::Vector<float> position, std::string t);
        ~Text();
        static void setFont(sf::Font* f);
        Coordinates::Vector<float> getPosition() const;
        void setPosition(Coordinates::Vector<float> position);
        void changeColorToWhite();
        void changeColorToRed();
        void setText(std::string t);
        void setSize(unsigned int s);
        void render();
    };
}
