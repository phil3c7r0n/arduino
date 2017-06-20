/**
 * Project Name: DIY Arduino - Project 02: Dark Room
 *
 * File Name: dark_room.ino
 *
 * Description: Automatically turn on the LED when it's dark
 * Find the light switch when you come home from work at night
 *
 * Compatibility: Arduino UNO
 *
 * Phi Luu
 * Portland, Oregon, United States
 * Created December 13, 2015
 * Updated June 20, 2017
 */

// Required hardware I/O connections
const byte photoPin = A0; // connect photocell to A0
const byte ledPin   = 2;  // connect LED to 2

// Global constants
const unsigned short photoThres = 100;

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
