#include "Menus/Text.h"
using namespace Menus;

sf::Font* Text::font = NULL;
Managers::GraphicManager* Text::pGraphicM = NULL;

Text::Text(Coordinates::Vector<float> position, std::string t) {
    text = new sf::Text();

    if (!pGraphicM)
        pGraphicM = Managers::GraphicManager::getInstance();


    text->setFont(*font);
    text->setString(t);

    text->setPosition(position.getX(), position.getY());

    sf::FloatRect textRect = text->getLocalBounds();
    text->setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);



    changeColorToWhite();
}

Text::~Text() {
    if (text)
        delete text;
}

void Text::setFont(sf::Font* f) {
    if (f && !font)
        font = f;
}

Coordinates::Vector<float> Text::getPosition() const {
    return Coordinates::Vector<float>(text->getPosition().x, text->getPosition().y);
}

void Text::setPosition(Coordinates::Vector<float> position) {
    text->setPosition(position.getX(), position.getY());
}

void Text::changeColorToWhite() {
    text->setFillColor(sf::Color::White);
}

void Text::changeColorToRed() {
    text->setFillColor(sf::Color::Red);
}

void Text::setText(std::string t) {
    text->setString(t);
}


void Text::render() {
    pGraphicM->render(text);
}

void Text::setSize(unsigned int s) {
    text->setCharacterSize(s);
    text->setPosition(getPosition().getX(), getPosition().getY());

    sf::FloatRect textRect = text->getLocalBounds();
    text->setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
}