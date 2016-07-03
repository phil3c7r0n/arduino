/*******************************************************************************

Arduino Projects Book - Project 03: Love-O-Meter

Name: love_o_meter.ino

Description: Using the temperature sensor, test how hot you really are!
 
Compatibility: Arduino UNO R3

Phi Luu
David Douglas High School
Portland, OR
July 03, 2016

*******************************************************************************/

const int sensorPin = A0;           // set sensorPin as A0 alias
const float baseLineTemp = 20.0;    // set baseLineTemp = 20 degrees Celsius

//**********setup**********
// Put setup code here, to run once
// Inputs: None
// Outputs: None
void setup() {
    Serial.begin(9600);               // start Serial Monitor
    for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
        pinMode(pinNumber, OUTPUT);     // quickly set LED pins as OUTPUT
        digitalWrite(pinNumber, LOW);   // quickly turn off all LEDs
    }
}

//**********loop**********
// Put main code here, to run repeatedly
// Inputs: None
// Outputs: None
void loop() {
    int sensorVal = analogRead(sensorPin);    // read value from sensorPin
    Serial.print("Sensor value: ");
    Serial.println(sensorVal);    // print sensorVal on Serial Monitor
    float voltage = (sensorVal / 1024.0) * 5.0;   // map sensorVal to voltage
    Serial.print("Volts: ");
    Serial.println(voltage);      // print voltage on Serial Monitor
    // from voltage, define temperature
    float temperature = (voltage - 0.5) * 100;
    Serial.print("Degrees C: ");
    Serial.println(temperature);  // print temperature on Serial Monitor
    Serial.println();
    
    if ((temperature >= baseLineTemp)
    && (temperature < baseLineTemp + 2)) {
        // level 1: from baseLineTemp to baseLineTemp + 2
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);  // all LEDs turn on
        digitalWrite(4, HIGH);
    }
    else if (temperature < baseLineTemp) {
        // level 0: less than baseLineTemp
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);   // all LEDs turn off
        digitalWrite(4, LOW);
    }
    else if ((temperature >= baseLineTemp + 2)
    && (temperature < baseLineTemp + 4)) {
        // level 2: from baseLineTemp + 2 to baseLineTemp + 4
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);   // LED 1 turns on, LED 2 and LED 3 turn off
        digitalWrite(4, LOW);
    }
    else if ((temperature >= baseLineTemp + 4)
    && (temperature < baseLineTemp + 6)) {
        // level 3: from baseLineTemp + 4 to baseLineTemp + 6
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);  // LED 2 turns on, LED 1 and LED 3 turn off
        digitalWrite(4, LOW);
    }
    else {
        // level 4: out of range
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);   // LED 3 turns on, LED 1 and LED 2 turn off
        digitalWrite(4, HIGH);
    }
}

