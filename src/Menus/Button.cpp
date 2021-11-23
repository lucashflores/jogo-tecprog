#include "Menus/Button.h"
using namespace Menus;

sf::Font* Button::font = NULL;

Button::Button(Coordinates::Vector<float> pos, std::string t): Ent(Id::button), text() {
    pGraphicM = Managers::GraphicManager::getInstance();
    selected = false;
    initializeSprite();
    sprite->changePosition(pos);
    text = NULL;
    text = new sf::Text();
    text->setString(t);
    text->setFont(*font);
    text->setPosition(pos.getX(), pos.getY());
    text->setFillColor(sf::Color::White);
}
Button::~Button() {

}

void Button::setFont(sf::Font* f) {
    if (!font) {
        if (f)
            font = f;
    }
}

void Button::initializeSprite() {
    Coordinates::Vector<float> size = Coordinates::Vector<float>(600.f ,200.f);
    Coordinates::Vector<unsigned int> imageCnt = Coordinates::Vector<unsigned int>(1, 1);
    sprite = new Animation(BUTTON_PATH, size, imageCnt, 1.f);
}

void Button::setSelected(bool s) {
    selected = s;
}

bool Button::getSelected() const {
    return selected;
}

void Button::render() {
    sprite->render();
    pGraphicM->render(text);
}

void Button::update() {
    if (getSelected())
        text->setFillColor(sf::Color::Red);
    else
        text->setFillColor(sf::Color::White);
}