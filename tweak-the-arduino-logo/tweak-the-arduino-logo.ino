/**
 * Project Name: Arduino Projects Book - Project 14: Tweak the Arduino Logo
 *
 * File Name: tweak-the-arduino-logo.ino
 *
 * Description: Using serial communication, the Arduino can send and receive
 * information to the computer. Draw the Arduino logo on the computer screen
 * and adjust the background color by the potentiometer
 *
 * Compatibility: Arduino UNO
 *
 * Phi Luu
 * Portland, Oregon, United States
 * Created January 07, 2017
 * Updated January 15, 2017
 */

// Required hardware I/O connections
const byte potPin = A0;      // potentiometer connected to A0

// Global constants
const int BAUD_RATE = 19200; // for serial monitor

void setup() {
    Serial.begin(BAUD_RATE);
}

void loop() {
    // potentiometer reads values from 0 to 1024
    // map it to 0-255 to speed up the communication
    Serial.write(analogRead(potPin) / 4);
    delay(1); // stabilize the pot
}
