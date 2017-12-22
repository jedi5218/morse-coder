#include "serialInputReciever.h"
unsigned int signalLED=2;

void setup() {
  Serial.begin(9600);
  pinMode(signalLED,OUTPUT);
}

void loop() {
    auto& input=SerialInputReciever::instance();

    if(input.hasData())
    {
        input.pop();
        digitalWrite(signalLED,HIGH);
        Delay(500);
        digitalWrite(signalLED,LOW);
        Delay(500);
    }


}

void serialEvent()
{
    SerialInputReciever::appendData();
}

