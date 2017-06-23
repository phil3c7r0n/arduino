/**
 * Project Name: Arduino Projects Book - Project 11: Crystal Ball
 *
 * File Name: crystal_ball.ino
 *
 * Description: Uses the LCD to help "predict" the future when tilting the
 * tilt switch.
 *
 * Author: Phi Luu
 * Location: Portland, Oregon, United States
 * Created: August 26, 2016
 * Updated: June 22, 2017
 */

#include <LiquidCrystal.h>

// Required hardware I/O connections
const byte lcd_d7     = 2;  // connect D7 of the LCD to 2
const byte lcd_d6     = 3;  // connect D6 of the LCD to ~3
const byte lcd_d5     = 4;  // connect D5 of the LCD to 4
const byte lcd_d4     = 5;  // connect D4 of the LCD to ~5
const byte lcd_e      = 11; // connect E of the LCD to ~11
const byte lcd_rs     = 12; // connect RS of the LCD to 12
const byte switch_pin = 6;  // connect the tilt switch to ~6

// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(lcd_rs, lcd_e, lcd_d4, lcd_d5, lcd_d6, lcd_d7);

// Global constants
const byte LCD_WIDTH  = 16;
const byte LCD_HEIGHT = 2;

// Global variables
byte switch_val      = 0;
byte prev_switch_val = 0;
byte reply           = 0; // varies from 0 to 7

void setup() {
    lcd.begin(LCD_WIDTH, LCD_HEIGHT);
    pinMode(switch_pin, INPUT);
    // intro message
    lcd.setCursor(0, 0);
    lcd.print("Ask the");
    lcd.setCursor(0, 1);
    lcd.print("Crystal Ball!");
}

void loop() {
    switch_val = digitalRead(switch_pin);

    if ((switch_val != prev_switch_val) && (switch_val == LOW)) {
        reply = random(8); // randomly choose 1 out of 8 anwers
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("The ball says...");
        delay(1000);
        lcd.setCursor(0, 1);

        switch (reply) {
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
    prev_switch_val = switch_val;
}
