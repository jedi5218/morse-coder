#ifndef QUEUE
#define QUEUE
#include "new.h"
#include <stdint.h>

#define QUEUE_SIZE 255
class CharQueue
{
    char queueArray[QUEUE_SIZE];
    uint16_t begin,end;
    uint16_t currentSize();
public:
    CharQueue();
    ~CharQueue();
    char pop();
    bool push(char);
    bool isEmpty();
};

#endif //QUEUE
