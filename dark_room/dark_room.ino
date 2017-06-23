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
const byte photo_pin = A0; // connect photocell to A0
const byte led_pin   = 2;  // connect LED to 2

// Global constants
const unsigned short PHOTO_THRESHOLD = 100;

void setup() {
    pinMode(led_pin, OUTPUT);
}

void loop() {
    int photo_val = analogRead(photo_pin);

    // toggle the light based on the threshold of light
    if (photo_val < PHOTO_THRESHOLD) {
        digitalWrite(led_pin, HIGH);
    } else {
        digitalWrite(led_pin, LOW);
    }
}
