//****************************************************************************
//
// Project Name: Arduino Projects Book - Project 09: Motorized Pinwheel
//
// File Name: motorized-pinwheel.ino
//
// Description: Get the Arduino to spin a colorful pinwheel using a motor
//
// Compatibility: Arduino UNO
//
// Phi Luu
// Portland, Oregon, United States
// Created August 13, 2016
// Updated January 07, 2017
//
//****************************************************************************

//***
// Global Declaration
//***

// Required hardware I/O connections
const byte switchPin = 2; // connect switch to 2
const byte motorPin  = 9; // connect dc motor to ~9

//***
// Mandatory Routines
//***

void setup() {
    pinMode(switchPin, INPUT);
    pinMode(motorPin,  OUTPUT);
}

void loop() {
    byte switchState = digitalRead(switchPin);

    // toggle the switch to toggle the motor
    if (switchState) {
        digitalWrite(motorPin, HIGH);
    } else {
        digitalWrite(motorPin, LOW);
    }
}
