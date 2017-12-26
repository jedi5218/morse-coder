#include "serialInputReciever.h"


SerialInputReciever &SerialInputReciever::instance()
{
    static SerialInputReciever object;
    return object;
}

void SerialInputReciever::appendData()
{
   while( Serial.available()>0 )
       instance().queue.push(Serial.read());
}

bool SerialInputReciever::hasData()
{
    return !queue.isEmpty();
}

char SerialInputReciever::pop()
{
    return queue.pop();
}

SerialInputReciever::SerialInputReciever():queue()
{

}
