/**
 * @file     dark_room.ino
 * @author   Phi Luu
 * @date     December 13, 2015
 *
 * @brief    DIY Arduino - Project 02: Dark Room
 *
 * @section  DESCRIPTION
 *
 * Automatically turns on the LED when it's dark.
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
