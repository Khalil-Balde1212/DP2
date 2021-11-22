#include <Arduino.h>
#include <Wire.h>

#include "smartMotor.h"
#include "robot.h"

AF_DCMotor motorRaw1(3);
AF_DCMotor motorRaw2(2);
SmartMotor motor1(motorRaw1, 0);
SmartMotor motor2(motorRaw2, 0);

void robotStart(){
}

void run(){
	motor1.setSpeedRaw(255);
	motor2.setSpeedRaw(0);
	delay(1000);
	motor1.setSpeedRaw(0);
	motor2.setSpeedRaw(255);
	delay(1000);
	motor1.setSpeedRaw(-255);
	motor2.setSpeedRaw(0);
	delay(1000);
	motor1.setSpeedRaw(0);
	motor2.setSpeedRaw(-255);
	delay(1000);
}

double getEncoderValue(){
    

    return 0;
}