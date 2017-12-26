#include "serialInputReciever.h"


SerialInputReciever &SerialInputReciever::instance()
{
    static SerialInputReciever object;
    return object;
}

void SerialInputReciever::appendData()
{
    Serial.println("log: append data");
   while( Serial.available()>0 )
   {
       Serial.println(Serial.available());
       if(!instance().queue.push(Serial.read()))
               Serial.println("queue owerflow");
   }
}

bool SerialInputReciever::hasData()
{
    return !queue.isEmpty();
}

char SerialInputReciever::pop()
{
    Serial.println("log: data taken out");
    return queue.pop();
}

SerialInputReciever::SerialInputReciever():queue()
{

}
