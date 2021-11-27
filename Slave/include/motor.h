#ifndef MOTOR_H
#define MOTOR_H

uint32_t m1speed;
uint32_t m2speed;
uint32_t answer;

uint32_t convertBinary(uint32_t first, uint32_t second);

void setMotorSpeed(int first, int second);

void onRequest();

#endif
