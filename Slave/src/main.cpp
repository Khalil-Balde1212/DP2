#include <Arduino.h>
#include <Wire.h>

#include <Encoder.h>


Encoder myEnc(2,3);

void requestEvent();

long oldPosition  = -999;

void setup() {
	Serial.begin(9600);
	Serial.print("Hello");
  	Wire.begin(8);                // join i2c bus with address #8
  	Wire.onRequest(requestEvent); // register event
}

void loop() {
  	long newPosition = myEnc.read();

  	if (newPosition != oldPosition) {
    	oldPosition = newPosition;
    	Serial.println(newPosition);
  	}
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  	Wire.write(convertBinary); // respond with message of 6 bytes
	Serial.println("Sending...");
  // as expected by master
}
int convertBinary(int first, int second, int third) {
    int answer = 0;
    answer += first;
    answer = answer << 9;
    answer += second;
    answer = answer << 9;
    answer += third;

    return answer;
}
