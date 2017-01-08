//****************************************************************************
//
// Project Name: Arduino Projects Book - Project 08: Digital Hourglass
//
// File Name: digital-hourglass.ino
//
// Description: A digital hourglass that turns on a LED every 2 seconds.
//   It works just like an hourglass, but digitally.
//
// Compatibility: Arduino UNO
//
// Phi Luu
// Portland, Oregon, United States
// Created July 27, 2016
// Updated January 07, 2017
//
//****************************************************************************

//***
// Global Declaration
//***

// Required hardware I/O connections
const byte led1Pin   = 2; // connect led1 to 2
const byte led2Pin   = 3; // connect led2 to ~3
const byte led3Pin   = 4; // connect led3 to 4
const byte led4Pin   = 5; // connect led4 to ~5
const byte led5Pin   = 6; // connect led5 to ~6
const byte led6Pin   = 7; // connect led6 to 7
const byte switchPin = 8; // connect tilt switch to 8

// Global variables
unsigned long prevTime = 0;
byte currSwitchState   = 0;
byte prevSwitchState   = 0;
byte currLed           = led1Pin;
unsigned long interval = 2000; // time delay between each event

//***
// Mandatory Routines
//***

void setup() {
    for (byte led = led1Pin; led <= led6Pin; led++) {
        pinMode(led, OUTPUT);
    }
    pinMode(switchPin, INPUT);
}

void loop() {
    // start the timer and set the new current time
    unsigned long currTime = millis();

    // check the time
    if (currTime - prevTime > interval) {
        prevTime = currTime;         // store the current time
        digitalWrite(currLed, HIGH); // turn on the current LED

        // once the time is up (all LEDs are turned on)
        if (currLed == led6Pin) {
            // make blink effect
            for (byte t = 0; t < 4; t++) {
                for (byte led = led1Pin; led <= led6Pin; led++) {
                    digitalWrite(led, HIGH); // flashing on
                }

                if (t < 3) {
                    delay(250);  // for 0.25 second
                } else {
                    delay(1000); // the last flash takes 1 second
                }

                for (byte led = led1Pin; led <= led6Pin; led++) {
                    digitalWrite(led, LOW); // flashing off
                }
                delay(250);                 // for 0.25 second
            }
            // restart the LED pin
            currLed = led1Pin;
        } else {
            currLed++; // go to next LED pin
        }
    }

    // check the tilt switch
    currSwitchState = digitalRead(switchPin);

    // flip the light if the tilt switch is flipped
    if (currSwitchState != prevSwitchState) {
        // restart the process - turn off all LEDs
        for (byte led = led1Pin; led <= led6Pin; led++) {
            digitalWrite(led, LOW);
        }
        // go back to the first LED
        currLed = led1Pin;
        // store the current time
        prevTime = currTime;
    }
    // store the current switch state
    prevSwitchState = currSwitchState;
}
