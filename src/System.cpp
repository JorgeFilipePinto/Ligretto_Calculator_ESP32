#include <Arduino.h>

#include "Encoder.h"




Encoder encoder;

void setup() {
    Serial.begin(115200);
    encoder.init();
}



void loop() {
    if(encoder.isRotated()) {
        encoder.getCwDirection();
        Serial.print("Counter: "); Serial.println(encoder.counter);
    }
}


