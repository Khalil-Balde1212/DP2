#ifndef ENC_H;
#define ENC_H;

#include <Arduino.h>
#include <Encoder.h>

Encoder enc (7, 8);
long oldPosition, newPosition;

void encInit();

long getEncoderTicks();
#endif