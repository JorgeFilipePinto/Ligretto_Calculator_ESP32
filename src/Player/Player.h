#pragma once
#include <Arduino.h>


class Player {
    public:
        String name;
        int points = 0;
        int tempPoints = 0;
        int tableCards = 0;
        int handCards = 0;
        int round = -1;

        void init(String name);
        void addPoints();

    private:


};