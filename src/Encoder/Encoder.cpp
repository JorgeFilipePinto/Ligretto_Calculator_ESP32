#include"Encoder.h"


static Encoder *instance = nullptr;

void Encoder::init(int CLK_Pin, int DT_Pin, int SW_Pin, int EncoderSteps) {
    this-> CLK_Pin = CLK_Pin;
    this-> DT_Pin = DT_Pin;
    this-> SW_Pin = SW_Pin;
    this-> EncoderSteps = EncoderSteps;
    this-> rotaryEncoder = new AiEsp32RotaryEncoder(CLK_Pin, DT_Pin, SW_Pin, -1, EncoderSteps);
    numberSelector = AiEsp32RotaryEncoderNumberSelector();
    instance = this;
}


Encoder::~Encoder() {
  delete rotaryEncoder;
}




void Encoder::begin(){
  rotaryEncoder->begin();
  rotaryEncoder->setup(readEncoderISR);
  numberSelector.attachEncoder(rotaryEncoder);
}


void Encoder::update()
{
    rotaryEncoder->readEncoder(); // Atualizar manualmente o estado do encoder
}


bool Encoder::hasChanged()
{
    return rotaryEncoder->encoderChanged();
}


float Encoder::getValue()
{
  selectorState = numberSelector.getValue();
    return selectorState;
}


bool Encoder::isButtonClicked()
{
    return rotaryEncoder->isEncoderButtonClicked();
}


void Encoder::setSelectorRange(float minSelector, float maxSelector, float midSelector, float scale, bool ciccle) {
  this-> minSelector = minSelector;
  this-> midSelector = midSelector;
  this-> maxSelector = maxSelector;
  this-> cicle = cicle;
  this-> scale = scale;
  selectorState = midSelector;
  numberSelector.setRange(minSelector, maxSelector, scale, ciccle, 0);
  numberSelector.setValue(midSelector);
}

void IRAM_ATTR Encoder::readEncoderISR()
{
    if (instance)
    {
        instance->rotaryEncoder->readEncoder_ISR();
    }
}



