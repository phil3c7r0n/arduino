//****************************************************************************
//
// Project Name: Arduino Projects Book - Project 07: Keyboard Instrument
//
// File Name: keyboard_instrument.ino
//
// Description: Simulate keys C, D, E, and F of the real piano
// using push buttons and piezo buzzer
//
// Compatibility: Arduino UNO
//
// Phi Luu
// Portland, Oregon, United States
// Created March 05, 2016
// Updated December 31, 2016
//
//****************************************************************************

//***
// Required hardware I/O connections
//***
const byte keyboard = A0;       // connect keyboard to A0
const byte piezoPin = 8;        // connect buzzer to 8

//***
// Global declaration
//***
// Global constants
const int notes[] = { 262, 294, 330, 349 };     // C, D, E, F frequencies
const unsigned int BAUD_RATE = 9600;            // serial monitor's baud rate

// Global variables
unsigned int keyVal;

//***
// Put setup code here, to run once
//***
void setup() {
    Serial.begin(BAUD_RATE);    // start the serial monitor
    pinMode(piezoPin, OUTPUT);  // set piezoPin as OUTPUT
}

//***
// Put main code here, to run repeatedly
//***
void loop() {
    // read and print keyboard value
    keyVal = analogRead(keyboard);
    Serial.print("keyVal = ");
    Serial.println(keyVal);

    if (keyVal == 1023) {
        tone(piezoPin, notes[0]);   // first switch ~ key C
    } else if (keyVal >= 990 && keyVal <= 1010) {
        tone(piezoPin, notes[1]);   // second switch ~ key D
    } else if (keyVal >= 505 && keyVal <= 515) {
        tone(piezoPin, notes[2]);   // third switch ~ key E
    } else if (keyVal >= 5 && keyVal <= 10) {
        tone(piezoPin, notes[3]);   // fourth switch ~ key F
    } else {
        noTone(piezoPin);           // no switch ~ no sound
    }
}
