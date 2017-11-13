/**
 * @file     motorized_pinwheel.ino
 * @author   Phi Luu
 * @date     August 13, 2016
 *
 * @brief    Arduino Projects Book - Project 09: Motorized Pinwheel
 *
 * @section  DESCRIPTION
 *
 * Gets the Arduino to spin a colorful pinwheel using a motor.
 */

// Required hardware I/O connections
const byte SWITCH_PIN = 2; // connect switch to 2
const byte MOTOR_PIN = 9;  // connect dc motor to ~9

void setup() {
    pinMode(SWITCH_PIN, INPUT);
    pinMode(MOTOR_PIN, OUTPUT);
}

void loop() {
    byte switch_state = digitalRead(SWITCH_PIN);

    // toggle the switch to toggle the motor
    if (switch_state) {
        digitalWrite(MOTOR_PIN, HIGH);
    } else {
        digitalWrite(MOTOR_PIN, LOW);
    }
}
