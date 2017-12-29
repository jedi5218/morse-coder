#include "serialInputReciever.h"
#include "string.h"

SerialInputReciever &SerialInputReciever::instance()
{
    static SerialInputReciever object;
    return object;
}

void SerialInputReciever::appendData()
{
    char buffer[Serial.available()];
   for(char& symbol:buffer)
   {
       symbol=Serial.read();
   }
   char* begin=strstr(buffer,"/speed");
   if(begin)
   {
       begin+=6;
       char* end=strchr(begin,';');
       if(!end)
           end=begin+strlen(begin);
       char valueStr[32];
       for(char& c:valueStr)
           c='\0';
       strncpy(valueStr,begin,end-begin);
       double speed=atof(valueStr);
        if(speed>0)
            instance().speed=speed;
       Serial.print("SPEED: ");
       Serial.println(speed);
       Serial.println(begin);
       Serial.println(end);
       *(begin-6)='\0';

       for(int i=0;i<strlen(buffer);i++)
           instance().queue.push(buffer[i]);
       for(int i=0;i<strlen(end);i++)
           instance().queue.push(end[i]);

   }
   else
       for(char& symbol:buffer)
       {
             instance().queue.push(symbol);
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

float SerialInputReciever::outputSpeed()
{
    return speed;
}

SerialInputReciever::SerialInputReciever():queue()
{

}
