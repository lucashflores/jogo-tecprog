#pragma once

namespace Coordinates {
    template <class TYPE>
    class Vector {
    private:
        TYPE x;
        TYPE y;
    public:
        Vector<TYPE>(TYPE num1, TYPE num2);
        ~Vector<TYPE>();

        TYPE getX() const;
        TYPE getY() const;
        void setX(TYPE num);
        void setY(TYPE num);

        Vector<TYPE> operator+(TYPE num);
        Vector<TYPE> operator-(TYPE num);
        Vector<TYPE> operator/(TYPE num);
        Vector<TYPE> operator*(TYPE num);
        void operator+=(TYPE num);
        void operator-=(TYPE num);
        void operator/=(TYPE num);
        void operator*=(TYPE num);

        Vector<TYPE> operator+(Vector<TYPE> vec);
        Vector<TYPE> operator-(Vector<TYPE> vec);
        Vector<TYPE> operator/(Vector<TYPE> vec);
        Vector<TYPE> operator*(Vector<TYPE> vec);
        void operator+=(Vector<TYPE> vec);
        void operator-=(Vector<TYPE> vec);
        void operator/=(Vector<TYPE> vec);
        void operator*=(Vector<TYPE> vec);


        void operator++();
        void operator--();
    };

    template <class TYPE>
    Vector<TYPE>::Vector(TYPE num1, TYPE num2): x(num1), y(num2) {}

    template <class TYPE>
    Vector<TYPE>::~Vector() {}

    template <class TYPE>
    void Vector<TYPE>::setX(TYPE num) {x = num;}

    template <class TYPE>
    void Vector<TYPE>::setY(TYPE num) {y = num;}

    template <class TYPE>
    TYPE Vector<TYPE>::getX() const {return x;}

    template <class TYPE>
    TYPE Vector<TYPE>::getY() const {return y;}



    // ================ Operations with Numbers ===================
    template <class TYPE>
    Vector<TYPE> Vector<TYPE>::operator+(TYPE num) {
        return Vector<TYPE>(this->getX() + num, this->getY() + num);
    }

    template <class TYPE>
    Vector<TYPE> Vector<TYPE>::operator-(TYPE num) {
        return Vector<TYPE>(this->getX() - num, this->getY() - num);
    }

    template <class TYPE>
    Vector<TYPE> Vector<TYPE>::operator*(TYPE num) {
        return Vector<TYPE>(this->getX() * num, this->getY() * num);
    }

    template <class TYPE>
    Vector<TYPE> Vector<TYPE>::operator/(TYPE num) {
        return Vector<TYPE>(this->getX() / num, this->getY() / num);
    }


    //Permanent
    template <class TYPE>
    void Vector<TYPE>::operator+=(TYPE num) {
       setX(getX() + num);
       setY(getY() + num);
    }

    template <class TYPE>
    void Vector<TYPE>::operator-=(TYPE num) {
        setX(getX() - num);
        setY(getY() - num);
    }

    template <class TYPE>
    void Vector<TYPE>::operator*=(TYPE num) {
        setX(getX() * num);
        setY(getY() * num);
    }

    template <class TYPE>
    void Vector<TYPE>::operator/=(TYPE num) {
        setX(getX() / num);
        setY(getY() / num);
    }



    // ================ Operations with Vectors ===================
    template <class TYPE>
    Vector<TYPE> Vector<TYPE>::operator+(Vector<TYPE> vec) {
        return Vector<TYPE>(getX() + vec.getX(), getY() + vec.getY());
    }

    template <class TYPE>
    Vector<TYPE> Vector<TYPE>::operator-(Vector<TYPE> vec) {
        return Vector<TYPE>(getX() - vec.getX(), getY() - vec.getY());
    }

    template <class TYPE>
    Vector<TYPE> Vector<TYPE>::operator*(Vector<TYPE> vec) {
        return Vector<TYPE>(getX() * vec.getX(), getY() * vec.getY());
    }

    template <class TYPE>
    Vector<TYPE> Vector<TYPE>::operator/(Vector<TYPE> vec) {
        return Vector<TYPE>(getX() / vec.getX(), getY() / vec.getY());
    }

    //Permanent
    template <class TYPE>
    void Vector<TYPE>::operator+=(Vector<TYPE> vec) {
        setX(getX() + vec.getX());
        setY(getY() + vec.getY());
    }

    template <class TYPE>
    void Vector<TYPE>::operator-=(Vector<TYPE> vec) {
        setX(getX() - vec.getX());
        setY(getY() - vec.getY());
    }

    template <class TYPE>
    void Vector<TYPE>::operator*=(Vector<TYPE> vec) {
        setX(getX() * vec.getX());
        setY(getY() * vec.getY());
    }

    template <class TYPE>
    void Vector<TYPE>::operator/=(Vector<TYPE> vec) {
        setX(getX() / vec.getX());
        setY(getY() / vec.getY());
    }



    //Other
    template <class TYPE>
    void Vector<TYPE>::operator++() {
        setX(getX()++);
        setY(getY()++);
    }

    template <class TYPE>
    void Vector<TYPE>::operator--() {
        setX(getX()--);
        setY(getY()--);
    }

}


