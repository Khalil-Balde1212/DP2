#include <Arduino.h>
#include <AFMotor.h>

#include <Wire.h>

#include "robot.h"
#include "smartMotor.h"

void setup() {
	// robotStart();
  	Serial.begin(9600);
    Wire.begin();

}

void loop() {
	// Serial.println("Hello!");
	Wire.requestFrom(8, 6);

    while (Wire.available()) { // slave may send less than requested
		// Serial.println("I am reading");
        char c = Wire.read(); // receive a byte as character
        Serial.print(c);         // print the character
    }
	// Serial.println("Hello2");
	delay(500);
}