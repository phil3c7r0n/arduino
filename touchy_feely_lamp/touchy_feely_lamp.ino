/**
 * @file     touchy_feely_lamp.ino
 * @author   Phi Luu
 * @date     December 18, 2016
 *
 * @brief    Arduino Projects Book - Project 13: Touchy-feely Lamp
 *
 * @section  DESCRIPTION
 *
 * Uses the capacitance of your body to turn an LED on/off when you touch a
 * piece of conductive material.
 */

#include <CapacitiveSensor.h>

// Required hardware I/O connections
const byte RECEIVING_PIN = 2;  // capacitance receiving pin connected to 2
const byte SENDING_PIN   = 4;  // capacitance sending pin connected to 4
const byte LED_PIN       = 12; // indicator LED pin connected to 12

// CapSensor class
CapacitiveSensor CapSensor = CapacitiveSensor(SENDING_PIN, RECEIVING_PIN);

// Global constants
const int THRESHOLD            = 45; // different people may have different values
const unsigned short BAUD_RATE = 9600;

void setup() {
    Serial.begin(BAUD_RATE);
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    // read 30 samples at a time
    int sensor_val = CapSensor.capacitiveSensor(30);

    Serial.print("Sensor value: ");
    Serial.println(sensor_val);

    // turn on the LED if the capacitance is over the THRESHOLD
    if (sensor_val > THRESHOLD) {
        digitalWrite(LED_PIN, HIGH);
    } else {
        digitalWrite(LED_PIN, LOW);
    }

    // delay helps stabilize the sensor
    delay(10);
}
