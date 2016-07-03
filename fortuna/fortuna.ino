/*******************************************************************************

Robot Collection - Project 01: Fortuna

Name: fortuna.ino

Description: The robot...
    moves forward by two motors on its left and right wings (wings)
    automatically beeps when activating (mouth)
    flashes the LEDs like an airplane at night
    determines the ON-OFF status of the motors by two photocells (eyes)
    listens to loud noise and changes behaviors of mouth and wings (ear)

Compatibility: Arduino UNO R3

Phi Luu
David Douglas High School
Portland, OR
July 03, 2016

*******************************************************************************/

const int BUZZER = 2;       // set BUZZER as 2 alias
const int LMOTOR = 5;       // set LMOTOR as 5 alias
const int RMOTOR = 10;      // set RMOTOR as 10 alias
const int LPHOTO = A0;      // set LPHOTO as A0 alias
const int MICINP = A3;      // set MICINP as A3 alias
const int RPHOTO = A5;      // set RPHOTO as A5 alias
const int LLED = 4;         // set LLED as 4 alias
const int RLED = 7;         // set RLED as 7 alias
// set motors to use 50% PWM (possible values 0-255)
const int MPOW = 128;       
// set microphone trigger threshold (possible values 0-1023)
const int MICTHRESH = 600;  

//**********setup**********
// Put setup code here, to run once
// Inputs: None
// Outputs: None
void setup() {
    pinMode(LMOTOR, OUTPUT);  // set LMOTOR as OUTPUT
    pinMode(RMOTOR, OUTPUT);  // set RMOTOR as OUTPUT
    pinMode(BUZZER, OUTPUT);  // set BUZZER as OUTPUT
    pinMode(LLED, OUTPUT);    // set LLED as OUTPUT
    pinMode(RLED, OUTPUT);    // set RLED as OUTPUT
}

//**********beep**********
// Generates a square wave at a given frequency for ms miliseconds
// Inputs: pin    the pin number needed to make sound
//         freq   the frequency of the sound
//         ms     the duration
// Outputs: None
void beep(int pin, int freq, long ms) {
    long semiPer = (long) (1000000/(freq*2));
    long loops = (long) ((ms*1000)/(semiPer*2));
    for (int k = 0; k < loops; k++) {
        digitalWrite(pin, HIGH);        // set buzzer pin high
        delayMicroseconds(semiPer);     // for half of the period
        digitalWrite(pin, LOW);         // set buzzer pin low
        delayMicroseconds(semiPer);     // for the other half of the period
    }
}

//**********loop**********
// Put main code here, to run repeatedly
// Inputs: None
// Outputs: None
void loop() {
    // turn off both motors
    analogWrite(LMOTOR,0);
    analogWrite(RMOTOR,0);
    
    // beep a bunch of times
    for (int i = 1; i < 5; i++) {
        beep(BUZZER, 1000, 100*i);
        delay(100*i);
    }
    
    // listen to the microphone for ~100 ms
    int val;
    int maxVal = 0;
    for (int i = 1; i < 100; i++) {
        val = analogRead(MICINP);
        if (val > maxVal) {
            maxVal = val;
        }
        delay(1);
    }
    
    // if the largest voltage detected is above 1.77 V (3.3*550/1024),
    // commence the "beep dance" response
    if (maxVal > MICTHRESH) {
        // make the "siren" noise by alternating 1200 Hz and 800 Hz tones
        for (int i = 0; i < 5; i++) {
            beep(BUZZER, 1200, 100);
            beep(BUZZER, 800,  100);
        }
        // shake motors back and forth rapidly
        for (int i = 0; i < 3; i++) {
            analogWrite(RMOTOR, MPOW);
            delay(200);
            analogWrite(RMOTOR, 0);
            analogWrite(LMOTOR, MPOW);
            delay(200);
            analogWrite(LMOTOR, 0);
        }
        // make a series of tones with increasing frequency from 300-100 Hz
        for (int i = 30; i < 100; i += 1) {
            beep(BUZZER, 10*i, 10);
        }
        // then come back down
        for (int i = 100; i > 30; i -= 1) {
            beep(BUZZER, 10*i, 10);
        }
    } 
    
    // flash the light like an airplane
    digitalWrite(LLED, HIGH);
    delay(10);
    digitalWrite(LLED, LOW);
    digitalWrite(RLED, HIGH);
    delay(10);
    digitalWrite(RLED, LOW);
    
    // read the status of photocells and adjust motor output
    // delay briefly to allow comparator outputs to settle
    delayMicroseconds(20);
    
    // check each photocell/circuit output and determine
    if (digitalRead(LPHOTO)) {
        analogWrite(LMOTOR, MPOW);  // whether to run on the left motor...
    }
    if (digitalRead(RPHOTO)) {      // ...or right motor
        analogWrite(RMOTOR, MPOW);     
    }
    delay(500);                     // wait 500ms
}

