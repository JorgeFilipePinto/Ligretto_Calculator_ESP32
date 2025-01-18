#pragma once
#include <Arduino.h>


class Player {
    public:
        String name;
        int points = 0;
        int tableCards = 0;
        int handCards = 0;

        void init(String name);
        void addPoints();

    private:


};