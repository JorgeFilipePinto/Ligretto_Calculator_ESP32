#pragma once

#include <Arduino.h>
#include "Player\Player.h"


class Game {
    public:
        bool gameExist = false;
        int playersNumber = 0;
        int playersCreated = 0;
        Player* players;

        void init(int playersNumber);
        void playersCreating();

};