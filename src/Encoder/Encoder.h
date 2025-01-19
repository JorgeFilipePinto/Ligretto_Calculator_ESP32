#pragma once
#include <Arduino.h>
#include <Wire.h>
#include "AiEsp32RotaryEncoder.h"
#include "AiEsp32RotaryEncoderNumberSelector.h"

class Encoder {
    public:
        float minSelector;
        float midSelector;
        float maxSelector;
        float selectorState;
        float scale;
        bool cicle;

        int counter = 0;
        void init(int CLK_Pin = 25, int DT_Pin = 26, int SW_Pin = 27, int EncoderSteps = 4);
        ~Encoder();

        void begin();
        void setSelectorRange(float minSelector = 0, float maxSelector = 12, float midSelector = 6, float scale = 1, bool cicle = false);
        void update();
        bool hasChanged();
        float getValue();
        bool isButtonClicked();

        static void IRAM_ATTR readEncoderISR();

    private:
        AiEsp32RotaryEncoder* rotaryEncoder;
        AiEsp32RotaryEncoderNumberSelector numberSelector;
        int EncoderSteps;
        int CLK_Pin;
        int DT_Pin;
        int SW_Pin;
};