/**
 * Project Name: Arduino Projects Book - Project 10: Zoetrope
 *
 * File Name: zoetrope.ino
 *
 * Description: Controls the speed and the direction of the DC motor using
 * two switches and a potentiometer.
 *
 * Author: Phi Luu
 * Location: Portland, Oregon, United States
 * Created: August 21, 2016
 * Updated: June 22, 2017
 */

// Required hardware I/O connections
const byte pot_pin              = A0; // connect potentiometer to A0
const byte ic_input_1           = 3;  // connect IC Input1 to ~3
const byte ic_input_2           = 2;  // connect IC Input2 to 2
const byte ic_enable_1          = 9;  // connect IC Enable1 t ~9
const byte direction_switch_pin = 4;  // connect direction switch to 4
const byte state_switch_pin     = 5;  // connect state switch to ~5

// Global variables
byte state_switch_val          = 0;   // state switch
byte direction_switch_val      = 0;   // direction switch
byte prev_state_switch_val     = 0;   // previous state switch
byte prev_direction_switch_val = 0;   // previous direction switch
byte motor_is_enabled          = 0;   // whether the motor is on/off
byte motor_direction           = 0;   // motor direction
unsigned short motor_speed     = 0;

void setup() {
    pinMode(direction_switch_pin, INPUT);
    pinMode(state_switch_pin,     INPUT);
    pinMode(ic_input_1,           OUTPUT);
    pinMode(ic_input_2,           OUTPUT);
    pinMode(ic_enable_1,          OUTPUT);
}

void loop() {
    state_switch_val = digitalRead(state_switch_pin);
    delay(1);
    direction_switch_val = digitalRead(direction_switch_pin);
    motor_speed          = analogRead(pot_pin) / 4;

    // process the on/off state of the motor from the state switch
    if (state_switch_val != prev_state_switch_val) {
        if (state_switch_val) {
            motor_is_enabled = !motor_is_enabled;
        }
    }

    // process the direction of the motor from the direction switch
    if (direction_switch_val != prev_direction_switch_val) {
        if (direction_switch_val) {
            motor_direction = !motor_direction;
        }
    }

    // control the direction of the motor using the IC
    if (motor_direction) {
        digitalWrite(ic_input_1, LOW);
        digitalWrite(ic_input_2, HIGH);
    } else {
        digitalWrite(ic_input_1, HIGH);
        digitalWrite(ic_input_2, LOW);
    }

    // control the on/off state of the motor using PWM
    if (motor_is_enabled) {
        analogWrite(ic_enable_1, motor_speed);
    } else {
        analogWrite(ic_enable_1, 0);
    }

    // prep for next inputs
    prev_state_switch_val     = state_switch_val;
    prev_direction_switch_val = direction_switch_val;
}
