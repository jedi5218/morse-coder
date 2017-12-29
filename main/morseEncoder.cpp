#include "morseEncoder.h"

#include "HardwareSerial.h"
extern HardwareSerial Serial;

const PROGMEM char code00[] =  " ";
const PROGMEM char code01[] =  "--..--";
const PROGMEM char code02[] =  ".-..-.";
const PROGMEM char code03[] =  "-. ---";
const PROGMEM char code04[] =  "..- ... --.";
const PROGMEM char code05[] =  ".--. -.-.";
const PROGMEM char code06[] =  ".- -. -..";
const PROGMEM char code07[] =  ".----.";
const PROGMEM char code08[] =  "-.--.-";
const PROGMEM char code09[] =  "-.--.-";
const PROGMEM char code10[] =  "... - .-.";
const PROGMEM char code11[] =  ".--. .-.. ...";
const PROGMEM char code12[] =  ".-.-.-";
const PROGMEM char code13[] =  "-....-";
const PROGMEM char code14[] =  "......";
const PROGMEM char code15[] =  "-..-.";
const PROGMEM char code16[] =  "-----";
const PROGMEM char code17[] =  ".----";
const PROGMEM char code18[] =  "..---";
const PROGMEM char code19[] =  "...--";
const PROGMEM char code20[] =  ".....";
const PROGMEM char code21[] =  "....-";
const PROGMEM char code22[] =  "-....";
const PROGMEM char code23[] =  "--...";
const PROGMEM char code24[] =  "---..";
const PROGMEM char code25[] =  "----.";
const PROGMEM char code26[] =  "---...";
const PROGMEM char code27[] =  "-.-.-.";
const PROGMEM char code28[] =  ".-..";
const PROGMEM char code29[] =  ". --.-";
const PROGMEM char code30[] =  "--. -";
const PROGMEM char code31[] =  "..--..";
const PROGMEM char code32[] =  ".--.-.";
const PROGMEM char code33[] =  ".-";
const PROGMEM char code34[] =  "-...";
const PROGMEM char code35[] =  "-.-.";
const PROGMEM char code36[] =  "-..";
const PROGMEM char code37[] =  ".";
const PROGMEM char code38[] =  "..-.";
const PROGMEM char code39[] =  "--.";
const PROGMEM char code40[] =  "....";
const PROGMEM char code41[] =  "..";
const PROGMEM char code42[] =  ".---";
const PROGMEM char code43[] =  "-.-";
const PROGMEM char code44[] =  ".-..";
const PROGMEM char code45[] =  "--";
const PROGMEM char code46[] =  "-.";
const PROGMEM char code47[] =  "---";
const PROGMEM char code48[] =  ".--.";
const PROGMEM char code49[] =  "--.-";
const PROGMEM char code50[] =  ".-.";
const PROGMEM char code51[] =  "...";
const PROGMEM char code52[] =  "-";
const PROGMEM char code53[] =  "..-";
const PROGMEM char code54[] =  "...-";
const PROGMEM char code55[] =  ".--";
const PROGMEM char code56[] =  "-..-";
const PROGMEM char code57[] =  "-.--";
const PROGMEM char code58[] =  "--..";
const PROGMEM char code59[] =  "-.--.-";
const PROGMEM char code60[] =  "-..-.";
const PROGMEM char code61[] =  "-.--.-";
const PROGMEM char code62[] =  "-.-. ..-. -..-";
const PROGMEM char code63[] =  "-....-";
const PROGMEM char code64[] =  ".----.";
const PROGMEM char code65[] =  "-....-";
const PROGMEM char code66[] =  "........";

const char* const morseAlphabet[] PROGMEM = {
    code00,
    code01,
    code02,
    code03,
    code04,
    code05,
    code06,
    code07,
    code08,
    code09,
    code10,
    code11,
    code12,
    code13,
    code14,
    code15,
    code16,
    code17,
    code18,
    code19,
    code20,
    code21,
    code22,
    code23,
    code24,
    code25,
    code26,
    code27,
    code28,
    code29,
    code30,
    code31,
    code32,
    code33,
    code34,
    code35,
    code36,
    code37,
    code38,
    code39,
    code40,
    code41,
    code42,
    code43,
    code44,
    code45,
    code46,
    code47,
    code48,
    code49,
    code50,
    code51,
    code52,
    code53,
    code54,
    code55,
    code56,
    code57,
    code58,
    code59,
    code60,
    code61,
    code62,
    code63,
    code64,
    code65,
    code66
};


void sendSymbol(char symbol,float wordsPerMin)
{
    Serial.print("Sending morse code for '");
    Serial.print(symbol);
    int dot=60000/(55*wordsPerMin);

    if(symbol>0x60&&symbol<0x80)
        symbol-=0x40;
    else
        symbol-=0x20;

    const char code[32];
    strcpy_P(code, (char*)pgm_read_word(&(morseAlphabet[symbol]))); // необходимые функции и расшифровки, просто скопируйте

    Serial.print("' wich is ");
    Serial.print(code);
    Serial.print(" dot length: ");
    Serial.println(dot);
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

