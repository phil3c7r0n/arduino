/**
 * Project Name: Arduino Projects Book - Project 04: Color Mixing Lamp
 *
 * File Name: color_mixing_lamp.ino
 *
 * Description: Indicates different colors on the RGB LED
 * according to the amount of light each photocell receives.
 *
 * Author: Phi Luu
 * Location: Portland, Oregon, United States
 * Created: October 25, 2015
 * Updated: June 22, 2017
 */

// Required hardware I/O connections
const byte red_sensor_pin   = A0; // connect red sensor to A0
const byte green_sensor_pin = A1; // connect green sensor to A1
const byte blue_sensor_pin  = A2; // connect blue sensor to A2
const byte green_led_pin    = 9;  // connect green pin of the RGB LED to ~9
const byte blue_led_pin     = 10; // connect blue pin of the RGB LED to ~10
const byte red_led_pin      = 11; // connect red pin of the RGB LED to ~11

// Global constants
const unsigned int BAUD_RATE = 9600;

// Global variables
unsigned int red_led_value      = 0;
unsigned int blue_led_value     = 0;
unsigned int green_led_value    = 0;
unsigned int red_sensor_value   = 0;
unsigned int blue_sensor_value  = 0;
unsigned int green_sensor_value = 0;

void setup() {
    Serial.begin(BAUD_RATE);
    pinMode(red_led_pin,   OUTPUT);
    pinMode(blue_led_pin,  OUTPUT);
    pinMode(green_led_pin, OUTPUT);
}

void loop() {
    // read the values from the sensors
    // leave 5 miliseconds for Analog - Digital Conversion
    red_sensor_value = analogRead(red_sensor_pin);
    delay(5);
    blue_sensor_value = analogRead(blue_sensor_pin);
    delay(5);
    green_sensor_value = analogRead(green_sensor_pin);

    // print those values onto the serial monitor
    Serial.println("Raw Sensor Values:");
    Serial.print("\t Red: ");
    Serial.print(red_sensor_value);
    Serial.print("\t Blue: ");
    Serial.print(blue_sensor_value);
    Serial.print("\t Green: ");
    Serial.println(green_sensor_value);

    // convert from 0-1023 to 0-255
    red_led_value   = red_sensor_value / 4;   // define Red LED
    blue_led_value  = blue_sensor_value / 4;  // define Blue LED
    green_led_value = green_sensor_value / 4; // define Green LED

    // print mapped values to serial monitor
    Serial.println("Mapped Sensor Values:");
    Serial.print("\t Red: ");
    Serial.print(red_led_value);
    Serial.print("\t Blue: ");
    Serial.print(blue_led_value);
    Serial.print("\t Green: ");
    Serial.println(green_led_value);

    // use analogWrite() to set output for RGB LED
    analogWrite(red_led_pin,   red_led_value);   // indicate red LED
    analogWrite(blue_led_pin,  blue_led_value);  // indicate blue LED
    analogWrite(green_led_pin, green_led_value); // indicate green LED
}
