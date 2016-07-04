/*******************************************************************************

Arduino Projects Book - Project 05: Mood Cue

Name: mood_cue.ino

Description: Express your feeling by a servo motor

Compatibility: Arduino UNO R3

Phi Luu
David Douglas High School
Portland, OR
July 03, 2016

*******************************************************************************/

#include <Servo.h>       // include Servo library for servo motors

Servo myServo;           // declare myServo

//**********Required Hardware I/O Connections**********
const byte potPin = A0;  // connect potentiometer to A0
const byte servoPin = 3; // connect servo motor to ~3

// baud rate for serial monitor
const unsigned int BAUD_RATE = 9600;

unsigned int potVal;     // the value of potentiometer
unsigned char angle;     // the angle of the servo motor

//**********setup**********
// Put setup code here, to run once
// Inputs: None
// Outputs: None
void setup() {
    myServo.attach(servoPin);   // attach myServo into servoPin
    Serial.begin(BAUD_RATE);    // start the Serial Monitor
}

//**********loop**********
// Put main code here, to run repeatedly
// Inputs: None
// Outputs: None
void loop() {
    potVal = analogRead(potPin);  // read potVal from potPin
    Serial.print("potVal: ");
    Serial.print(potVal);         // print potVal on the Serial Monitor
    angle = map(potVal, 0, 1023, 0, 179);   // map potVal to angle
    Serial.print(", angle: ");
    Serial.print(angle);    // print angle on the Serial Monitor
    myServo.write(angle);   // run the servo motor with the angle above
    Serial.println();
    delay(15);              // delay helps the servo stable
}

