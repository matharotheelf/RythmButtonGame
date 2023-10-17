/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int blueRythmLedPin =  10;      // the number of the blue LED Pin which pulses at a set rythmn
const int greenLedPin =  11;      // the number of the green LED Pin which outputs a success
const int yellowLedPin =  12;      // the number of the green LED Pin which outputs a slight miss
const int redLedPin =  13;      // the number of the green LED Pin which outputs a miss

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(blueRythmLedPin, OUTPUT);
  // initialize the LED pin as an output:
  pinMode(greenLedPin, OUTPUT);
  // initialize the LED pin as an output:
  pinMode(yellowLedPin, OUTPUT);
  // initialize the LED pin as an output:
  pinMode(redLedPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn all LED on:
    digitalWrite(blueRythmLedPin, HIGH);
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(redLedPin, HIGH);
  } else {
    // turn all LED off:
    digitalWrite(blueRythmLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
  }
}
