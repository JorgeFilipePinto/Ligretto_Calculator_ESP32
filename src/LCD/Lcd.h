#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>




class Lcd {
    public:
        bool newData = true;
        void init();
        void refresh();
        void write(String text, int x, int y, int size);
        void writeWithouClear(String text, int x, int y, int size);
        void allClear();
        void drawBmpImages(int x, int y, const unsigned char *image, int w= 16, int h = 16);
        void apresentation();
        void drawMenu1();
        void drawMenu2();
        void drawMenu3();
        int pagesCalculation(int number, int maxNumber);


    private:
        Adafruit_SH1106G* lcd;
        int address = 0x3c;
        int resetPin = -1;
        int width = 128;
        int height = 64;


};