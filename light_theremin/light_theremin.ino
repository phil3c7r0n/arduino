/**
 * Project Name: Arduino Projects Book - Project 06: Light Theremin
 *
 * File Name: light_theremin.ino
 *
 * Description: Makes a light-based theremin using photocells and a buzzer.
 *
 * Author: Phi Luu
 * Location: Portland, Oregon, United States
 * Created: January 10, 2016
 * Updated: June 22, 2017
 */

// Required hardware I/O connections
const byte sensor_pin = A0; // connect photocell to A0
const byte piezo_pin  = 2;  // connect buzzer to 2
const byte led_pin    = 4;  // connect LED to 4

// Global variables
unsigned int sensor_val;
unsigned int sensor_high = 0;    // initial min of the photocell
unsigned int sensor_low  = 1023; // initial max of the photocell

void setup() {
    pinMode(piezo_pin, OUTPUT);
    pinMode(led_pin,   OUTPUT);
    // calibrate the photocell for 5 seconds - red light turned on
    digitalWrite(led_pin, HIGH);

    while (millis() < 5000) {
        sensor_val = analogRead(sensor_pin);

        if (sensor_val > sensor_high) {
            sensor_high = sensor_val; // set new max value
        }

        if (sensor_val < sensor_low) {
            sensor_low = sensor_val; // set new min value
        }
    }
    // calibration completed - red light turned off
    digitalWrite(led_pin, LOW);
}

void loop() {
    sensor_val = analogRead(sensor_pin);
    // determine the pitch of the piezo
    unsigned int pitch = map(sensor_val, sensor_low, sensor_high, 50, 4000);
    // play the piezo with the pitch for 20 milliseconds
    tone(piezo_pin, pitch, 20);
    // wait 10ms for the sensor to stabilize
    delay(10);
}
