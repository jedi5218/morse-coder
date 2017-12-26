#ifndef MORSE_ENCODER
#define MORSE_ENCODER
#include <cstring>

 extern unsigned int signalLED;
#include "CDCSerialClass.h"
extern CDCSerialClass Serial;
const PROGMEM char* morseAlphabet[] = {
    " ",//0x20
    "--..--",
    ".-..-.",
    "-. ---",
    "..- ... --.",
    ".--. -.-.",
    ".- -. -..",
    ".----.",
    "-.--.-",
    "-.--.-",
    "... - .-.",
    ".--. .-.. ...",
    ".-.-.-",
    "-....-",
    "......",
    "-..-.",
    "-----",//0x30, 0
    ".----",//1
    "..---",
    "...--",
    ".....",
    "....-",
    "-....",
    "--...",
    "---..",
    "----.",//9
    "---...",
    "-.-.-.",
    ".-..",
    ". --.-",
    "--. -",
    "..--..",
    ".--.-.",//0x40
    ".-",//A
    "-...",
    "-.-.",
    "-..",
    ".",
    "..-.",
    "--.",
    "....",
    "..",
    ".---",
    "-.-",
    ".-..",
    "--",
    "-.",
    "---",
    ".--.",//0x50
    "--.-",
    ".-.",
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    "-..-",
    "-.--",
    "--..",//Z
    "-.--.-",
    "-..-.",
    "-.--.-",
    "-.-. ..-. -..-",
    "-....-",
    ".----.",//0x60
    "-....-",
    "........"//0x7f
    //TODO: fill the remains of the table
};

void encodeSymbol(char symbol,float wordsPerMin)
{
    int dot=60000/(55*wordsPerMin);

    if(symbol>0x60&&symbol<0x80)
        symbol-=0x40;
    else
        symbol-=0x20;

    const char* code=morseAlphabet[symbol];
    for(unsigned int i=0;i<strlen(code);i++)
    {
        switch (code[i])
        {
        case ' ':
            digitalWrite(signalLED,LOW);
            delay(dot*6);
            break;
        case '.':
            digitalWrite(signalLED,HIGH);
            delay(dot);
            break;
        case '-':
            digitalWrite(signalLED,HIGH);
            delay(dot*3);
            break;
        }
        digitalWrite(signalLED,LOW);
        delay(dot);
    }
    digitalWrite(signalLED,LOW);
    delay(dot*2);
}

#endif //MORSE_ENCODER
