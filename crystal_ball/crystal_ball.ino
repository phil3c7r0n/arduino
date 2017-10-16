/**
 * @file     crystal_ball.ino
 * @author   Phi Luu
 * @date     August 26, 2016
 *
 * @brief    Arduino Projects Book - Project 11: Crystal Ball
 *
 * @section  DESCRIPTION
 *
 * Uses the LCD to help "predict" the future when tilting the tilt switch.
 */

#include <LiquidCrystal.h>

// Required hardware I/O connections
const byte LCD_D7     = 2;  // connect D7 of the LCD to 2
const byte LCD_D6     = 3;  // connect D6 of the LCD to ~3
const byte LCD_D5     = 4;  // connect D5 of the LCD to 4
const byte LCD_D4     = 5;  // connect D4 of the LCD to ~5
const byte LCD_E      = 11; // connect E of the LCD to ~11
const byte LCD_RS     = 12; // connect RS of the LCD to 12
const byte SWITCH_PIN = 6;  // connect the tilt switch to ~6

// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal Lcd(LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

// Global constants
const byte LCD_WIDTH  = 16;
const byte LCD_HEIGHT = 2;

// Global variables
byte switch_val      = 0;
byte prev_switch_val = 0;
byte reply           = 0; // varies from 0 to 7

void setup() {
    Lcd.begin(LCD_WIDTH, LCD_HEIGHT);
    pinMode(SWITCH_PIN, INPUT);
    // intro message
    Lcd.setCursor(0, 0);
    Lcd.print("Ask the");
    Lcd.setCursor(0, 1);
    Lcd.print("Crystal Ball!");
}

void loop() {
    switch_val = digitalRead(SWITCH_PIN);

    if ((switch_val != prev_switch_val) && (switch_val == LOW)) {
        reply = random(8); // randomly choose 1 out of 8 anwers
        Lcd.clear();
        Lcd.setCursor(0, 0);
        Lcd.print("The ball says...");
        delay(1000);
        Lcd.setCursor(0, 1);

        switch (reply) {
            case 0:
                Lcd.print("Absolutely");
                break;
            case 1:
                Lcd.print("Probably");
                break;
            case 2:
                Lcd.print("Maybe");
                break;
            case 3:
                Lcd.print("Yep");
                break;
            case 4:
                Lcd.print("Unsure");
                break;
            case 5:
                Lcd.print("Foolish Question");
                break;
            case 6:
                Lcd.print("Who knows");
                break;
            case 7:
                Lcd.print("Impossible");
                break;
        }
    }
    prev_switch_val = switch_val;
}
