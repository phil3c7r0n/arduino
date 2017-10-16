/**
 * @file     tweak_the_arduino_logo.ino
 * @author   Phi Luu
 * @date     January 07, 2017
 *
 * @brief    Arduino Projects Book - Project 14: Tweak the Arduino Logo
 *
 * @section  DESCRIPTION
 *
 * Using serial communication, the Arduino can send and receive information to
 * the computer. Draws the Arduino logo on the computer screen and adjust the
 * background color by the potentiometer.
 */

// Required hardware I/O connections
const byte POT_PIN = A0;     // potentiometer connected to A0

// Global constants
const int BAUD_RATE = 19200; // for serial monitor

void setup() {
    Serial.begin(BAUD_RATE);
}

void loop() {
    // potentiometer reads values from 0 to 1024
    // map it to 0-255 to speed up the communication
    Serial.write(analogRead(POT_PIN) / 4);
    delay(1); // stabilize the pot
}
