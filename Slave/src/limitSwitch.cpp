#include <Arduino.h>

#include "limitSwitch.h"

const int L_SWITCH1 = 9;
const int L_SWITCH2 = 10;

void limitSwitchInit(){
    pinMode(L_SWITCH1, INPUT); 
    pinMode(L_SWITCH2, INPUT); 
}

bool limit1isPressed(){
    return digitalRead(L_SWITCH1) == HIGH;
}


bool limit2isPressed(){
    return digitalRead(L_SWITCH2) == HIGH;
}