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
// Updated December 31, 2016
//
//****************************************************************************

//***
// Required hardware I/O connections
//***
const byte photoPin = A0;       // connect photocell to A0
const byte ledPin = 12;         // connect LED to 12

//***
// Global declaration
//***
// Global constants
const unsigned short photoThres = 100;

//***
// Put setup code here, to run once
//***
void setup() {
    pinMode(ledPin, OUTPUT);
}

//***
// Put main code here, to run repeatedly
//***
void loop() {
    int photoVal = analogRead(photoPin);

    // toggle the light based on the threshold of light
    if (photoVal < photoThres) {
        digitalWrite(ledPin, HIGH);
    } else {
        digitalWrite(ledPin, LOW);
    }
}
