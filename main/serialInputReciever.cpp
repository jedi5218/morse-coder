#include "serialInputReciever.h"
#include "string.h"

SerialInputReciever &SerialInputReciever::instance()
{
    static SerialInputReciever object;
    return object;
}

void SerialInputReciever::appendData()
{
   char buffer[255];
   strcpy(buffer,Serial.readString().c_str());
   Serial.print("Recieved string: ");
   Serial.println(buffer);
   char* begin=strstr(buffer,"/speed");

   if(begin)
   {
       begin+=6;
       char* end=strchr(begin,' ');
       if(!end)
           end=buffer+strlen(buffer);
       char valueStr[8];
       for(char& c:valueStr)
           c='\0';
       strncpy(valueStr,begin,end-begin);
       double speed=atof(valueStr);
        if(speed>0)
            instance().speed=speed;
        *(begin-6)='\0';
       Serial.print("SPEED: ");
       Serial.println(speed);
       Serial.print("parsed string: ");
       Serial.println(buffer);
       Serial.print("begin: ");
       Serial.println(begin);
       Serial.print("end: ");
       Serial.println(end);

       for(int i=0;i<strlen(buffer);i++)
           instance().queue.push(buffer[i]);
       for(int i=0;i<strlen(end);i++)
           instance().queue.push(end[i]);

   }
   else
       for(int i=0;i<strlen(buffer);i++)
       {
             instance().queue.push(buffer[i]);
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

SerialInputReciever::SerialInputReciever():queue()
{

}
