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
// Updated January 07, 2017
//
//****************************************************************************

//***
// Global Declaration
//***

// Required hardware I/O connections
const byte sensorPin = A0; // connect photocell to A0
const byte piezoPin  = 2;  // connect buzzer to 2
const byte ledPin    = 4;  // connect LED to 4

// Global variables
unsigned int sensorValue;
unsigned int sensorHigh = 0;    // initial min of the photocell
unsigned int sensorLow  = 1023; // initial max of the photocell

//***
// Mandatory Routines
//***

void setup() {
    pinMode(piezoPin, OUTPUT);
    pinMode(ledPin,   OUTPUT);
    // calibrate the photocell for 5 seconds - red light turned on
    digitalWrite(ledPin, HIGH);

    while (millis() < 5000) {
        sensorValue = analogRead(sensorPin);

        if (sensorValue > sensorHigh) {
            sensorHigh = sensorValue; // set new max value
        }

        if (sensorValue < sensorLow) {
            sensorLow = sensorValue; // set new min value
        }
    }
    // calibration completed - red light turned off
    digitalWrite(ledPin, LOW);
}

void loop() {
    sensorValue = analogRead(sensorPin);
    // determine the pitch of the piezo
    unsigned int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
    // play the piezo with the pitch for 20 milliseconds
    tone(piezoPin, pitch, 20);
    // wait 10ms for the sensor to stabilize
    delay(10);
}
