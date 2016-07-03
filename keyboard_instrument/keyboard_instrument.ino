/*******************************************************************************

Arduino Projects Book - Project 07: Keyboard Instrument

Name: keyboard_instrument.ino

Description: Simulate keys C, D, E, and F of the real piano
using push buttons and piezo buzzer

Compatibility: Arduino UNO R3

Phi Luu
David Douglas High School
Portland, OR
July 03, 2016

*******************************************************************************/

// set up frequencies for C, D, E, and F in the real piano
const int notes[] = {262, 294, 330, 349};
const int piezo = 8;        // set piezo as 8 alias
const int keyboard = A0;    // set keyboard as A0 alias

//**********setup**********
// Put setup code here, to run once
// Inputs: None
// Outputs: None
void setup() {
    Serial.begin(9600);       // start the serial monitor
    pinMode(piezo, OUTPUT);   // set piezo as OUTPUT
}

//**********loop**********
// Put main code here, to run repeatedly
// Inputs: None
// Outputs: None
void loop() {
    // read input from the keyboard and set to keyVal
    int keyVal = analogRead(keyboard);
    Serial.print("keyVal = ");
    Serial.println(keyVal); // indicate the value of keyVal for debugging
    // if the first button is pressed
    if (keyVal == 1023) {
        tone(piezo, notes[0]);      // play key C of the real piano
    }
    // if the second button is pressed
    else if (keyVal >= 990 && keyVal <= 1010) {
        tone(piezo, notes[1]);      // play key D of the real piano
    }
    // if the third button is pressed
    else if (keyVal >= 505 && keyVal <= 515) {
        tone(piezo, notes[2]);      // play key E of the real piano
    }
    // if the fourth button is pressed
    else if (keyVal >= 5 && keyVal <= 10) {
        tone(piezo, notes[3]);      // play key F of the real piano
    }
    // if no button is pressed (or out of tolerance)
    else {
        noTone(piezo);              // mute the piezo
    }
}

