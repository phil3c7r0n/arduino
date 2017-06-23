/**
 * Project Name: Arduino Projects Book - Project 08: Digital Hourglass
 *
 * File Name: digital_hourglass.ino
 *
 * Description: Turns on an LED every 2 second. Operates like an hourglass.
 *
 * Author: Phi Luu
 * Location: Portland, Oregon, United States
 * Created: July 27, 2016
 * Updated: June 22, 2017
 */

// Required hardware I/O connections
const byte LED_1_PIN   = 2; // connect led1 to 2
const byte LED_2_PIN   = 3; // connect led2 to ~3
const byte LED_3_PIN   = 4; // connect led3 to 4
const byte LED_4_PIN   = 5; // connect led4 to ~5
const byte LED_5_PIN   = 6; // connect led5 to ~6
const byte LED_6_PIN   = 7; // connect led6 to 7
const byte SWITCH_PIN = 8; // connect tilt switch to 8

// Global variables
unsigned long prev_time = 0;
byte switch_state       = 0;
byte prev_switch_state  = 0;
byte current_led        = LED_1_PIN;
unsigned long interval  = 2000; // time delay between each event

void setup() {
    for (byte led = LED_1_PIN; led <= LED_6_PIN; led++) {
        pinMode(led, OUTPUT);
    }
    pinMode(SWITCH_PIN, INPUT);
}

void loop() {
    // start the timer and set the new current time
    unsigned long current_time = millis();

    // check the time
    if (current_time - prev_time > interval) {
        prev_time = current_time;        // store the current time
        digitalWrite(current_led, HIGH); // turn on the current LED

        // once the time is up (all LEDs are turned on)
        if (current_led == LED_6_PIN) {
            // make blink effect
            for (byte t = 0; t < 4; t++) {
                for (byte led = LED_1_PIN; led <= LED_6_PIN; led++) {
                    digitalWrite(led, HIGH); // flashing on
                }

                if (t < 3) {
                    delay(250);  // for 0.25 second
                } else {
                    delay(1000); // the last flash takes 1 second
                }

                for (byte led = LED_1_PIN; led <= LED_6_PIN; led++) {
                    digitalWrite(led, LOW); // flashing off
                }
                delay(250);                 // for 0.25 second
            }
            // restart the LED pin
            current_led = LED_1_PIN;
        } else {
            current_led++; // go to next LED pin
        }
    }

    // check the tilt switch
    switch_state = digitalRead(SWITCH_PIN);

    // flip the light if the tilt switch is flipped
    if (switch_state != prev_switch_state) {
        // restart the process - turn off all LEDs
        for (byte led = LED_1_PIN; led <= LED_6_PIN; led++) {
            digitalWrite(led, LOW);
        }
        // go back to the first LED
        current_led = LED_1_PIN;
        // store the current time
        prev_time = current_time;
    }
    // store the current switch state
    prev_switch_state = switch_state;
}
