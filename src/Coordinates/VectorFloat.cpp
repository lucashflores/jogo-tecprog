#include "Coordinates/VectorFloat.h"
using namespace Coordinates;

VectorFloat::VectorFloat(float x, float y): x(x), y(y) {
}

void VectorFloat::setX(float f) {
    x = f;
}

void VectorFloat::setY(float f) {
    y = f;
}

float VectorFloat::getX() {
    return x;
}

float VectorFloat::getY() {
    return y;
}

