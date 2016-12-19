/*
  StopIntervalExample

  Shows how to use the stop function of the Interval library.
  Runs an interval that blinks an LED every second. When you press
  a pushbutton on pin 4, the interval is stopped.

  Circuit:
    - Pushbutton attached to digital pin 4 with a 10K pulldown resistor
    - Builtin LED
    
  created 19 Dec. 2016
  by Tom Igoe
*/
#include "Interval.h"

Interval ledTimer;       // set a timer for the LED

const int buttonPin = 4;       // pin number for the pushbutton
int previousButtonState = LOW; // previous state of the button
int blinkState = HIGH;         // the LED state, HIGH or LOW


void setup() {
  Serial.begin(9600);          // initialize serial
  pinMode(LED_BUILTIN, OUTPUT);// set the LED to be an output
  pinMode(buttonPin, INPUT);
  // timer's callback function is blink, interval is 1000ms:
  ledTimer.setInterval(blink, 1000);
 }

void loop() {
   // read the input pin:
  int buttonState = digitalRead(buttonPin);
  // if the button state has changed,
  if (buttonState != previousButtonState) {
    // and it's HIGH, start the timeout:
    if (buttonState == HIGH) {
      Serial.println("Button pressed. Interval stopped");
      // stop the interval:
      ledTimer.stop();
    }
    // save the button state for next time through the loop:
    previousButtonState = buttonState;
  }
  // check the timeout:
  ledTimer.check();
}

void blink() {
  blinkState = !blinkState;
  digitalWrite(LED_BUILTIN, blinkState);
}
