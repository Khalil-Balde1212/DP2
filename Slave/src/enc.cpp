#include <Arduino.h>

#include "enc.h"

void encInit()
{
    oldPosition = -999;
}


long getEncoderTicks()
{
    newPosition = myEnc.read();
    if (newPosition != oldPosition) {
        oldPosition = newPosition;
    }

    return newPosition;

}