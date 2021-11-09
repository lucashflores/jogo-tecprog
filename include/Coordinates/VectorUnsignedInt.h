#pragma once

namespace Coordinates {

    class VectorUnsignedInt {
    private:
        unsigned int x;
        unsigned int y;
    public:
        VectorFloat(unsigned int x, unsigned int y);
        ~VectorFloat();
        unsigned int x();
        unsigned int y();
        void setX(unsigned int u);
        void setY(unsigned int f);
    };
}