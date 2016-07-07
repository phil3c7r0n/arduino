/*******************************************************************************

Arduino Projects Book - Project 04: Color Mixing Lamp

Name: color_mixing_lamp.ino

Description: Indicate different colors on the RGB LED
according to the amount of light each photocell receives

Compatibility: Arduino UNO R3

Phi Luu
David Douglas High School
Portland, OR
July 03, 2016

*******************************************************************************/

//**********Required Hardware I/O Connections**********
const byte redLEDPin = 11;       // connect red pin of the RGB LED to ~11
const byte blueLEDPin = 10;      // connect green pin of the RGB LED to ~10
const byte greenLEDPin = 9;      // connect blue pin of the RGB LED to ~9
const byte redSensorPin = A0;    // connect red sensor to A0
const byte greenSensorPin = A1;  // connect green sensor to A1
const byte blueSensorPin = A2;   // connect blue sensor to A2

// baud rate for serial monitor
const unsigned int BAUD_RATE = 9600;

// initial values
unsigned int redLEDValue = 0;                // init redLEDValue = 0
unsigned int blueLEDValue = 0;               // init blueLEDValue = 0
unsigned int greenLEDValue = 0;              // init greenLEDValue = 0
unsigned int redSensorValue = 0;             // init redSensorValue = 0
unsigned int blueSensorValue = 0;            // init blueSensorValue = 0
unsigned int greenSensorValue = 0;           // init greenSensorValue = 0

//**********setup**********
// Put setup code here, to run once
// Inputs: None
// Outputs: None
void setup() {
    Serial.begin(BAUD_RATE);          // start serial monitor
    pinMode(redLEDPin, OUTPUT);       // set redLEDPin as OUTPUT
    pinMode(blueLEDPin, OUTPUT);      // set blueLEDPin as OUTPUT
    pinMode(greenLEDPin, OUTPUT);     // set greenLEDPin as OUTPUT
}

//**********loop**********
// Put main code here, to run repeatedly
// Inputs: None
// Outputs: None
void loop() {
    // read the values from the sensors
    // leave 5 miliseconds for Analog - Digital Conversion
    redSensorValue = analogRead(redSensorPin);      // read redSensorPin
    delay(5);               // delay helps Arduino stable after reading
    blueSensorValue = analogRead(blueSensorPin);    // read blueSensorPin
    delay(5);               // delay helps Arduino stable after reading
    greenSensorValue = analogRead(greenSensorPin);  // read greenSensorPin
    
    // print those values onto the serial monitor
    Serial.println("Raw Sensor Values:");
    Serial.print("\t Red: ");                                     
    Serial.print(redSensorValue);           // print redSensorValue
    Serial.print("\t Blue: ");                                      
    Serial.print(blueSensorValue);          // print blueSensorValue
    Serial.print("\t Green: "); 
    Serial.println(greenSensorValue);       // print greenSensorValue
    
    // convert from 0-1023 to 0-255 by divided by 4
    redLEDValue = redSensorValue/4;         // define Red LED
    blueLEDValue = blueSensorValue/4;       // define Blue LED
    greenLEDValue = greenSensorValue/4;     // define Green LED
    
    // print mapped values to serial monitor
    Serial.println("Mapped Sensor Values:");
    Serial.print("\t Red: ");
    Serial.print(redLEDValue);              // print redLEDValue
    Serial.print("\t Blue: ");  
    Serial.print(blueLEDValue);             // print blueLEDValue
    Serial.print("\t Green: ");
    Serial.println(greenLEDValue);          // print greenLEDValue
    
    // use analogWrite() to set output for RGB LED
    analogWrite(redLEDPin, redLEDValue);          // indicate red LED
    analogWrite(blueLEDPin, blueLEDValue);        // indicate blue LED
    analogWrite(greenLEDPin, greenLEDValue);      // indicate green LED
}

