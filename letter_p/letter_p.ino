/**
 * Project Name: DIY Arduino - Project 01: Letter P
 *
 * File Name: letter_p.ino
 *
 * Description: Makes a beautiful effect of letter P
 * LEDs arrangement.
 *    LED_4 LED_5
 *    LED_3 LED_6
 *    LED_2
 *    LED_1
 *
 * Author: Phi Luu
 * Location: Portland, Oregon, United States
 * Created: September 29, 2015
 * Updated: June 22, 2017
 */

// Required hardware I/O connections
const byte LED_1 = 2;          // connect LED 1 to 2
const byte LED_2 = 3;          // connect LED 2 to ~3
const byte LED_3 = 4;          // connect LED 3 to 4
const byte LED_4 = 5;          // connect LED 4 to ~5
const byte LED_5 = 6;          // connect LED 5 to ~6
const byte LED_6 = 7;          // connect LED 6 to 7

// Global constants
const unsigned int TIME = 100; // time to blink between LEDs

void setup() {
    for (byte pin = LED_1; pin <= LED_6; pin++) {
        pinMode(pin, OUTPUT);
    }
}

void loop() {
    // turn off all LEDs
    for (byte pin = LED_1; pin <= LED_6; pin++) {
        digitalWrite(pin, LOW);
    }
    // start with LED_1
    digitalWrite(LED_1, HIGH);
    delay(TIME);

    // create a "running" effect on LEDs
    for (byte pin = LED_1; pin <= LED_5; pin++) {
        digitalWrite(pin,     LOW);  // turn off this LED
        digitalWrite(pin + 1, HIGH); // and turn on next LED
        delay(TIME);                 // turn on for TIME milliseconds
    }
    // when completes letter P, go straight down and repeat it again
    digitalWrite(LED_6, LOW);
    digitalWrite(LED_3, HIGH);
    delay(TIME);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_2, HIGH);
    delay(TIME);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_1, HIGH);
}
