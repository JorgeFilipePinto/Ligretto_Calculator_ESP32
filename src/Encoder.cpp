#include"Encoder.h"


void Encoder::init(int SW_Pin) {
    this-> SW_Pin = SW_Pin;
    this-> button = new ezButton(SW_Pin);
    pinModes();
}


void Encoder::pinModes() {
  // configure encoder pins as inputs
  pinMode(CLK_Pin, INPUT);
  pinMode(DT_Pin, INPUT);
  button-> setDebounceTime(50);  // set debounce time to 50 milliseconds
  last_CLK_estate = readClk();
}


bool Encoder::isRotated() {
    CLK_estate = readClk();
    if(CLK_estate != last_CLK_estate && CLK_estate == HIGH) {
        last_CLK_estate = CLK_estate;
        return true;
    }
    last_CLK_estate = CLK_estate;
    return false;
}


void Encoder::getCwDirection() {
    int dtState = readDt();
    //Serial.print("DT State: ");
    //Serial.println(dtState);

    if (dtState == LOW) {
        //Serial.println("Rotação: Horária (CW)");
        counterChange(true);
    } else {
        //Serial.println("Rotação: Anti-horária (CCW)");
        counterChange(false);
    }
}


void Encoder::counterChange(bool cwRotation){
    if(cwRotation) {
        counter < maxCounter ? counter++ : counter + 0;  
    } else {
        counter > 0 ? counter-- : counter - 0;
        
    }
}


bool Encoder::buttonPressed() {

    return false;
}


int Encoder::readClk() {
    int state = digitalRead(CLK_Pin);
    //Serial.print("CLK State: ");
    //Serial.println(state);
    return state;
}


int Encoder::readDt() {
    int state = digitalRead(DT_Pin);
    //Serial.print("DT State: ");
    //Serial.println(state);
    return state;
}