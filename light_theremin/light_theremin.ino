/*******************************************************************************

Arduino Projects Book - Project 06: Light Theremin

Name: light_theremin.ino

Description: Make a light-based theremin using photocells and a buzzer

Compatibility: Arduino UNO R3

Phi Luu
David Douglas High School
Portland, OR
Updated July 14, 2016

*******************************************************************************/

//**********Required Hardware I/O Connections**********
const byte sensorPin = A0;     // connect photocell to A0
const byte ledPin = 4;         // connect LED to 4
const byte piezoPin = 2;       // connect buzzer to 2

unsigned int sensorValue;        // declare sensorValue
unsigned int sensorHigh = 0;     // 0 as the initial min of the photocell
unsigned int sensorLow = 1023;   // 1023 as the initial max of the photocell

//**********setup**********
// Put setup code here, to run once
// Inputs: None
// Outputs: None
void setup() {
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH); // red light is turning on - calibrating...
    // calibrate the photocell for 5 seconds
    while (millis() < 5000) {
        sensorValue = analogRead(sensorPin);    // read sensorPin value
        if (sensorValue > sensorHigh) {
            sensorHigh = sensorValue;   // set upper bound of the photocell
        }
        if (sensorValue < sensorLow) {
            sensorLow = sensorValue;    // set lower bound of the photocell
        }
    }
    // calibration completed
    digitalWrite(ledPin, LOW);  // red light turned off
}

//**********loop**********
// Put main code here, to run repeatedly
// Inputs: None
// Outputs: None
void loop() {
    sensorValue = analogRead(sensorPin);    // read sensorPin value again
    // determine the pitch of the piezo
    unsigned int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
    // play the piezo with the pitch above and play for 20 milliseconds
    tone(piezoPin, pitch, 20);
    delay(10);                              // wait 10 milliseconds
}

