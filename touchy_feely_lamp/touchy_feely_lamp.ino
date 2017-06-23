/**
 * Project Name: Arduino Projects Book - Project 13: Touchy-feely Lamp
 *
 * File Name: touchy_feely_lamp.ino
 *
 * Description: Uses the capacitance of your body to turn an LED on/off
 * when you touch a piece of conductive material.
 *
 * Author: Phi Luu
 * Location: Portland, Oregon, United States
 * Created: December 18, 2016
 * Updated: June 22, 2017
 */

#include <CapacitiveSensor.h>

// Required hardware I/O connections
const byte receiving_pin = 2;  // capacitance receiving pin connected to 2
const byte sending_pin   = 4;  // capacitance sending pin connected to 4
const byte led_pin       = 12; // indicator LED pin connected to 12

// CapSensor class
CapacitiveSensor CapSensor = CapacitiveSensor(sending_pin, receiving_pin);

// Global constants
const int THRESHOLD            = 45; // different people may have different values
const unsigned short BAUD_RATE = 9600;

void setup() {
    Serial.begin(BAUD_RATE);
    pinMode(led_pin, OUTPUT);
}

void loop() {
    // read 30 samples at a time
    int sensor_val = CapSensor.capacitiveSensor(30);

    Serial.print("Sensor value: ");
    Serial.println(sensor_val);

    // turn on the LED if the capacitance is over the THRESHOLD
    if (sensor_val > THRESHOLD) {
        digitalWrite(led_pin, HIGH);
    } else {
        digitalWrite(led_pin, LOW);
    }

    // delay helps stabilize the sensor
    delay(10);
}
