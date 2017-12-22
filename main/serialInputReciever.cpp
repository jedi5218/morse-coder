#include "serialInputReciever.h"



SerialInputReciever &SerialInputReciever::instance()
{
    static SerialInputReciever object;
    return object;
}

void SerialInputReciever::appendData()
{
   while( Serial.available() )
       Serial.read();

}

bool SerialInputReciever::hasData()
{

}

char SerialInputReciever::pop()
{

}

SerialInputReciever::SerialInputReciever()
{

}
