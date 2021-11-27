#include <Arduino.h>
#include <Wire.h>
#include <Encoder.h>

#include "ultrasonic.h"
#include "limitSwitch.h"
#include "enc.h"
#include "motor.h"
#include "commands.h"

void requestEvent();


void setup() {
	Serial.begin(9600);

  	Wire.begin(8);                // join i2c bus with address #8
  	Wire.onRequest(requestEvent); // register event

	ultrasonicInit(); //initialize ultrasonic sensors
	limitSwitchInit();
	encInit();


}

void loop() {
	long startTime = micros();

	pidController.calculate(input);
	obstacleAvoidance();

	while (micros() - startTime < loopInterval) delayMicroseconds(1);
}
