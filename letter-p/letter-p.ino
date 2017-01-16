/**
 * Project Name: DIY Arduino - Project 01: Letter P
 *
 * File Name: letter_p.ino
 *
 * Description: Make a beautiful effect of letter P
 * LEDs arrangement
 *    LED4 LED5
 *    LED3 LED6
 *    LED2
 *    LED1
 *
 * Compatibility: Arduino UNO
 *
 * Phi Luu
 * Portland, Oregon, United States
 * Created September 29, 2015
 * Updated January 15, 2017
 */

// Required hardware I/O connections
const byte LED1 = 2;           // connect LED 1 to 2
const byte LED2 = 3;           // connect LED 2 to ~3
const byte LED3 = 4;           // connect LED3 to 4
const byte LED4 = 5;           // connect LED4 to ~5
const byte LED5 = 6;           // connect LED5 to ~6
const byte LED6 = 7;           // connect LED6 to 7

// Global constants
const unsigned int TIME = 100; // time to blink between LEDs

void setup() {
    for (byte pinNumber = LED1; pinNumber <= LED6; pinNumber++) {
        pinMode(pinNumber, OUTPUT);
    }
}

void loop() {
    // turn off all LEDs
    for (byte pinNumber = LED1; pinNumber <= LED6; pinNumber++) {
        digitalWrite(pinNumber, LOW);
    }
    // start with LED1
    digitalWrite(LED1, HIGH);
    delay(TIME);

    // create a "running" effect on LEDs
    for (byte pinNumber = LED1; pinNumber <= LED5; pinNumber++) {
        digitalWrite(pinNumber,     LOW);  // turn off this LED
        digitalWrite(pinNumber + 1, HIGH); // and turn on next LED
        delay(TIME);                       // turn on for TIME milliseconds
    }
    // when completes letter P, go straight down and repeat it again
    digitalWrite(LED6, LOW);
    digitalWrite(LED3, HIGH);
    delay(TIME);
    digitalWrite(LED3, LOW);
    digitalWrite(LED2, HIGH);
    delay(TIME);
    digitalWrite(LED2, LOW);
    digitalWrite(LED1, HIGH);
}
