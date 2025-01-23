#pragma once

#include <Arduino.h>
#include "Player\Player.h"


class Game {
    public:
        bool isOver = false;
        bool gameExist = false;
        int maxPlayers = 12;
        int playersNumber = 0;
        int playersCreated = 0;
        int round = 0;
        int maxCardsHand = 10;
        int maxCardsTable = 40;
        Player* players;
        Player winner;
        void init();
        void playersCreating();
        int howIsWin();
        void newRound();
        bool roudIsFinish();
        void setPlayerRound(int index);
        int pointsCalcule(int index);
        Player winnerCalculation();
        
        String funnyNames[12] = {
            "Gilberto",
            "Anastácio",
            "Carolino",
            "Joaquina",
            "Albertina",
            "Player",
            "Player",
            "Player",
            "Player",
            "Player",
            "Player",
            "Player"
        };

    private:
        
};