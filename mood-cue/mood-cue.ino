//****************************************************************************
//
// Project Name: Arduino Projects Book - Project 05: Mood Cue
//
// File Name: mood_cue.ino
//
// Description: Express your feeling by a servo motor
//
// Compatibility: Arduino UNO
//
// Phi Luu
// Portland, Oregon, United States
// Created November 21, 2015
// Updated January 07, 2017
//
//****************************************************************************

//***
// Preprocessor Directives
//***

#include <Servo.h> // include Servo library for servo motors

//***
// Global Declaration
//***

// Required hardware I/O connections
const byte potPin   = A0;            // connect potentiometer to A0
const byte servoPin = 3;             // connect servo motor to ~3

// Servo class
Servo myServo;                       // declare myServo

// Global constants
const unsigned int BAUD_RATE = 9600; // serial monitor's baud rate

// Global variables
unsigned int  potVal;                // potentiometer
unsigned char angle;                 // servo's angle

//***
// Mandatory Routines
//***

void setup() {
    myServo.attach(servoPin); // attach myServo into servoPin
    Serial.begin(BAUD_RATE);  // start the Serial Monitor
}

void loop() {
    // read & print potentiometer value
    potVal = analogRead(potPin);
    Serial.print("potVal: ");
    Serial.print(potVal);
    // map & print from pot value to angle
    angle = map(potVal, 0, 1023, 0, 179);
    Serial.print(", angle: ");
    Serial.println(angle);
    // run the servo by the angle
    myServo.write(angle);
    // delay to stabilize
    delay(15);
}
