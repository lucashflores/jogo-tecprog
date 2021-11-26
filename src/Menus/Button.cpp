#include "Menus/Button.h"
using namespace Menus;

sf::Font* Button::font = NULL;

Button::Button(Coordinates::Vector<float> pos, std::string t): Ent(Id::button), text() {
    pGraphicM = Managers::GraphicManager::getInstance();
    selected = false;
    initializeSprite();
    sprite->changePosition(pos);
    if (!font)
        setFont(pGraphicM->loadFont(FONT_PATH));
    text = NULL;
    text = new sf::Text();
    text->setString(t);
    text->setFont(*font);
    text->setCharacterSize(25);

    //center text
    sf::FloatRect textRect = text->getLocalBounds();
    text->setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
    text->setPosition(640.f,pos.getY()-15.f);

    //text->setPosition(pos.getX() - 105.f, pos.getY());
    text->setFillColor(sf::Color::White);
}
Button::~Button() {
    if (text)
        delete text;
}

void Button::setFont(sf::Font* f) {
    if (!font) {
        if (f)
            font = f;
    }
}

void Button::initializeSprite() {
    Coordinates::Vector<float> size = Coordinates::Vector<float>(210.f ,70.f);
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
        text->setFillColor(sf::Color(175, 175, 189, 255));
    else
        text->setFillColor(sf::Color(22, 22, 28, 255));
}