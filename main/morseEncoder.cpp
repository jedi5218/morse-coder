#include "morseEncoder.h"
#include "codeTable.h"
#include "HardwareSerial.h"
extern HardwareSerial Serial;

void sendSymbol( char symbol, float wordsPerMin )
{
    Serial.print( "Sending morse code for '" );
    Serial.print( symbol );
    int dot = 60000 / ( 55.0 * wordsPerMin );

    if( symbol > 0x60 && symbol < 0x80 )
        symbol -= 0x40;
    else
        symbol -= 0x20;

    const char code[ 32 ];
    strcpy_P( code, (char*) pgm_read_word( &( morseAlphabet[symbol] ) ) );
    Serial.print( "' wich is " );
    Serial.print( code );
    Serial.print( " dot length: " );
    Serial.println( dot );
    for( unsigned int i = 0; i < strlen( code ); i++)
    {
        switch ( code[i] )
        {
        case ' ':
            digitalWrite( outputPin, LOW );
            delay( dot * 6 );
            break;
        case '.':
            digitalWrite( outputPin, HIGH );
            delay( dot );
            break;
        case '-':
            digitalWrite( outputPin, HIGH );
            delay( dot * 3 );
            break;
        }
        digitalWrite( outputPin, LOW );
        delay( dot );
    }
    digitalWrite( outputPin, LOW );
    delay( dot * 2 );
}

