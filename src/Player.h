#pragma once
#include <Arduino.h>


class Player {
    public:
        int points = 0;
        String name;

        Player(int playerNumber) {
            name = "Player " + playerNumber;
        }

        void addPoints(int points);

    private:


};