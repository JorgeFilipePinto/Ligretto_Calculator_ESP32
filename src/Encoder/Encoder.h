#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <ezButton.h>


class Encoder {
    public:
        int counter = 0;
        int maxCounter = 12;
        void init(int SW_Pin = 27);
        bool isRotated();
        bool getCwDirection();
        void counterChange(bool cwRotation);
        bool buttonPressed();
        int readClk();
        int readDt();

    private:
        int CLK_estate;
        int last_CLK_estate;
        int CLK_Pin = 25;
        int DT_Pin = 26;
        int SW_Pin;
        ezButton* button;
        void pinModes();
};