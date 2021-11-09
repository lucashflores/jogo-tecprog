#pragma once

namespace Coordinates {

    class FloatRectangle {
    private:
        float top;
        float height;
        float left;
        float width;
    public:
        FloatRectangle(float t, float h, float l, float w);
        ~FloatRectangle();
        float top();
        float height();
        float left();
        float width();
        void setTop(float f);
        void setHeight(float f);
        void setLeft(float f);
        void setWidth(float f);
        void intersects(FloatRectangle rect);
    };

}