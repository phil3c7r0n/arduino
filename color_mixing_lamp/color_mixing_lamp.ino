/**
 * @file     color_mixing_lamp.ino
 * @author   Phi Luu
 * @date     October 25, 2015
 *
 * @brief    Arduino Projects Book - Project 04: Color Mixing Lamp
 *
 * @section  DESCRIPTION
 *
 * Indicates different colors on the RGB LED according to the amount
 * of light each photocell receives.
 */

// Required hardware I/O connections
const byte RED_SENSOR_PIN   = A0; // connect red sensor to A0
const byte GREEN_SENSOR_PIN = A1; // connect green sensor to A1
const byte BLUE_SENSOR_PIN  = A2; // connect blue sensor to A2
const byte GREEN_LED_PIN    = 9;  // connect green pin of the RGB LED to ~9
const byte BLUE_LED_PIN     = 10; // connect blue pin of the RGB LED to ~10
const byte RED_LED_PIN      = 11; // connect red pin of the RGB LED to ~11

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
    pinMode(RED_LED_PIN,   OUTPUT);
    pinMode(BLUE_LED_PIN,  OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
}

void loop() {
    // read the values from the sensors
    // leave 5 miliseconds for Analog - Digital Conversion
    red_sensor_value = analogRead(RED_SENSOR_PIN);
    delay(5);
    blue_sensor_value = analogRead(BLUE_SENSOR_PIN);
    delay(5);
    green_sensor_value = analogRead(GREEN_SENSOR_PIN);

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
    analogWrite(RED_LED_PIN,   red_led_value);   // indicate red LED
    analogWrite(BLUE_LED_PIN,  blue_led_value);  // indicate blue LED
    analogWrite(GREEN_LED_PIN, green_led_value); // indicate green LED
}
