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
const byte SENSOR_PIN = A0; // connect photocell to A0
const byte PIEZO_PIN  = 2;  // connect buzzer to 2
const byte LED_PIN    = 4;  // connect LED to 4

// Global variables
unsigned int sensor_val;
unsigned int sensor_high = 0;    // initial min of the photocell
unsigned int sensor_low  = 1023; // initial max of the photocell

void setup() {
    pinMode(PIEZO_PIN, OUTPUT);
    pinMode(LED_PIN,   OUTPUT);
    // calibrate the photocell for 5 seconds - red light turned on
    digitalWrite(LED_PIN, HIGH);

    while (millis() < 5000) {
        sensor_val = analogRead(SENSOR_PIN);

        if (sensor_val > sensor_high) {
            sensor_high = sensor_val; // set new max value
        }

        if (sensor_val < sensor_low) {
            sensor_low = sensor_val; // set new min value
        }
    }
    // calibration completed - red light turned off
    digitalWrite(LED_PIN, LOW);
}

void loop() {
    sensor_val = analogRead(SENSOR_PIN);
    // determine the pitch of the piezo
    unsigned int pitch = map(sensor_val, sensor_low, sensor_high, 50, 4000);
    // play the piezo with the pitch for 20 milliseconds
    tone(PIEZO_PIN, pitch, 20);
    // wait 10ms for the sensor to stabilize
    delay(10);
}
