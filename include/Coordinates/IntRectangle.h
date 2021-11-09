#pragma once

namespace Coordinates {

    class IntRectangle {
    private:
        int top;
        int height;
        int left;
        int width;
    public:
        intRectangle(int t, int h, int l, int w);
        ~intRectangle();
        int top();
        int height();
        int left();
        int width();
        void setTop(int i);
        void setHeight(int i);
        void setLeft(int i);
        void setWidth(int i);
        void intersects(IntRectangle rect);
    };

}