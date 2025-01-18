#include <Arduino.h>
#include "LCD\Lcd.h"
#include "Encoder\Encoder.h"




Encoder encoder;
Lcd lcd;

void setup() {
    Serial.begin(115200);
    encoder.init();
    lcd.init();
}



void loop() {
    if(encoder.isRotated()) {
        encoder.getCwDirection();
        Serial.print("Counter: "); Serial.println(encoder.counter);
    }
}


