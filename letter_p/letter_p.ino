/*******************************************************************************

DIY Arduino - Project 01: Letter P

Name: letter_p.ino

Description: Make a beautiful effect of letter P
 
Compatibility: Arduino UNO R3

Phi Luu
David Douglas High School
Portland, OR
July 03, 2016

*******************************************************************************/

// LEDs arrangement by pin numbers
// 56
// 47
// 3
// 2

const int TIME = 100;   // set how long in milliseconds to flash one LED

//**********setup**********
// Put setup code here, to run once
// Inputs: None
// Outputs: None
void setup() {
    for (int pinNumber = 2; pinNumber < 8; pinNumber++) {
        pinMode(pinNumber, OUTPUT);    // set pin 2 to pin 8 as OUTPUT
    }
}

//**********loop**********
// Put main code here, to run repeatedly
// Inputs: None
// Outputs: None
void loop() {
    for (int pinNumber = 2; pinNumber < 8; pinNumber++) {
        digitalWrite(pinNumber, LOW);   // turn off all LED
    }
    digitalWrite(2, HIGH);  // start with LED at pin 2
    delay(TIME);            // flash this LED for TIME milliseconds
    // create a "running" effect on LEDs
    for (int pinNumber = 2; pinNumber < 7; pinNumber++) {
        digitalWrite(pinNumber, LOW);       // turn off this LED
        digitalWrite(pinNumber + 1, HIGH);  // and turn on next LED
        delay(TIME);                    // turn on for TIME milliseconds
    }
    // when completes letter P, go straight down and repeat it again
    digitalWrite(7, LOW);
    digitalWrite(4, HIGH);
    delay(TIME);
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
    delay(TIME);
    digitalWrite(3, LOW);
    digitalWrite(2, HIGH);
}

