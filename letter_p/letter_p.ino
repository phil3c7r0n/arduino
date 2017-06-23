/**
 * Project Name: DIY Arduino - Project 01: Letter P
 *
 * File Name: letter_p.ino
 *
 * Description: Makes a beautiful effect of letter P
 * LEDs arrangement.
 *    led_4 led_5
 *    led_3 led_6
 *    led_2
 *    led_1
 *
 * Author: Phi Luu
 * Location: Portland, Oregon, United States
 * Created: September 29, 2015
 * Updated: June 22, 2017
 */

// Required hardware I/O connections
const byte led_1 = 2;          // connect LED 1 to 2
const byte led_2 = 3;          // connect LED 2 to ~3
const byte led_3 = 4;          // connect LED 3 to 4
const byte led_4 = 5;          // connect LED 4 to ~5
const byte led_5 = 6;          // connect LED 5 to ~6
const byte led_6 = 7;          // connect LED 6 to 7

// Global constants
const unsigned int TIME = 100; // time to blink between LEDs

void setup() {
    for (byte pin = led_1; pin <= led_6; pin++) {
        pinMode(pin, OUTPUT);
    }
}

void loop() {
    // turn off all LEDs
    for (byte pin = led_1; pin <= led_6; pin++) {
        digitalWrite(pin, LOW);
    }
    // start with led_1
    digitalWrite(led_1, HIGH);
    delay(TIME);

    // create a "running" effect on LEDs
    for (byte pin = led_1; pin <= led_5; pin++) {
        digitalWrite(pin,     LOW);  // turn off this LED
        digitalWrite(pin + 1, HIGH); // and turn on next LED
        delay(TIME);                 // turn on for TIME milliseconds
    }
    // when completes letter P, go straight down and repeat it again
    digitalWrite(led_6, LOW);
    digitalWrite(led_3, HIGH);
    delay(TIME);
    digitalWrite(led_3, LOW);
    digitalWrite(led_2, HIGH);
    delay(TIME);
    digitalWrite(led_2, LOW);
    digitalWrite(led_1, HIGH);
}
