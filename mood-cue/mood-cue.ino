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
// Updated December 28, 2016
//
//****************************************************************************

//**********Required Hardware I/O Connections**********
const byte LED1 = 2;                // connect LED 1 to 2
const byte LED2 = 3;                // connect LED 2 to ~3
const byte LED3 = 4;                // connect LED 3 to 4
const byte sensorPin = A0;          // connect TMP sensor to A0

// set baseLineTemp = 20 degrees Celsius
const float baseLineTemp = 20.0;

//**********setup**********
// Put setup code here, to run once
// Inputs: None
// Outputs: None
void setup() {
    Serial.begin(9600);                 // start Serial Monitor
    for (byte pinNumber = LED1; pinNumber <= LED3; pinNumber++) {
        pinMode(pinNumber, OUTPUT);     // quickly set LED pins as OUTPUT
        digitalWrite(pinNumber, LOW);   // quickly turn off all LEDs
    }
}

//**********loop**********
// Put main code here, to run repeatedly
// Inputs: None
// Outputs: None
void loop() {
    // read value from sensorPin
    unsigned int sensorVal = analogRead(sensorPin);

    Serial.print("Sensor value: ");
    Serial.println(sensorVal);                  // print sensorVal on Serial Monitor
    float voltage = (sensorVal / 1024.0) * 5.0; // map sensorVal to voltage
    Serial.print("Volts: ");
    Serial.println(voltage);                    // print voltage on Serial Monitor
    // from voltage, define temperature
    float temperature = (voltage - 0.5) * 100;
    Serial.print("Degrees C: ");
    Serial.println(temperature);  // print temperature on Serial Monitor
    Serial.println();

    if ((temperature >= baseLineTemp)
        && (temperature < baseLineTemp + 2)) {
        // level 1: from baseLineTemp to baseLineTemp + 2
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);  // all LEDs turn on
        digitalWrite(LED3, HIGH);
    } else if (temperature < baseLineTemp) {
        // level 0: less than baseLineTemp
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);   // all LEDs turn off
        digitalWrite(LED3, LOW);
    } else if ((temperature >= baseLineTemp + 2)
               && (temperature < baseLineTemp + 4)) {
        // level 2: from baseLineTemp + 2 to baseLineTemp + 4
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, LOW);   // LED 1 turns on, LED 2 and LED 3 turn off
        digitalWrite(LED3, LOW);
    } else if ((temperature >= baseLineTemp + 4)
               && (temperature < baseLineTemp + 6)) {
        // level 3: from baseLineTemp + 4 to baseLineTemp + 6
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH);  // LED 2 turns on, LED 1 and LED 3 turn off
        digitalWrite(LED3, LOW);
    } else {
        // level 4: out of range
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);   // LED 3 turns on, LED 1 and LED 2 turn off
        digitalWrite(LED3, HIGH);
    }
}
