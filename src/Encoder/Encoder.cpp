#include"Encoder.h"


void Encoder::init(int CLK_Pin, int DT_Pin, int SW_Pin) {
    this-> CLK_Pin = CLK_Pin;
    this-> DT_Pin = DT_Pin;
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

    return (CLK_estate != last_CLK_estate) && (CLK_estate == HIGH);
}


bool Encoder::getCwDirection() {

    if (readDt() == HIGH) {
        Serial.println("Rotação: Horária (CW)");
        return true;
    } else {
        Serial.println("Rotação: Anti-horária (CCW)");
        return false;
    }
}


void Encoder::counterEncoder(){
  CLK_estate = readClk();

  if (CLK_estate != last_CLK_estate && CLK_estate == HIGH) {

    if (readDt() == HIGH) {
      counter++;
    } else {
      counter--;
    }

  }
  last_CLK_estate = readClk();

}


bool Encoder::buttonIsPressed() {
    button-> loop();
    return button-> isPressed();
}


int Encoder::readClk() {
    digitalRead(CLK_Pin);
    return digitalRead(CLK_Pin);
}


int Encoder::readDt() {
    digitalRead(DT_Pin);
    return digitalRead(DT_Pin);
}