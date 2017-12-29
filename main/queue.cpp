#include "queue.h"

#include "HardwareSerial.h"
extern HardwareSerial Serial;


uint16_t CharQueue::currentSize()
{
    if(begin>end)
        return end+QUEUE_SIZE-begin;
    else return end-begin;
}

CharQueue::CharQueue():begin(0),end(0)
{
}

CharQueue::~CharQueue()
{
}

char CharQueue::pop()
{
    if(begin!=end)
    {
        char retval=queueArray[end];
        end=(end+1)%QUEUE_SIZE;
        return retval;
    }
    else return 0;
}

bool CharQueue::push(char value)
{
    if(currentSize()>=QUEUE_SIZE)
    {
        Serial.println("OVERFLOW");
        Serial.print("Size: ");
        Serial.print(QUEUE_SIZE);
        Serial.print(" current: ");
        Serial.println(currentSize());
        return false;
    }
    else
    {
        queueArray[begin]=value;
        begin=(begin+1)%QUEUE_SIZE;
        return true;
    }
}

bool CharQueue::isEmpty()
{
    return begin==end;
}
