#ifndef SERIAL_INPUT_RECIEVER
#define SERIAL_INPUT_RECIEVER
#include "CDCSerialClass.h"

extern CDCSerialClass Serial;

class SerialInputReciever
{
    bool data=true;
public:
    static SerialInputReciever& instance();
    static void appendData();
    bool hasData();
    char pop();
private:
    SerialInputReciever();
//    SerialInputReciever(const SerialInputReciever& root) = delete;
//    SerialInputReciever(const SerialInputReciever&& moved) = delete;
//    SerialInputReciever& operator=(const SerialInputReciever&) = delete;
//    SerialInputReciever& operator=(const SerialInputReciever&) = delete;
};


#endif //SERIAL_INPUT_RECIEVER


