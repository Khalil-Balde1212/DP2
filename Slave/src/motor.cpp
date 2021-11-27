#include "motor.h"

#include <Wire.h>

uint32_t convertBinary(uint32_t first, uint32_t second){
	answer = 0;
    answer += first;
    answer = answer << 4;
    answer += second;

    return answer;
}

//between -100, 100
void setMotorSpeed(int first, int second){
    m1speed = map(first, -100, 100, 1, 7);
    m2speed = map(second, -100, 100, 1, 7);
}


void requestEvent() {
	Wire.write(convertBinary(m1speed, m2speed));
	Serial.print("Sending! ");  Serial.println(convertBinary(m1speed, m2speed));
}