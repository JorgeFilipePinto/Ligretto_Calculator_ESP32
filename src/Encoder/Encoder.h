#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <ezButton.h>


class Encoder {
    public:
        ezButton* button;
        int CLK_estate;
        int last_CLK_estate;
        int counter = 0;
        int maxCounter = 12;
        void init(int CLK_Pin = 25, int DT_Pin = 26, int SW_Pin = 27);
        bool isRotated();
        bool getCwDirection();
        void counterEncoder();
        bool buttonIsPressed();
        int readClk();
        int readDt();

    private:

        int CLK_Pin;
        int DT_Pin;
        int SW_Pin;
        void pinModes();
};