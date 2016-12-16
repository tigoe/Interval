/*\
  SetTimeoutExample

  Shows how to use the setTimeout function of the Interval library.
  Turns on the builtin LED two seconds after pin 4 changes from
  LOW to HIGH.

  Circuit:
    - Pushbutton attached to digital pin 4 with a 10K pulldown resistor
    - Builtin LED

  created 15 Dec. 2016
  by Tom Igoe
*/

#include "Interval.h"

Interval buttonTimeout;         // set a timout for the ticker

const int buttonPin = 4;       // pin number for the pushbutton
int ledState = LOW;            // the LED state, HIGH or LOW
int previousButtonState = LOW; // previous state of the button

void setup() {
  Serial.begin(9600);           // initialize serial
  pinMode(LED_BUILTIN, OUTPUT); // set the LED to be an output
  pinMode(buttonPin, INPUT);    // set the button pin to be an input
}

void loop() {
  // read the input pin:
  int buttonState = digitalRead(buttonPin);
  // if the button state has changed,
  if (buttonState != previousButtonState) {
    // and it's HIGH, start the timeout:
    if (buttonState == HIGH) {
      Serial.println("Button pressed");
      buttonTimeout.setTimeout(changeLED, 2000);
    }
    // save the button state for next time through the loop:
    previousButtonState = buttonState;
  }
  // check the timeout:
  buttonTimeout.check();
}


void changeLED() {
  digitalWrite(LED_BUILTIN, ledState);
  ledState = !ledState;
}
