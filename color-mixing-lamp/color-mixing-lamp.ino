/**
 * Project Name: Arduino Projects Book - Project 04: Color Mixing Lamp
 *
 * File Name: color_mixing_lamp.ino
 *
 * Description: Indicate different colors on the RGB LED
 * according to the amount of light each photocell receives
 *
 * Compatibility: Arduino UNO
 *
 * Phi Luu
 * Portland, Oregon, United States
 * Created October 25, 2015
 * Updated June 20, 2017
 */

// Required hardware I/O connections
const byte redSensorPin   = A0; // connect red sensor to A0
const byte greenSensorPin = A1; // connect green sensor to A1
const byte blueSensorPin  = A2; // connect blue sensor to A2
const byte greenLEDPin    = 9;  // connect green pin of the RGB LED to ~9
const byte blueLEDPin     = 10; // connect blue pin of the RGB LED to ~10
const byte redLEDPin      = 11; // connect red pin of the RGB LED to ~11

// Global constants
const unsigned int BAUD_RATE = 9600;

// Global variables
unsigned int redLEDValue      = 0;
unsigned int blueLEDValue     = 0;
unsigned int greenLEDValue    = 0;
unsigned int redSensorValue   = 0;
unsigned int blueSensorValue  = 0;
unsigned int greenSensorValue = 0;

void setup() {
    Serial.begin(BAUD_RATE);
    pinMode(redLEDPin,   OUTPUT);
    pinMode(blueLEDPin,  OUTPUT);
    pinMode(greenLEDPin, OUTPUT);
}

void loop() {
    // read the values from the sensors
    // leave 5 miliseconds for Analog - Digital Conversion
    redSensorValue = analogRead(redSensorPin);
    delay(5);
    blueSensorValue = analogRead(blueSensorPin);
    delay(5);
    greenSensorValue = analogRead(greenSensorPin);

    // print those values onto the serial monitor
    Serial.println("Raw Sensor Values:");
    Serial.print("\t Red: ");
    Serial.print(redSensorValue);
    Serial.print("\t Blue: ");
    Serial.print(blueSensorValue);
    Serial.print("\t Green: ");
    Serial.println(greenSensorValue);

    // convert from 0-1023 to 0-255
    redLEDValue   = redSensorValue / 4;   // define Red LED
    blueLEDValue  = blueSensorValue / 4;  // define Blue LED
    greenLEDValue = greenSensorValue / 4; // define Green LED

    // print mapped values to serial monitor
    Serial.println("Mapped Sensor Values:");
    Serial.print("\t Red: ");
    Serial.print(redLEDValue);
    Serial.print("\t Blue: ");
    Serial.print(blueLEDValue);
    Serial.print("\t Green: ");
    Serial.println(greenLEDValue);

    // use analogWrite() to set output for RGB LED
    analogWrite(redLEDPin,   redLEDValue);   // indicate red LED
    analogWrite(blueLEDPin,  blueLEDValue);  // indicate blue LED
    analogWrite(greenLEDPin, greenLEDValue); // indicate green LED
}
