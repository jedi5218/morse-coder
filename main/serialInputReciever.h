#ifndef SERIAL_INPUT_RECIEVER
#define SERIAL_INPUT_RECIEVER

#include <queue>
#include <map>

class SerialInputReciever
{
    std::queue<char> queue;
public:
    static SerialInputReciever& instance();
    static void appendData();
    char pop();
private:
    SerialInputReciever();
//    SerialInputReciever(const SerialInputReciever& root) = delete;
//    SerialInputReciever(const SerialInputReciever&& moved) = delete;
//    SerialInputReciever& operator=(const SerialInputReciever&) = delete;
//    SerialInputReciever& operator=(const SerialInputReciever&) = delete;
};


#endif //SERIAL_INPUT_RECIEVER


