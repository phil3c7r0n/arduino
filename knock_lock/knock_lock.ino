/**
 * Project Name: Arduino Projects Book - Project 12: Knock Lock
 *
 * File Name: knock_lock.ino
 *
 * Description: Uses the Piezo buzzer to make a secret locking mechanism in
 * order to keep intruders out.
 *
 * Author: Phi Luu
 * Location: Portland, Oregon, United States
 * Created: September 06, 2016
 * Updated: June 22, 2017
 */

#include <Servo.h>
Servo ServoMotor;

// Required hardware I/O connections
const byte PIEZO_PIN      = A0; // the pin piezo buzzer connected to
const byte SWITCH_PIN     = 2;  // the pin switch connected to
const byte YELLOW_LED_PIN = 3;  // the pin yellow LED connected to
const byte GREEN_LED_PIN  = 4;  // the pin green LED connnected to
const byte RED_LED_PIN    = 5;  // the pin red LED connected to
const byte SERVO_PIN      = 9;  // the pin servo motor connected to

// Global constants
const unsigned short BAUD_RATE = 9600;
const byte QUIET_KNOCK_VAL     = 30;
const byte LOUD_KNOCK_VAL      = 50;
const byte MAX_NUM_KNOCK       = 5;

// Global variables
byte switch_val;
byte knock_val;
boolean is_locked  = false;
byte    num_knocks = 0;

void setup() {
    ServoMotor.attach(SERVO_PIN);
    pinMode(SWITCH_PIN,     INPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN,  OUTPUT);
    pinMode(RED_LED_PIN,    OUTPUT);
    Serial.begin(BAUD_RATE);
    // unlock the box first
    digitalWrite(GREEN_LED_PIN, HIGH);
    ServoMotor.write(0);
    Serial.println("ACCESS GRANTED");
}

void loop() {
    if (is_locked == false) {
        switch_val = digitalRead(SWITCH_PIN);

        if (switch_val == HIGH) {
            LockTheBox();
        }
    } else {
        knock_val = analogRead(PIEZO_PIN);

        // require MAX_NUM_KNOCK valid knocks
        if ((num_knocks < MAX_NUM_KNOCK) && (knock_val > 0)) {
            if (CheckForKnock(knock_val) == true) {
                num_knocks++;
            }
            Serial.print("Need ");
            Serial.print(MAX_NUM_KNOCK - num_knocks);
            Serial.println(" more knock(s)");
        }

        if (num_knocks >= MAX_NUM_KNOCK) {
            UnLockTheBox();
            // reset num_knocks
            num_knocks = 0;
        }
    }
}

/**
 * Changes the LEDs and turn the servo to unlock the box.
 */
void UnLockTheBox(void) {
    // change the is_locked value
    is_locked = false;
    // indicate on LEDs
    digitalWrite(RED_LED_PIN,   LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);
    // rotate the servo to 0 degree
    ServoMotor.write(0);
    // print a message on the Serial Monitor
    Serial.println("ACCESS GRANTED");
    // allow time for the servo to completely move
    delay(20);
}

/**
 * Changes the LEDs and turn the servo to lock the box.
 */
void LockTheBox(void) {
    // change is_locked value
    is_locked = true;
    // indicate on LEDs
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN,   HIGH);
    // rotate the servo to 90 degrees
    ServoMotor.write(90); // rotate the servo 90 degrees to lock
    // print a message on the Serial Monitor
    Serial.println("ACCESS DENIED");
    // allow time for the servo to completely move
    delay(20);
}

/**
 * Checks to see if a knock is valid or not.
 *
 * @param   a_knock_val   the loudness of the knock
 *
 * @return                true if a valid knock, false otherwise
 */
boolean CheckForKnock(byte a_knock_val) {
    if ((a_knock_val > QUIET_KNOCK_VAL) && (a_knock_val < LOUD_KNOCK_VAL)) {
        digitalWrite(YELLOW_LED_PIN, HIGH);
        delay(50);
        digitalWrite(YELLOW_LED_PIN, LOW);
        Serial.print("Valid knock value: ");
        Serial.println(a_knock_val);
        return true;
    } else {
        Serial.print("Invalid knock value: ");
        Serial.println(a_knock_val);
        return false;
    }
}
