/**
 * @file     mood_cue.ino
 * @author   Phi Luu
 * @date     November 21, 2015
 *
 * @brief    Arduino Projects Book - Project 05: Mood Cue
 *
 * @section  DESCRIPTION
 *
 * Helps express your feeling using a servo motor.
 */

// include Servo library for servo motors
#include <Servo.h>

// Required hardware I/O connections
const byte POT_PIN   = A0;           // connect potentiometer to A0
const byte SERVO_PIN = 3;            // connect servo motor to ~3

// Servo class
Servo MyServo;                       // declare MyServo

// Global constants
const unsigned int BAUD_RATE = 9600; // serial monitor's baud rate

// Global variables
unsigned int  pot_val;               // potentiometer
unsigned char angle;                 // servo's angle

void setup() {
    MyServo.attach(SERVO_PIN);       // attach MyServo into SERVO_PIN
    Serial.begin(BAUD_RATE);         // start the Serial Monitor
}

void loop() {
    // read & print potentiometer value
    pot_val = analogRead(POT_PIN);
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
