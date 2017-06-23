/**
 * Project Name: Arduino Projects Book - Project 07: Keyboard Instrument
 *
 * File Name: keyboard_instrument.ino
 *
 * Description: Simulates keys C, D, E, and F of the real piano
 * using push buttons and piezo buzzer.
 *
 * Author: Phi Luu
 * Location: Portland, Oregon, United States
 * Created: March 05, 2016
 * Updated: June 22, 2017
 */

// Required hardware I/O connections
const byte keyboard = A0;                   // connect keyboard to A0
const byte piezo_pin = 8;                    // connect buzzer to 8

// Global constants
const int NOTES[] = { 262, 294, 330, 349 }; // C, D, E, F frequencies
const unsigned int BAUD_RATE = 9600;        // serial monitor's baud rate

// Global variables
unsigned int key_val;

void setup() {
    Serial.begin(BAUD_RATE);   // start the serial monitor
    pinMode(piezo_pin, OUTPUT); // set piezo_pin as OUTPUT
}

void loop() {
    // read and print keyboard value
    key_val = analogRead(keyboard);
    Serial.print("key_val = ");
    Serial.println(key_val);

    if (key_val == 1023) {
        tone(piezo_pin, NOTES[0]); // first switch ~ key C
    } else if ((key_val >= 990) && (key_val <= 1010)) {
        tone(piezo_pin, NOTES[1]); // second switch ~ key D
    } else if ((key_val >= 505) && (key_val <= 515)) {
        tone(piezo_pin, NOTES[2]); // third switch ~ key E
    } else if ((key_val >= 5) && (key_val <= 10)) {
        tone(piezo_pin, NOTES[3]); // fourth switch ~ key F
    } else {
        noTone(piezo_pin);         // no switch ~ no sound
    }
}
