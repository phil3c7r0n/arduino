//****************************************************************************
//
// Project Name: Arduino Projects Book - Project 10: Zoetrope
//
// File Name: zoetrope.ino
//
// Description: Control the speed and the direction of the DC motor using
// two switches and a potentiometer
//
// Compatibility: Arduino UNO
//
// Phi Luu
// Portland, Oregon, United States
// Created August 21, 2016
// Updated December 30, 2016
//
//****************************************************************************

//*** Required hardware I/O connections ***
const byte potPin = A0;         // connect potentiometer to A0
const byte icInput1 = 3;        // connect IC Input1 to ~3
const byte icInput2 = 2;        // connect IC Input2 to 2
const byte icEnable1 = 9;       // connect IC Enable1 t ~9
const byte dirSwitch = 4;       // connect direction switch to 4
const byte stateSwitch = 5;     // connect state switch to ~5

//*** Global variables ***
byte stateSwitchVal = 0;        // state switch
byte dirSwitchVal = 0;          // direction switch
byte prevStateSwitchVal = 0;    // previous state switch
byte prevDirSwitchVal = 0;      // previous direction switch
byte motorEnabled = 0;          // whether the motor is on/off
byte motorDirection = 0;        // motor direction
unsigned short motorSpeed = 0;

// Put setup code here, to run once
void setup() {
    pinMode(dirSwitch, INPUT);
    pinMode(stateSwitch, INPUT);
    pinMode(icInput1, OUTPUT);
    pinMode(icInput2, OUTPUT);
    pinMode(icEnable1, OUTPUT);
}

// Put main code here, to run repeatedly
void loop() {
    stateSwitchVal = digitalRead(stateSwitch);
    delay(1);
    dirSwitchVal = digitalRead(dirSwitch);
    motorSpeed = analogRead(potPin) / 4;

    // process the on/off state of the motor from the state switch
    if (stateSwitchVal != prevStateSwitchVal) {
        if (stateSwitchVal) {
            motorEnabled = !motorEnabled;
        }
    }

    // process the direction of the motor from the direction switch
    if (dirSwitchVal != prevDirSwitchVal) {
        if (dirSwitchVal) {
            motorDirection = !motorDirection;
        }
    }

    // control the direction of the motor using the IC
    if (motorDirection) {
        digitalWrite(icInput1, LOW);
        digitalWrite(icInput2, HIGH);
    } else {
        digitalWrite(icInput1, HIGH);
        digitalWrite(icInput2, LOW);
    }

    // control the on/off state of the motor using PWM
    if (motorEnabled) {
        analogWrite(icEnable1, motorSpeed);
    } else {
        analogWrite(icEnable1, 0);
    }

    // prep for next inputs
    prevStateSwitchVal = stateSwitchVal;
    prevDirSwitchVal = dirSwitchVal;
}
