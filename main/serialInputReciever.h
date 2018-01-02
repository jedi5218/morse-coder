#ifndef SERIAL_INPUT_RECIEVER_H
#define SERIAL_INPUT_RECIEVER_H
#include "queue.h"


class SerialInputReciever
{
    CharQueue queue;
    float speed = 20;
public:
    static SerialInputReciever& instance();
    static void appendData();
    bool hasData();
    char pop();
    float outputSpeed();
private:
    SerialInputReciever(){}
//    SerialInputReciever(const SerialInputReciever& root) = delete;
//    SerialInputReciever(const SerialInputReciever&& moved) = delete;
//    SerialInputReciever& operator=(const SerialInputReciever&) = delete;
//    SerialInputReciever& operator=(const SerialInputReciever&) = delete;
};


#endif //SERIAL_INPUT_RECIEVER_H


