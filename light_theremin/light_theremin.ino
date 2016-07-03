/*******************************************************************************

Arduino Projects Book - Project 06: Light Theremin

Name: light_theremin.ino

Description: Make a light-based theremin using photocells and a buzzer

Compatibility: Arduino UNO R3

Phi Luu
David Douglas High School
Portland, OR
July 03, 2016

*******************************************************************************/

const int sensorPin = A0;     // set sensorPin as A0 alias
const int ledPin = 4;         // set ledPin as 4 alias
const int piezoPin = 2;       // set piezoPin as 2 alias

int sensorValue;        // declare sensorValue
int sensorHigh = 0;     // sensorHigh = 0 as lower bound of the photocell
int sensorLow = 1023;   // sensorLow = 1023 as upper bound of the photocell

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
    int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
    // play the piezo with the pitch above and play for 20 milliseconds
    tone(piezoPin, pitch, 20);
    delay(10);                              // wait 10 milliseconds
}

