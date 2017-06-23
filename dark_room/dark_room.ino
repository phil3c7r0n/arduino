/**
 * Project Name: DIY Arduino - Project 02: Dark Room
 *
 * File Name: dark_room.ino
 *
 * Description: Automatically turns on the LED when it's dark.
 *
 * Author: Phi Luu
 * Location: Portland, Oregon, United States
 * Created: December 13, 2015
 * Updated: June 22, 2017
 */

// Required hardware I/O connections
const byte PHOTO_PIN = A0; // connect photocell to A0
const byte LED_PIN   = 2;  // connect LED to 2

// Global constants
const unsigned short THRESHOLD = 100;

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    int photo_val = analogRead(PHOTO_PIN);

    // toggle the light based on the threshold of light
    if (photo_val < THRESHOLD) {
        digitalWrite(LED_PIN, HIGH);
    } else {
        digitalWrite(LED_PIN, LOW);
    }
}
