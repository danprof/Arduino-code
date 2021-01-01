// ATtiny 84 Keypad
//
// use an Attiny 84 to scan 4X4 keypad and send character read to ESP32
// using a software Serial connection. This requires only two GPIO
// pins on Esp32 instead of eight. The ATtiny 84 also turns on an LED
// as feedback that keypress was read.
// the code to use a 4X3 keypad is included as comments for easy mod to 
// smaller keypad.
//
// 5V   |  1 ***U*** 14  | Gnd
//10/X1 |  2 *     * 13  | 0/A0
// 9/X2 |  3 *     * 12  | 1/A1
//RESET |  4 *     * 11  | 2/A2
//    8 |  5 *     * 10  | 3/A3
// A7/7 |  6 *     *  9  | 4/A4
// A6/6 |  7 *******  8  | 5/A5


#include <Keypad.h>

/*
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}         };
  
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3}; //connect to the column pinouts of the keypad
 */
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}     };

byte rowPins[ROWS] = {0, 1, 2, 3 }; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 5, 8, 9 }; //connect to the column pinouts of the keypad

//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

#include "SoftwareSerial.h"
const int LED = 10;               // this is physical pin 2 for the LED
const int Rx = 7;                 // this is physical pin 6
const int Tx = 6;                 // this is physical pin 7

// Create the serial port called mySerial
SoftwareSerial mySerial(Rx, Tx);

//--------------------------------------
void setup(){
  pinMode(LED, OUTPUT);           // tell Arduino LED is an output
  pinMode(Rx, INPUT);
  pinMode(Tx, OUTPUT);
  mySerial.begin(9600);           // send serial data at 9600 bits/sec
}
  
void loop(){
  char key = keypad.getKey();// Read the key
  
  // Print if key pressed
  if (key){
    mySerial.print("Key Pressed : ");
    mySerial.println(key);
    digitalWrite(LED, HIGH);       // turn LED ON
    delay(500);
    digitalWrite(LED, LOW);       // turn off
  }
}
