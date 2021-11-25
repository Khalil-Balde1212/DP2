#include <Arduino.h>
#include <AFMotor.h>

#include <Wire.h>

#include "robot.h"
#include "smartMotor.h"


AF_DCMotor motor1(1);

AF_DCMotor motor2(2);

void setup() {
	// robotStart();
  	Serial.begin(9600);
    Wire.begin();

}


void loop() {
	// Serial.println("Hello!");
	Wire.requestFrom(27, 6);
	unint32_t c;
    while (Wire.available()) { // slave may send less than requested
        c = Wire.read(); // receive a byte as character
        Serial.print(c);         // print the character
    }
	split(c);
	// Serial.println("Hello2");
	delay(500);
}

void setMotor1Speed(int speed) {
	if (speed < 0) {
		motor1.setSpeed(speed);
		motor1.run(BACKWARD);
	}
	else if (speed > 0) {
		motor1.setSpeed(speed);
		motor1.run(FORWARD);
	}
	else
		motor1.run(RELEASE);
	
}
void setMotor2Speed(int speed) {
	if (speed < 0) {
		motor2.setSpeed(speed);
		motor2.run(BACKWARD);
	}
	else if (speed > 0) {
		motor2.setSpeed(speed);
		motor2.run(FORWARD);
	}
	else
		motor2.run(RELEASE);

}
void split(uint32_t input) {
	unsigned mask;
	mask = (1 << 9) - 1;
	c = input & mask;

	input = input >> 9;
	setMotor2Speed(input & mask);

	input = input >> 9;
	setMotor1Speed(input & mask);
}