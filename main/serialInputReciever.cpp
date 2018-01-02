#include "serialInputReciever.h"
#include "debugOutput.h"
#include "string.h"

SerialInputReciever &SerialInputReciever :: instance()
{
    static SerialInputReciever object;
    return object;
}

void SerialInputReciever :: appendData()
{
   char buffer[255];
   strncpy( buffer, Serial.readString().c_str(), 255 );
   char* begin = strstr( buffer, "/speed" );

   if(begin)
   {
       begin += 6;//set begin to the first symbol of the value being set
       char* end = strchr( begin, ' ');

       if( !end )
           end = buffer + strlen( buffer );//if the end cannot be found it is set at the end of the buffer

       char valueStr[8];
       for( char& c : valueStr )
           c='\0';
       strncpy( valueStr, begin, end - begin);
       double speed = atof( valueStr );
        if( speed > 0 )
        {
            instance().speed=speed;
            setSpeedDebugOutput(speed);
        }
       strcpy( begin - 6, end );
   }

   for( int i = 0; i < strlen( buffer ); i++ )
   {
       instance().queue.push( buffer[i] );
   }
}

bool SerialInputReciever::hasData()
{
    return !queue.isEmpty();
}

char SerialInputReciever::pop()
{
    return queue.pop();
}

float SerialInputReciever::outputSpeed()
{
    return speed;
}


