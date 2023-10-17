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
const int blueRythmLedPin = 10;      // the number of the blue LED Pin which pulses at a set rythmn
const int greenLedPin = 11;      // the number of the green LED Pin which outputs a success
const int redLedPin =  13;      // the number of the green LED Pin which outputs a miss

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

// blue LED state counter
int blueLedStartTime;

// blue LED period
int blueLedPeriod = 5000;

// blue button pulse duration
int blueLedPulseDuration = 1000;

// button press time
int buttonPressTime = 0;

//

// time of loop
int timeNow;

void setup() {
  // initialize the LED pin as an output:
  pinMode(blueRythmLedPin, OUTPUT);
  // initialize the LED pin as an output:
  pinMode(greenLedPin, OUTPUT);
  // initialize the LED pin as an output:
  pinMode(redLedPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  int blueLedStartTime = millis();
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  // Save time of loop
  timeNow = millis();

  // register initial press
  if (buttonState == HIGH && buttonPressTime == 0) {
    buttonPressTime = timeNow;
  }

  // put red light if button pressed before pulse
  if (buttonPressTime !=0 && (buttonPressTime - blueLedStartTime) < (blueLedPeriod - blueLedPulseDuration)) {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
  }
  
  // put green light on if in duration
   if (buttonPressTime !=0 && ((buttonPressTime - blueLedStartTime) >= (blueLedPeriod - blueLedPulseDuration)) && (buttonPressTime - blueLedStartTime < blueLedPeriod)) {
     digitalWrite(redLedPin, LOW);
     digitalWrite(greenLedPin, HIGH);
  }

  // put red button on if missed
  if (buttonPressTime == 0 && (blueLedPeriod <= (timeNow - blueLedStartTime))) {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
  }

  // if time since start reaches period the start time is reset and the button is turned off
  if(blueLedPeriod <= (timeNow - blueLedStartTime)) {
    blueLedStartTime = timeNow;
    digitalWrite(blueRythmLedPin, LOW);
    buttonPressTime = 0;
    // if time since start reaches period blueLedPulseDuration before start time button is turned on
  } else if ((blueLedPeriod - blueLedPulseDuration) <= (timeNow - blueLedStartTime)) {
    digitalWrite(blueRythmLedPin, HIGH);
  }
}
