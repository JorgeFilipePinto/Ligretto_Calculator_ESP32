#pragma once

#include <Arduino.h>
#include "Player\Player.h"


class Game {
    public:
        bool isOver = false;
        bool gameExist = false;
        int playersNumber = 0;
        int playersCreated = 0;
        int round = 0;
        int maxCardsHand = 10;
        int maxCardsTable = 40;
        Player* players;
        void init();
        void playersCreating();
        int howIsWin();
        void newRound();
        bool roudIsFinish();
        void setPlayerRound(int index);
        int pointsCalcule(int index);

    private:
        
};