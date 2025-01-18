#include <Arduino.h>
#include "Menu\Menu.h"



Menu menu;
void setup() {
    Serial.begin(115200);
    menu.init();
}



void loop() {
    menu.mainMenuNavigation();
}


