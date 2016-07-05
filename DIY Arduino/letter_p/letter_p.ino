/*******************************************************************************

DIY Arduino - Project 01: Letter P

Name: letter_p.ino

Description: Make a beautiful effect of letter P
 
Compatibility: Arduino UNO R3

Phi Luu
David Douglas High School
Portland, OR
July 05, 2016

*******************************************************************************/

// LEDs arrangement
// LED4 LED5
// LED3 LED6
// LED2
// LED1

//**********Required Hardware I/O Connections**********
const byte LED1 = 2;     // connect LED 1 to 2
const byte LED2 = 3;     // connect LED 2 to ~3
const byte LED3 = 4;     // connect LED3 to 4
const byte LED4 = 5;     // connect LED4 to ~5
const byte LED5 = 6;     // connect LED5 to ~6
const byte LED6 = 7;     // connect LED6 to 7

// set how long in milliseconds to flash one LED
const unsigned int TIME = 100;

//**********setup**********
// Put setup code here, to run once
// Inputs: None
// Outputs: None
void setup() {
    for (byte pinNumber = LED1; pinNumber <= LED6; pinNumber++) {
        pinMode(pinNumber, OUTPUT);    // set pin 2 to pin 8 as OUTPUT
    }
}

//**********loop**********
// Put main code here, to run repeatedly
// Inputs: None
// Outputs: None
void loop() {
    for (byte pinNumber = LED1; pinNumber <= LED6; pinNumber++) {
        digitalWrite(pinNumber, LOW);   // turn off all LED
    }
    digitalWrite(LED1, HIGH);  // start with LED 1
    delay(TIME);            // flash this LED for TIME milliseconds
    // create a "running" effect on LEDs
    for (byte pinNumber = LED1; pinNumber <= LED5; pinNumber++) {
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

