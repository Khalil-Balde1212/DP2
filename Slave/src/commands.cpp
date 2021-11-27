#include <Arduino.h>

#include "commands.h"
#include "limitSwitch.h"
#include "enc.h"
#include "ultrasonic.h"
#include "motor.h"

posPid = new PID(2, 5, 1, minAngle, maxAngle);


void calibrateEncoder(){
    setMotorSpeed(0, 50);
    if(limit1isPressed()){
        setMotorSpeed(0, 0);
        minAngle = getEncoderTicks();
    }

    delay(1000);

    setMotorSpeed(0,-50);
    if(limit2isPressed()){
        setMotorSpeed(0, 0);
        maxAngle = getEncoderTicks();
    }

    setSteeringAngle(0);
}

void setSteeringAngle(int angle){
    posPid->setSetpoint(map(angle, -90, 90, minAngle, maxAngle));
}



void obstacleAvoidance(){
    if(checkFrontDistance() < 10){
        setMotorSpeed(0, 0);
        delay(500);
        
        setMotorSpeed(-100, 0);
        delay(1000);
        
        setSteeringAngle(-45);
    } else {
        setSteeringAngle(0);
        setMotorSpeed(100, 0);
    }
}