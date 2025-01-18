#include "Lcd.h"
#include "Images.cpp"


void Lcd::init() {
  this-> lcd = new Adafruit_SH1106G(width, height, &Wire, resetPin);
  delay(250);
  lcd-> begin(address, true);
  lcd-> display();
  lcd-> clearDisplay();
  lcd-> setTextColor(SH110X_WHITE);
  apresentation();
}


void Lcd::refresh() {
  lcd-> display();
}


void Lcd::write(String text, int x, int y, int size) {
  allClear();
  lcd-> setCursor(x, y);
  lcd-> setTextSize(size);
  lcd-> println(text);
  refresh();
}

void Lcd::writeWithouClear(String text, int x, int y, int size) {
  lcd-> setCursor(x, y);
  lcd-> setTextSize(size);
  lcd-> println(text);
  refresh();
}


void Lcd::allClear() {
  lcd-> clearDisplay();
}


void Lcd::drawBmpImages(int x, int y, const unsigned char *image, int w, int h) {
  allClear();
  lcd-> drawBitmap(x, y, image, w, h, 1);
  refresh();
}


void Lcd::apresentation() {
  drawBmpImages(0, 0, arduino_logo_image, 128, 64);
  delay(3000);
}


void Lcd::drawMenu1() {
  drawBmpImages(0, 0, Menu1, 128, 64);
}


void Lcd::drawMenu2() {
  drawBmpImages(0, 0, Menu2, 128, 64);
}


void Lcd::drawMenu3() {
  drawBmpImages(0, 0, Menu3, 128, 64);
}

