//****************************************************************************
//
// Project Name: Arduino Projects Book - Project 11: Crystal Ball
//
// File Name: crystal-ball.ino
//
// Description: Use the LCD to help "predict" the future when tilting the
// tilt switch
//
// Compatibility: Arduino UNO
//
// Phi Luu
// Portland, Oregon, United States
// Created August 26, 2016
// Updated August 26, 2016
//
//****************************************************************************

#include <LiquidCrystal.h>

//**********Required Hardware I/O Connections**********
const byte lcdD7 = 2;       // connect D7 of the LCD to 2
const byte lcdD6 = 3;       // connect D6 of the LCD to ~3
const byte lcdD5 = 4;       // connect D5 of the LCD to 4
const byte lcdD4 = 5;       // connect D4 of the LCD to ~5
const byte lcdE = 11;       // connect E of the LCD to ~11
const byte lcdRS = 12;      // connect RS of the LCD to 12
const byte switchPin = 6;   // connect the tilt switch to ~6

// constructor syntax
// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(lcdRS, lcdE, lcdD4, lcdD5, lcdD6, lcdD7);
// set the number of columns (width) and rows (height) of the LCD
const byte LCDW = 16;
const byte LCDH = 2;

byte switchVal = 0;
byte prevSwitchVal = 0;
byte reply = 0;             // available choices vary from 0 to 7

//**********setup**********
// Put setup code here, to run once
// Inputs: None
// Outputs: None
void setup() {
    lcd.begin(LCDW, LCDH);
    pinMode(switchPin, INPUT);
    // intro message
    lcd.setCursor(0, 0);
    lcd.print("Ask the");
    lcd.setCursor(0, 1);
    lcd.print("Crystal Ball!");
}

//**********loop**********
// Put main code here, to run repeatedly
// Inputs: None
// Outputs: None
void loop() {
    switchVal = digitalRead(switchPin);
    if (switchVal != prevSwitchVal) {
        if (switchVal == LOW) {
            reply = random(8);      // choose 1 out of 8 anwers
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("The ball says...");
            delay(1000);
            lcd.setCursor(0, 1);
            switch(reply) {
                case 0:
                lcd.print("Absolutely");
                break;
                case 1:
                lcd.print("Probably");
                break;
                case 2:
                lcd.print("Maybe");
                break;
                case 3:
                lcd.print("Yep");
                break;
                case 4:
                lcd.print("Unsure");
                break;
                case 5:
                lcd.print("Foolish Question");
                break;
                case 6:
                lcd.print("Who knows");
                break;
                case 7:
                lcd.print("Impossible");
                break;
            }
        }
    }
    prevSwitchVal = switchVal;
}
