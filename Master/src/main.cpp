#include <Arduino.h>
#include <AFMotor.h>

#include <Wire.h>


AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void split(uint32_t);
void setMotor1Speed(int);
void setMotor2Speed(int);

long c = 0;

void setup() {
	// robotStart();
  	Serial.begin(9600);
    Wire.begin();
}


void loop() {
	Wire.requestFrom(8, 1);
	
	c = 0;
    while (Wire.available()) { // slave may send less than requested
    	c += Wire.read();
    }


	split(c);
	delay(50);


}

void setMotor1Speed(int speed) {
	Serial.print("Setting motor1 speed to: "); Serial.println(speed);

	if (speed < 0) {
		motor1.setSpeed(-speed);
		motor1.run(BACKWARD);
	}
	else if (speed > 0) {
		motor1.setSpeed(speed);
		motor1.run(FORWARD);
	}
	else{
		motor1.run(RELEASE);
	}
	
}

void setMotor2Speed(int speed) {
	Serial.print("Setting motor2 speed to: "); Serial.println(speed);

	if (speed < 0) {
		motor2.setSpeed(-speed);
		motor2.run(BACKWARD);
	}
	else if (speed > 0) {
		motor2.setSpeed(speed);
		motor2.run(FORWARD);
	}
	else{
		motor2.run(RELEASE);
	}
}

void split(uint32_t input) {
	unsigned mask;
	mask = (1 << 4) - 1;
	int m1 = input &mask;
	m1 = map(m1, 1, 15, -255, 255);
	setMotor2Speed(m1);

	input = input >> 4;
	int m2 = input &mask;
	m2 = map(m2, 0, 15, -255, 255);
	setMotor1Speed(m2);
}