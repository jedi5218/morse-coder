#include "serialInputReciever.h"



SerialInputReciever &SerialInputReciever::instance()
{
    static SerialInputReciever object;
    return object;
}

void SerialInputReciever::appendData()
{
    while( Serial.available() )
        instance().queue.push_back( Serial.recieve() );
}

bool SerialInputReciever::hasData()
{
    return queue.size();
}

char SerialInputReciever::pop()
{
    char retval=queue.front();
    queue.pop();
    return retval;
}

SerialInputReciever::SerialInputReciever()
{

}
