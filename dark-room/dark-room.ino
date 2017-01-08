//****************************************************************************
//
// Project Name: DIY Arduino - Project 02: Dark Room
//
// File Name: dark_room.ino
//
// Description: Automatically turn on the LED when it's dark
// Find the light switch when you come home from work at night
//
// Compatibility: Arduino UNO
//
// Phi Luu
// Portland, Oregon, United States
// Created December 13, 2015
// Updated January 07, 2017
//
//****************************************************************************

//***
// Global Declaration
//***

// Required hardware I/O connections
const byte photoPin = A0; // connect photocell to A0
const byte ledPin   = 12; // connect LED to 12

// Global constants
const unsigned short photoThres = 100;

//***
// Mandatory Routines
//***

void setup() {
    pinMode(ledPin, OUTPUT);
}

void loop() {
    int photoVal = analogRead(photoPin);

    // toggle the light based on the threshold of light
    if (photoVal < photoThres) {
        digitalWrite(ledPin, HIGH);
    } else {
        digitalWrite(ledPin, LOW);
    }
}
