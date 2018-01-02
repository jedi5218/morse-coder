#include "morseEncoder.h"
#include "codeTable.h"
#include "debugOutput.h"

void sendSymbol( char symbol, float wordsPerMin )
{
    char input=symbol;
    int dot = 60000 / ( 55.0 * wordsPerMin );

    if( symbol > 0x60 && symbol < 0x80 )
        symbol -= 0x40;
    else
        symbol -= 0x20;

    const char code[ 32 ];
    strcpy_P( code, (char*) pgm_read_word( &( morseAlphabet[symbol] ) ) );
    codeDebugOutput(input,code);
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

