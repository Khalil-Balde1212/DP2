#ifndef COMMANDS_H
#define COMMANDS_H

#include <pidcontroller.h>

long maxAngle, minAngle;
PID *posPid;


void calibrateEncoder();

void obstacleAvoidance();

void setSteeringAngle(int angle); //an angle between 90, -90
#endif