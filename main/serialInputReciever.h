#ifndef SERIAL_INPUT_RECIEVER
#define SERIAL_INPUT_RECIEVER
#include "HardwareSerial.h"
extern HardwareSerial Serial;
#include "queue.h"


class SerialInputReciever
{
    CharQueue queue;
    bool data=true;
    float speed=20;
public:
    static SerialInputReciever& instance();
    static void appendData();
    bool hasData();
    char pop();
    float outputSpeed();
private:
    SerialInputReciever();
//    SerialInputReciever(const SerialInputReciever& root) = delete;
//    SerialInputReciever(const SerialInputReciever&& moved) = delete;
//    SerialInputReciever& operator=(const SerialInputReciever&) = delete;
//    SerialInputReciever& operator=(const SerialInputReciever&) = delete;
};


#endif //SERIAL_INPUT_RECIEVER


