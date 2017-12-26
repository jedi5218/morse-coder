#include "serialInputReciever.h"
#include "morseEncoder.h"
unsigned int signalLED=2;
bool enabled=true;
void setup() {
  Serial.begin(9600);
  pinMode(signalLED,OUTPUT);
  while(!Serial);
  Serial.println("HelloWorld");
}

void loop()
{


    SerialInputReciever& input=SerialInputReciever::instance();

    if(input.hasData())
    {
        encodeSymbol(input.pop(),10);
    }
}

void serialEvent()
{
    SerialInputReciever::appendData();
    digitalWrite(signalLED,HIGH);
    delay(100);
    digitalWrite(signalLED,LOW);
    delay(400);
}

