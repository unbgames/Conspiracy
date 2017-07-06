#ifndef ALIEN_VARGINHA_HPP
#define ALIEN_VARGINHA_HPP

#include "alien.hpp"
#include "camera_switch.hpp"
#include "camera_lever.hpp"

class Varginha: public Alien{
public:
    Varginha(double positionX, double positionY);
    void update(double timeElapsed);
    void draw();
protected:
    void specialAction();
private:
    bool isInvisible;
};

#endif
