#include "serialInputReciever.h"
#include "morseEncoder.h"
#include <string.h>

unsigned int signalLED=2;

void setup() {
  Serial.begin(9600);
  pinMode(signalLED,OUTPUT);
  while(!Serial);
  Serial.println("Arduino is ready");
}

void loop()
{


    SerialInputReciever& input=SerialInputReciever::instance();

    if(input.hasData())
    {
        sendSymbol(input.pop(),input.outputSpeed());
    }
}

void serialEvent()
{
    SerialInputReciever::appendData();
}

