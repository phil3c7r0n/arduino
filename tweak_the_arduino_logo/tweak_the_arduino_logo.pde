/**
 * @file     tweak_the_arduino_logo.pde
 * @author   Phi Luu
 * @date     January 07, 2017
 *
 * @brief    Arduino Projects Book - Project 14: Tweak the Arduino Logo
 *
 * @section  DESCRIPTION
 *
 * Using serial communication, the Arduino can send and receive information to
 * the computer. Draws the Arduino logo on the computer screen and adjust the
 * background color by the potentiometer.
 */

import processing.serial.*;
Serial MyPort;
PImage logo;

// Global constants
final int BAUD_RATE = 19200; // must be the same as the Arduino
final String LOGO_ADDRESS = "http://www.arduino.cc/arduino_logo.png";

// Global variables
int bgcolor = 0; // holds the background color

void setup() {
    size(1, 1);
    surface.setResizable(true);
    // set the color mode to Hue/Saturation/Brightness
    colorMode(HSB, 255);

    // load the Arduino logo into the PImage instance
    logo = loadImage(LOGO_ADDRESS);

    // make the window the same size as the image
    surface.setSize(logo.width, logo.height);

    // print a list of available serial ports to the
    // Processing staus window
    println("Available serial ports:");
    println(Serial.list());

    // Tell the serial object the information it needs to communicate
    MyPort = new Serial(this, Serial.list()[0], BAUD_RATE);
}

void draw() {
    if (MyPort.available() > 0) {
        // read and print for easy debugging
        bgcolor = MyPort.read();
        println(bgcolor);

        // draw the background by RGB color (each channel ranges 0-255)
        background(bgcolor, 255, 255);

        // draw the Arduino logo
        image(logo, 0, 0);
    }
}
