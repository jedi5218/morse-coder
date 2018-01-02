#include "debugOutput.h"

#ifdef ENABLE_DEBUG_OUTPUT
    #include "stream.h"
    extern Stream& serialStream;
#endif

void setSpeedDebugOutput(float speed)
{
#ifdef ENABLE_DEBUG_OUTPUT
    Serial.print( "Speed set to: " );
    Serial.println( speed );
#endif
}

void overflowErrorDebugOutput()
{
#ifdef ENABLE_DEBUG_OUTPUT
    Serial.println( "OVERFLOW size limit of the queue reached." );
#endif
}

void codeDebugOutput(char inputSymbol, char *code)
{
#ifdef ENABLE_DEBUG_OUTPUT
    Serial.print( "Sending morse code for '" );
    Serial.print( inputSymbol );
    Serial.print( "' wich is " );
    Serial.println( code );
#endif
}
