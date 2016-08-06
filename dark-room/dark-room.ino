/*****************************************************************************

Project Name: DIY Arduino - Project 02: Dark Room

File Name: dark_room.ino

Description: Automatically turn on the LED when it's dark
Find the light switch when you come home from work at night

Compatibility: Arduino UNO

Phi Luu
Portland, Oregon, United States
Created December 13, 2015
Updated August 06, 2016

*****************************************************************************/

//**********Required Hardware I/O Connections**********
const int led = 12;         // connect LED to 12
const int photo = A0;       // connect photocell to A0

//**********setup**********
// Put setup code here, to run once
// Inputs: None
// Outputs: None
void setup() {
    pinMode(led, OUTPUT);   // set led as OUTPUT
}

//**********loop**********
// Put main code here, to run repeatedly
// Inputs: None
// Outputs: None
void loop() {
    int photoVal = analogRead(photo);   // read light amount from photocell
    // when you enter your room and it's too dark
    if (photoVal < 100) {
        // it will turn the light on for you
        digitalWrite(led, HIGH);
    }
    // if it's bright enough
    else {
        // turn of the LED to save energy
        digitalWrite(led, LOW);
    }
}
