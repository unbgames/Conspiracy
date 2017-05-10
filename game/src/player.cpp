#include "log.h"
#include "player.hpp"

using namespace engine;

Player::Player(){
    bilu = new Alien("assets/sprites/alien1.png", 0, 0, 50, 50);
    varginha = new Alien("assets/sprites/alien2.png", 0,70, 50, 50);
    etemer = new Alien("assets/sprites/alien3.png", 0,130, 50, 50);
    selectedAlien = 1;

    bilu->update(0);
    varginha->update(0);
    etemer->update(0);
}

Player::~Player(){}

void Player::update(int timeElapsed){
    int beforeAlien = selectedAlien;
    if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_ONE)){
        selectedAlien = 1;
    } else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_TWO)){
        selectedAlien = 2;
    } else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_THREE)){
        selectedAlien = 3;
    }

    if(beforeAlien != selectedAlien){
      waitAnimation(timeElapsed, beforeAlien);
    }

    switch(selectedAlien){
        case 1: bilu->update(timeElapsed); break;
        case 2: varginha->update(timeElapsed); break;
        case 3: etemer->update(timeElapsed); break;
    }
}

void Player::draw(){
    INFO("PLAYER DRAW");
    bilu->draw();
    varginha->draw();
    etemer->draw();
}

void Player::waitAnimation(int timeElapsed, int beforeAlien){
    if(beforeAlien==1){
      bilu->getAnimation()->setInterval(bilu->getAnimation()->getInterval().first, bilu->getAnimation()->getInterval().first);
      bilu->update(timeElapsed);
    }else if(beforeAlien==2){
      varginha->getAnimation()->setInterval(varginha->getAnimation()->getInterval().first, varginha->getAnimation()->getInterval().first);
      varginha->update(timeElapsed);
    } else if(beforeAlien==3){
      etemer->getAnimation()->setInterval(etemer->getAnimation()->getInterval().first, etemer->getAnimation()->getInterval().first);
      etemer->update(timeElapsed);
    }
}