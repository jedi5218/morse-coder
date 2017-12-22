#include "queue.h"

uint16_t CharQueue::currentSize()
{
    if(begin>end)
        return end+size-begin;
}

CharQueue::CharQueue(uint16_t size):size(size),begin(0),end(0)
{
    queueArray=new char[size];
}

CharQueue::~CharQueue()
{
    delete queueArray;
}

char CharQueue::pop()
{
    if(begin!=end)
    {
        char retval=queueArray[end];
        end=(end+size-1)%size;
        return retval;
    }
    else return 0;
}

bool CharQueue::push(char value)
{
    if(currentSize()>=size)
        return false;
    else
    {
        begin=(begin+1)%size;
        queueArray[begin]=value;
        return true;
    }
}

bool CharQueue::isEmpty()
{
    return begin==end;
}
