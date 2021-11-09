#pragma once

namespace Coordinates {

    class VectorFloat {
    private:
        float x;
        float y;
    public:
        VectorFloat(float x, float y);
        ~VectorFloat();
        float getX();
        float getY();
        void setX(float f);
        void setY(float f);
    };

}
