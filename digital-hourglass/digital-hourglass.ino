/*****************************************************************************

Project Name: Arduino Projects Book - Project 08: Digital Hourglass

File Name: digital-hourglass.ino

Description: A digital hourglass that turns on a LED every 2 seconds.
  It works just like an hourglass, but digitally.

Compatibility: Arduino UNO R3

Phi Luu
Portland, Oregon, United States
Created July 27, 2016
Updated July 28, 2016

*****************************************************************************/

//**********Required Hardware I/O Connections**********
const byte switchPin = 8;   // connect tilt switch to 8
const byte led6Pin = 7;     // connect led6 to 7
const byte led5Pin = 6;     // connect led5 to ~6
const byte led4Pin = 5;     // connect led4 to ~5
const byte led3Pin = 4;     // connect led3 to 4
const byte led2Pin = 3;     // connect led2 to ~3
const byte led1Pin = 2;     // connect led1 to 2

unsigned long prevTime = 0; // hold the time
byte currSwitchState = 0;   // hold the current switch state
byte prevSwitchState = 0;   // hold the previous switch state
byte currLed = led1Pin;     // init the current led to be led1
unsigned long interval = 2000;      // 2 seconds = 2,000 milliseconds
                                    // between each event

//**********setup**********
// Put setup code here, to run once
// Inputs: None
// Outputs: None
void setup() {
    // set all LED pins as OUTPUT
    for (byte led = led1Pin; led <= led6Pin; led++) {
        pinMode(led, OUTPUT);
    }
    // set switch pin as INPUT
    pinMode(switchPin, INPUT);
}

//**********loop**********
// Put main code here, to run repeatedly
// Inputs: None
// Outputs: None
void loop() {
    // start the timer and set the new current time
    unsigned long currTime = millis();
    // check the time
    if (currTime - prevTime > interval) {
        prevTime = currTime;            // store the current time
        digitalWrite(currLed, HIGH);    // turn on the current LED
        // once the time is up (all LEDs are turned on)
        if (currLed == led6Pin) {
            // make a flashing effect
            // indicating that time is up
            for (byte t = 0; t < 4; t++) {
                for (byte led = led1Pin; led <= led6Pin; led++) {
                    digitalWrite(led, HIGH);    // flashing on
                }
                if (t < 3) {
                    delay(250);     // for 0.25 second
                }
                else {
                    delay(1000);    // the last flash takes 1 second
                }
                for (byte led = led1Pin; led <= led6Pin; led++) {
                    digitalWrite(led, LOW);     // flashing off
                }
                delay(250);                     // for 0.25 second
            }
            // restart the process
            currLed = led1Pin;
        }
        else {
            currLed++;  // next LED
        }
    }

    // read the current switch state from the tilt switch
    currSwitchState = digitalRead(switchPin);
    // check difference in the switch states
    // simulate the flip of the hourglass. If the hourglass is flipped
    if (currSwitchState != prevSwitchState) {
        // restart the process
        // turn off all LEDs
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
