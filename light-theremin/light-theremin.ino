//****************************************************************************
//
// Project Name: Arduino Projects Book - Project 06: Light Theremin
//
// File Name: light_theremin.ino
//
// Description: Make a light-based theremin using photocells and a buzzer
//
// Compatibility: Arduino UNO
//
// Phi Luu
// Portland, Oregon, United States
// Created January 10, 2016
// Updated December 29, 2016
//
//****************************************************************************

// required hardware I/O connections
const byte sensorPin = A0;      // connect photocell to A0
const byte ledPin = 4;          // connect LED to 4
const byte piezoPin = 2;        // connect buzzer to 2

unsigned int sensorValue;       // declare sensorValue
unsigned int sensorHigh = 0;    // 0 as the initial min of the photocell
unsigned int sensorLow = 1023;  // 1023 as the initial max of the photocell

/**
 * put setup code here, to run once
 * @method setup
 */
void setup() {
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH); // red light is turning on - calibrating...
    // calibrate the photocell for 5 seconds
    while (millis() < 5000) {
        sensorValue = analogRead(sensorPin);    // read sensorPin value
        if (sensorValue > sensorHigh) {
            sensorHigh = sensorValue;           // set upper bound of the photocell
        }
        if (sensorValue < sensorLow) {
            sensorLow = sensorValue;            // set lower bound of the photocell
        }
    }
    // calibration completed
    digitalWrite(ledPin, LOW);                  // red light turned off
}

/**
 * put main code here, to run repeatedly
 * @method loop
 */
void loop() {
    sensorValue = analogRead(sensorPin);    // read sensorPin value again
    // determine the pitch of the piezo
    unsigned int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
    // play the piezo with the pitch above and play for 20 milliseconds
    tone(piezoPin, pitch, 20);
    delay(10);                              // wait 10 milliseconds
}
