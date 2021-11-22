#ifndef SMART_MOTOR_H
#define SMART_MOTOR_H

#include <AFMotor.h>
#include <PID_v1.h>

#include "EncoderR.h"

class SmartMotor{
public:
    enum Mode{ //what feedback loop control mode is the motor in
        POSITION, SPEED, FREE
    };

private:
    int lastSpeed;

    uint8_t motorAddress, encoderAddress;

    EncoderR* inputEncoder;
    AF_DCMotor & dcMotor;

    bool isReverse; //is the motor reversed


    //feedback control stuff
    Mode currentMode;

    PID* spdPid;
    PID* posPid;

    double spdSetpoint;
    double spdOutput;
    double spdCurrent;

    double posSetpoint;
    double posOutput;
    double posCurrent;

    double kp_spd, ki_spd, kd_spd; //gain
    double akp_spd, aki_spd, akd_spd; //aggressive gain

    double kp_pos, ki_pos, kd_pos; //gain
    double akp_pos, aki_pos, akd_pos; //aggressive gain

    void iterate(){

    }

public:
    SmartMotor(); //default constructor stub
    SmartMotor(AF_DCMotor& motor, int encoder);
    SmartMotor(AF_DCMotor& motor, int encoder, bool reverse);
    

    //raw
    //-255 backwards full power, 0 stopped, 255 forwards full power
    void setSpeedRaw(int speed);


    //PID stuff
    void setFeedbackMode(Mode mode);
    void setSetpoint();

    void run();

    
};

#endif