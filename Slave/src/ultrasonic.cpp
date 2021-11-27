#include <Arduino.h>

#include "ultrasonic.h"

const int SIDE_ECHO = 2;
const int SIDE_TRIG = 3;

const int FRONT_ECHO = 4;
const int FRONT_TRIG = 5;

float duration1, distance1;
float duration2, distance2;

void ultrasonicInit(){
    //front ultrasonic
    pinMode(SIDE_TRIG, OUTPUT);
    pinMode(SIDE_ECHO, INPUT);

    //side ultrasonic
    pinMode(FRONT_TRIG, OUTPUT);
    pinMode(FRONT_TRIG, INPUT);
};

float checkFrontDistance(){
    digitalWrite(FRONT_TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(FRONT_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(FRONT_TRIG, LOW);

    duration1 = pulseIn(FRONT_ECHO, HIGH);

    //Calculate the distance
    distance1 = duration1 / 29 / 2; //Computation to print the distance in cm
    return distance1;
}

float checkSideDistance(){
    digitalWrite(SIDE_TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(SIDE_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(SIDE_TRIG, LOW);

    duration2 = pulseIn(SIDE_ECHO,HIGH);

    //Calculate the distance
    distance2 = duration2 / 29 / 2; //Computation to print the distance in cm
    return distance2;
}