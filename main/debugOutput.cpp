#include "debugOutput.h"

#include "stream.h"
extern Stream& serialStream;


void setSpeedDebugOutput(float speed)
{
#ifdef ENABLE_DEBUG_OUTPUT
    serialStream.print( "Speed set to: " );
    serialStream.println( speed );
#endif
}

void overflowErrorDebugOutput()
{
#ifdef ENABLE_DEBUG_OUTPUT
    serialStream.println( "OVERFLOW size limit of the queue reached." );
#endif
}

void codeDebugOutput(char inputSymbol, char *code)
{
#ifdef ENABLE_DEBUG_OUTPUT
    serialStream.print( "Sending morse code for '" );
    serialStream.print( inputSymbol );
    serialStream.print( "' wich is " );
    serialStream.println( code );
#endif
}
