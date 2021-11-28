#include "Menus/Button.h"
using namespace Menus;


Button::Button(Coordinates::Vector<float> pos, std::string t): Ent(Id::button), text() {
    selected = false;
    initializeSprite();
    sprite->changePosition(pos);
    Text::setFont(pGraphicM->loadFont(FONT_PATH));
    text = NULL;
    text = new Text(Coordinates::Vector<float>(pos.getX(), pos.getY() - 14.5f), t);
    text->changeColorToGrey();
}
Button::~Button() {
    if (text)
        delete text;
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
    text->render();
}

void Button::update() {
    if (getSelected())
        text->changeColorToOffWhite();
    else
        text->changeColorToGray();
}