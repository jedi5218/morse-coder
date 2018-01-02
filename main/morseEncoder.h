#ifndef MORSE_ENCODER
#define MORSE_ENCODER
#include <string.h>
#include "arduino.h"

extern unsigned int outputPin;

void sendSymbol( char symbol, float wordsPerMin );


#endif //MORSE_ENCODER
