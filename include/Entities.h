#pragma once

class Entities {
protected:
    float velocity;
    unsigned char life;
public:
    Entities(float v, unsigned char l);
    virtual ~Entities();
    virtual void move() = 0;
};

