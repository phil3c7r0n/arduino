//****************************************************************************
//
// Project Name: Arduino Projects Book - Project 12: Knock Lock
//
// File Name: knock-lock.ino
//
// Description: Using the Piezo buzzer to make a secret locking mechanism, in
// order to keep intruders out
//
// Compatibility: Arduino UNO
//
// Phi Luu
// Portland, Oregon, United States
// Created September 06, 2016
// Updated December 28, 2016
//
//****************************************************************************

#include <Servo.h>
Servo servoMotor;

// required hardware I/O connections
const byte switchPin = 2;       // the pin switch connected to
const byte yellowLEDPin = 3;    // the pin yellow LED connected to
const byte greenLEDPin = 4;     // the pin green LED connnected to
const byte redLEDPin = 5;       // the pin red LED connected to
const byte servoPin = 9;        // the pin servo motor connected to
const byte piezoPin = A0;       // the pin piezo buzzer connected to

// default baud rate
const unsigned short baudRate = 9600;

// default knock meter
const byte quietKnockVal = 30;
const byte loudKnockVal = 50;
const byte maxNumKnock = 5;

byte switchVal;
byte knockVal;
boolean locked = false;
byte numKnocks = 0;

// put setup code here, to run once
void setup() {
    servoMotor.attach(servoPin);       // attach the servo to ~9
    pinMode(switchPin, INPUT);
    pinMode(yellowLEDPin, OUTPUT);
    pinMode(greenLEDPin, OUTPUT);
    pinMode(redLEDPin, OUTPUT);
    Serial.begin(baudRate);
    // unlock the box first
    digitalWrite(greenLEDPin, HIGH);
    servoMotor.write(0);
    Serial.println("ACCESS GRANTED");
}

// put main code here, to run repeatedly
void loop() {
    if (locked == false) {
        switchVal = digitalRead(switchPin);
        if (switchVal == HIGH) {
            lockTheBox();
        }
    } else {
        knockVal = analogRead(piezoPin);
        // require maxNumKnock valid knocks
        if (numKnocks < maxNumKnock && knockVal > 0) {
            if (checkForKnock(knockVal) == true) {
                numKnocks++;
            }
            Serial.print("Need ");
            Serial.print(maxNumKnock - numKnocks);
            Serial.println(" more knock(s)");
        }
        if (numKnocks >= maxNumKnock) {
            unlockTheBox();
            // reset numKnocks
            numKnocks = 0;
        }
    }
}

void unlockTheBox(void) {
    // change the locked value
    locked = false;
    // indicate on LEDs
    digitalWrite(redLEDPin, LOW);
    digitalWrite(greenLEDPin, HIGH);
    // rotate the servo to 0 degree
    servoMotor.write(0);
    // print a message on the Serial Monitor
    Serial.println("ACCESS GRANTED");
    // allow time for the servo to completely move
    delay(20);
}

void lockTheBox(void) {
    // change locked value
    locked = true;
    // indicate on LEDs
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(redLEDPin, HIGH);
    // rotate the servo to 90 degrees
    servoMotor.write(90);       // rotate the servo 90 degrees to lock
    // print a message on the Serial Monitor
    Serial.println("ACCESS DENIED");
    // allow time for the servo to completely move
    delay(20);
}

// checks to see if a knock is valid or not
boolean checkForKnock(byte aKnockVal) {
    if (aKnockVal > quietKnockVal && aKnockVal < loudKnockVal) {
        digitalWrite(yellowLEDPin, HIGH);
        delay(50);
        digitalWrite(yellowLEDPin, LOW);
        Serial.print("Valid knock value: ");
        Serial.println(aKnockVal);
        return true;
    } else {
        Serial.print("Invalid knock value: ");
        Serial.println(aKnockVal);
        return false;
    }
}
