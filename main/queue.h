#ifndef QUEUE
#define QUEUE
#include "new.h"
#include <stdint.h>

class CharQueue
{
    char* queueArray;
    uint16_t size,begin,end;
    uint16_t currentSize();
public:
    CharQueue(uint16_t size);
    ~CharQueue();
    char pop();
    bool push(char);
    bool isEmpty();
};

#endif //QUEUE
