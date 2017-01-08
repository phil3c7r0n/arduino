//****************************************************************************
//
// Project Name: Arduino Projects Book - Project 03: Love-O-Meter
//
// File Name: love_o_meter.ino
//
// Description: Using the temperature sensor, test how hot you really are!
//
// Compatibility: Arduino UNO
//
// Phi Luu
// Portland, Oregon, United States
// Created September 30, 2015
// Updated January 07, 2017
//
//****************************************************************************

//***
// Global Declaration
//***

// Required hardware I/O connections
const byte sensorPin = A0; // connect TMP sensor to A0
const byte LED1      = 2;  // connect LED 1 to 2
const byte LED2      = 3;  // connect LED 2 to ~3
const byte LED3      = 4;  // connect LED 3 to 4

// Global constants
const float baseLineTemp = 20.0;

// Global variables
unsigned int sensorVal;

//***
// Mandatory Routines
//***

void setup() {
    Serial.begin(9600);

    for (byte pinNumber = LED1; pinNumber <= LED3; pinNumber++) {
        pinMode(pinNumber, OUTPUT);
        digitalWrite(pinNumber, LOW);
    }
}

void loop() {
    // read & print temperature value
    sensorVal = analogRead(sensorPin);
    Serial.print("Sensor value: ");
    Serial.println(sensorVal);

    // map & print temperature value to voltage
    float voltage = (sensorVal / 1024.0) * 5.0;
    Serial.print("Volts: ");
    Serial.println(voltage);

    // from voltage, define temperature
    float temperature = (voltage - 0.5) * 100;
    Serial.print("Degrees C: ");
    Serial.println(temperature);
    Serial.println();

    // from temperature, indicate the LEDs
    if ((temperature >= baseLineTemp)
            && (temperature < baseLineTemp + 2)) {
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH); // level 1: all LEDs turned on
        digitalWrite(LED3, HIGH);
    } else if (temperature < baseLineTemp) {
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW); // level 0: all LEDs turned off
        digitalWrite(LED3, LOW);
    } else if ((temperature >= baseLineTemp + 2)
               && (temperature < baseLineTemp + 4)) {
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, LOW); // level 2: LED1 turned on, LEDs 2 & 3 turned off
        digitalWrite(LED3, LOW);
    } else if ((temperature >= baseLineTemp + 4)
               && (temperature < baseLineTemp + 6)) {
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH); // level 3: LED2 turned on, LEDs 1 & 3 turned off
        digitalWrite(LED3, LOW);
    } else {
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW); // level 4: LED 3 turned on, LEDs 1 & 2 turned off
        digitalWrite(LED3, HIGH);
    }
}
