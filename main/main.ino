#include "serialInputReciever.h"
unsigned int signalLED=2;
bool enabled=true;
void setup() {
  Serial.begin(9600);
  pinMode(signalLED,OUTPUT);
  while(!Serial);
  Serial.println("HelloWorld");
}

void loop() {

    SerialInputReciever& input=SerialInputReciever::instance();

    if(input.hasData())
    {
        Serial.println(input.pop());
        digitalWrite(signalLED,HIGH);
        delay(100);
        digitalWrite(signalLED,LOW);
        delay(300);
        digitalWrite(signalLED,HIGH);
        delay(100);
        digitalWrite(signalLED,LOW);
        delay(500);
    }
    digitalWrite(signalLED,HIGH);
    delay(500);
    digitalWrite(signalLED,LOW);
    delay(500);
}

void serialEvent()
{
    SerialInputReciever::appendData();
    digitalWrite(signalLED,HIGH);
    delay(100);
    digitalWrite(signalLED,LOW);
    delay(400);
}

