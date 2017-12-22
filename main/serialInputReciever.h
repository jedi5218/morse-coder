#ifndef SERIAL_INPUT_RECIEVER
#define SERIAL_INPUT_RECIEVER

#include <stack>

class SerialInputReciever
{
    std::stack<char> stack;
    SerialInputReciever(){}
public:
    static SerialInputReciever& instance();
    void encodeSymbol;
    void appendData();
};


#endif SERIAL_INPUT_RECIEVER


