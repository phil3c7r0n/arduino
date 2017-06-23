/**
 * Project Name: Arduino Projects Book - Project 05: Mood Cue
 *
 * File Name: mood_cue.ino
 *
 * Description: Expresses your feeling by a servo motor.
 *
 * Author: Phi Luu
 * Location: Portland, Oregon, United States
 * Created: November 21, 2015
 * Updated: June 22, 2017
 */

// include Servo library for servo motors
#include <Servo.h>

// Required hardware I/O connections
const byte pot_pin   = A0;           // connect potentiometer to A0
const byte servo_pin = 3;            // connect servo motor to ~3

// Servo class
Servo MyServo;                       // declare MyServo

// Global constants
const unsigned int BAUD_RATE = 9600; // serial monitor's baud rate

// Global variables
unsigned int  pot_val;               // potentiometer
unsigned char angle;                 // servo's angle

void setup() {
    MyServo.attach(servo_pin);       // attach MyServo into servo_pin
    Serial.begin(BAUD_RATE);         // start the Serial Monitor
}

void loop() {
    // read & print potentiometer value
    pot_val = analogRead(pot_pin);
    Serial.print("pot_val: ");
    Serial.print(pot_val);
    // map & print from pot value to angle
    angle = map(pot_val, 0, 1023, 0, 179);
    Serial.print(", angle: ");
    Serial.println(angle);
    // run the servo by the angle
    MyServo.write(angle);
    // delay to stabilize
    delay(15);
}
