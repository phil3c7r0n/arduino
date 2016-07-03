/*******************************************************************************

DIY Arduino - Project 02: Dark Room

Name: dark_room.ino

Description: Automatically turn on the LED when it's dark
Find the light switch when you come home from work at night

Compatibility: Arduino UNO R3

Phi Luu
David Douglas High School
Portland, OR
July 03, 2016

*******************************************************************************/

const int led = 12;         // set led as 12 alias
const int photo = A0;       // set photo as A0 alias

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
    if (photoVal < 100) {         // when you enter your room and it's too dark
        digitalWrite(led, HIGH);  // then it will turn the light on for you
    }
    else {                        // if it's bright enough
        digitalWrite(led, LOW);   // then turn of the LED to save energy
    }
}

