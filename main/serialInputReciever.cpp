#include "serialInputReciever.h"

SerialInputReciever &SerialInputReciever::instance()
{
    static SerialInputReciever object;
    return object;
}
