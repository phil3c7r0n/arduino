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
// Updated December 28, 2016
//
//****************************************************************************

//**********Required Hardware I/O Connections**********
const byte switchPin = 2;       // connect switch to 2
const byte motorPin = 9;        // connect dc motor to ~9

//**********setup**********
// Put setup code here, to run once
// Inputs: None
// Outputs: None
void setup() {
    pinMode(switchPin, INPUT);
    pinMode(motorPin, OUTPUT);
}

//**********loop**********
// Put main code here, to run repeatedly
// Inputs: None
// Outputs: None
void loop() {
    byte switchState = digitalRead(switchPin);   // read input from the switch

    // if the switch is pressed
    if (switchState) {
        digitalWrite(motorPin, HIGH);           // spin the motor
    }
    // otherwise
    else {
        digitalWrite(motorPin, LOW);        // cut the power from the motor
    }
}
