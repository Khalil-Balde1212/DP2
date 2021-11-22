#include <Arduino.h>

#include <AFMotor.h>
#include <PID_v1.h>
#include <Math.h>


#include "smartMotor.h"
#include "encoderR.h"

SmartMotor::SmartMotor(AF_DCMotor& motor, int encoderAddress, bool isReverse) : dcMotor(motor){
    this->encoderAddress = encoderAddress;
    this->isReverse = isReverse;

    dcMotor = motor;
    inputEncoder = new EncoderR();

    //init PID controllers
    currentMode = FREE;

    kp_spd = 2; ki_spd = 5; kd_spd = 1; //gain
    akp_spd = 2; aki_spd = 5; akd_spd = 1; //aggressive gain

    spdSetpoint = 0; spdOutput = 0; spdCurrent = 0;

    if(this->isReverse){
        spdPid = new PID(&spdCurrent, &spdOutput, &spdSetpoint,
            kp_spd, ki_spd, kd_spd, REVERSE);
    } else {
        spdPid = new PID(&spdCurrent, &spdOutput, &spdSetpoint,
            kp_spd, ki_spd, kd_spd, DIRECT);
    }
    
    //pos
    kp_pos = 2; ki_pos = 5; kd_pos = 1; //gain
    akp_pos = 2; aki_pos = 5; akd_pos = 1; //aggressive gain

    posSetpoint = 0; posOutput = 0; posCurrent = 0;

    
    if(this->isReverse){
        posPid = new PID(&posCurrent, &posOutput, &posSetpoint,
            kp_pos, ki_pos, kd_pos, REVERSE);
    }else {
        posPid = new PID(&posCurrent, &posOutput, &posSetpoint,
            kp_pos, ki_pos, kd_pos, DIRECT);
    }

    //misc
    lastSpeed = 0;

}

SmartMotor::SmartMotor(AF_DCMotor& motor, int encoderAddress) : dcMotor(motor){
    SmartMotor(motor, encoderAddress, false);
}

void SmartMotor::setSpeedRaw(int speed){
    // if(speed > 255){
    //     speed = 255;
    // } else if(speed < -255){
    //     speed = -255;
    // }
    Serial.println("Setting speed to: ");
	Serial.println(speed);

    // // check if motor switches direction
    // if(speed > 0 && lastSpeed < 0){
    //     dcMotor.run(RELEASE);
    // } else if(speed < 0 && lastSpeed > 0){
    //     dcMotor.run(RELEASE);
    // }
    // set speed

    if(speed > 0){
        dcMotor.setSpeed(speed);
        dcMotor.run(FORWARD);
    } 
    else if(speed < 0){
        dcMotor.setSpeed(-speed);
        dcMotor.run(BACKWARD);
    } else {
        dcMotor.run(RELEASE);
    }

    lastSpeed = speed;
}

