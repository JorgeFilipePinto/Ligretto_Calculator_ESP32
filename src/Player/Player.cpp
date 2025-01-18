#include "Player.h"

void Player::init(String name) {
    this-> name = name;
}


void Player::addPoints() {
    points -= (handCards * 2);
    points += (tableCards * 2);
}