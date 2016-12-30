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
// Updated December 29, 2016
//
//****************************************************************************

#include <Servo.h>          // include Servo library for servo motors
Servo myServo;              // declare myServo

// required hardware I/O connections
const byte potPin = A0;     // connect potentiometer to A0
const byte servoPin = 3;    // connect servo motor to ~3

// baud rate for serial monitor
const unsigned int BAUD_RATE = 9600;

unsigned int potVal;        // the value of potentiometer
unsigned char angle;        // the angle of the servo motor

/**
 * put setup code here, to run once
 * @method setup
 */
void setup() {
    myServo.attach(servoPin);   // attach myServo into servoPin
    Serial.begin(BAUD_RATE);    // start the Serial Monitor
}

/**
 * put main code here, to run repeatedly
 * @method loop
 */
void loop() {
    potVal = analogRead(potPin);            // read potVal from potPin
    Serial.print("potVal: ");
    Serial.print(potVal);                   // print potVal on the Serial Monitor
    angle = map(potVal, 0, 1023, 0, 179);   // map potVal to angle
    Serial.print(", angle: ");
    Serial.print(angle);                    // print angle on the Serial Monitor
    myServo.write(angle);                   // run the servo motor with the angle above
    Serial.println();
    delay(15);                              // delay helps the servo stable
}
