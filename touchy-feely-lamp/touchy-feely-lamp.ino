//****************************************************************************
//
// Project Name: Arduino Projects Book - Project 13: Touchy-feely Lamp
//
// File Name: touchy-feely-lamp.ino
//
// Description: Use the capacitance of your body to turn a LED on/off
// when you touch a piece of conductive material.
//
// Compatibility: Arduino UNO
//
// Phi Luu
// Portland, Oregon, United States
// Created December 18, 2016
// Updated January 07, 2017
//
//****************************************************************************

//***
// Preprocessor Directives
//***

#include <CapacitiveSensor.h>

//***
// Global Declaration
//***

// Required hardware I/O connections
const byte receivingPin = 2;  // capacitance receiving pin connected to 2
const byte sendingPin   = 4;  // capacitance sending pin connected to 4
const byte ledPin       = 12; // indicator LED pin connected to 12

// capSensor class
CapacitiveSensor capSensor = CapacitiveSensor(sendingPin, receivingPin);

// Global constants
const int threshold            = 45; // different people may have different values
const unsigned short BAUD_RATE = 9600;

//***
// Mandatory Routines
//***

void setup() {
    Serial.begin(BAUD_RATE);
    pinMode(ledPin, OUTPUT);
}

void loop() {
    // read 30 samples at a time
    int sensorValue = capSensor.capacitiveSensor(30);

    Serial.print("Sensor value: ");
    Serial.println(sensorValue);

    // turn on the LED if the capacitance is over the threshold
    if (sensorValue > threshold) {
        digitalWrite(ledPin, HIGH);
    } else {
        digitalWrite(ledPin, LOW);
    }

    // delay helps stabilize the sensor
    delay(10);
}
