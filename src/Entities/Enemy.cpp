#include "Entities/Enemy.h"
#include <iostream>
#include <math.h>

using namespace Entities;

Enemy::Enemy(Id::ids idEnemy, unsigned int life, unsigned int dmg,
             Coordinates::Vector<float> hit, Coordinates::Vector<float> pos, float view_rng):
Character(idEnemy, life, dmg, hit, pos), isCommitted(false), view_range(view_rng) {
    player1 = NULL;
    player2 = NULL;
    target = NULL;
}

Enemy::~Enemy() {
    player1 = NULL;
    player2 = NULL;
    target = NULL;
}

void Enemy::setPlayer(Player* player) {
    if(player) {
        if (player1 == NULL)
            player1 = player;
        else if (player2 == NULL)
            player2 = player;
        else
            std::cout << "All players were set on Enemy::setPlayer. Operation cannot succeed" << std::endl;
    }
    else
        std::cout << "Null player pointer to set on Enemy::setPlayer. Operation cannot succeed" << std::endl;

}

void Enemy::setTarget(Player* tg){
    target = tg;
}

void Enemy::chooseTarget() {
    double distP1 = 20000, distP2 = 20000;

    if (player1!=NULL) {
        distP1 = abs(sqrt(pow(player1->getPosition().getX() - getPosition().getX(), 2) +
                          pow(player1->getPosition().getY() - getPosition().getY(), 2)));
    }


    if (player2!=NULL) {
        distP2 = abs(sqrt(pow(player2->getPosition().getX() - getPosition().getX(), 2) +
                          pow(player2->getPosition().getY() - getPosition().getY(), 2)));
    }

    if (player2!=NULL){
        if (distP1 <= distP2)
            setTarget(player1);
        else
            setTarget(player2);
    }
    else
        setTarget(player1);


    if(target == player1) {
        if (distP1 < view_range)
            isCommitted = true;
        else
            isCommitted = false;
    }
    else if(target == player2) {
        if (distP2 < view_range)
            isCommitted = true;
        else
            isCommitted = false;
    }

}

double Enemy::getTargetDist() {
    if(target) {
        return abs(sqrt(pow(target->getPosition().getX() - getPosition().getX(), 2) +
                pow(target->getPosition().getY() - getPosition().getY(), 2)));
    }
    else
        std::cout <<"Enemy cannot get Target distance, target is NULL"<< std::endl;

    return -1;
}