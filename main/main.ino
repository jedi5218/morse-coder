#include "serialInputReciever.h"
#include "morseEncoder.h"
#include "debugOutput.h"
#include "stream.h"
#include "string.h"

unsigned int outputPin = 2;
Stream& serialStream=Serial;


void setup()
{
    Serial.begin( 9600 );
    pinMode( outputPin, OUTPUT );
    while( !Serial );
    serialStream.println( "Arduino is ready" );
}

void loop()
{
    SerialInputReciever& input = SerialInputReciever :: instance();

    if( input.hasData() )
        sendSymbol( input.pop(), input.outputSpeed() );
}

void serialEvent()
{
    SerialInputReciever :: appendData();
}

