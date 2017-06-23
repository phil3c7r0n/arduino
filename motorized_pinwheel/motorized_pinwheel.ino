/**
 * Project Name: Arduino Projects Book - Project 09: Motorized Pinwheel
 *
 * File Name: motorized_pinwheel.ino
 *
 * Description: Gets the Arduino to spin a colorful pinwheel using a motor.
 *
 * Author: Phi Luu
 * Location: Portland, Oregon, United States
 * Created: August 13, 2016
 * Updated: June 22, 2017
 */

// Required hardware I/O connections
const byte switch_pin = 2; // connect switch to 2
const byte motor_pin  = 9; // connect dc motor to ~9

void setup() {
    pinMode(switch_pin, INPUT);
    pinMode(motor_pin,  OUTPUT);
}

void loop() {
    byte switch_state = digitalRead(switch_pin);

    // toggle the switch to toggle the motor
    if (switch_state) {
        digitalWrite(motor_pin, HIGH);
    } else {
        digitalWrite(motor_pin, LOW);
    }
}
