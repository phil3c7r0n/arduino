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

//**********Required Hardware I/O Connections**********
// LEDs 1, 2, 3, 4, 5, and 6 connected to
// pins 2, 3, 4, 5, 6, and 7 respectively

// LEDs arrangement
// LED4 LED5
// LED3 LED6
// LED2
// LED1

const int LED1 = 2;     // set LED1 as 2 alias
const int LED2 = 3;     // set LED2 as 3 alias
const int LED3 = 4;     // set LED3 as 4 alias
const int LED4 = 5;     // set LED4 as 5 alias
const int LED5 = 6;     // set LED5 as 6 alias
const int LED6 = 7;     // set LED6 as 7 alias
const int TIME = 100;   // set how long in milliseconds to flash one LED

//**********setup**********
// Put setup code here, to run once
// Inputs: None
// Outputs: None
void setup() {
    for (int pinNumber = LED1; pinNumber <= LED6; pinNumber++) {
        pinMode(pinNumber, OUTPUT);    // set pin 2 to pin 8 as OUTPUT
    }
}

//**********loop**********
// Put main code here, to run repeatedly
// Inputs: None
// Outputs: None
void loop() {
    for (int pinNumber = LED1; pinNumber <= LED6; pinNumber++) {
        digitalWrite(pinNumber, LOW);   // turn off all LED
    }
    digitalWrite(LED1, HIGH);  // start with LED 1
    delay(TIME);            // flash this LED for TIME milliseconds
    // create a "running" effect on LEDs
    for (int pinNumber = LED1; pinNumber <= LED5; pinNumber++) {
        digitalWrite(pinNumber, LOW);       // turn off this LED
        digitalWrite(pinNumber + 1, HIGH);  // and turn on next LED
        delay(TIME);                    // turn on for TIME milliseconds
    }
    // when completes letter P, go straight down and repeat it again
    digitalWrite(LED6, LOW);
    digitalWrite(LED3, HIGH);
    delay(TIME);
    digitalWrite(LED3, LOW);
    digitalWrite(LED2, HIGH);
    delay(TIME);
    digitalWrite(LED2, LOW);
    digitalWrite(LED1, HIGH);
}

