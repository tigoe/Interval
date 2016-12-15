#include "Interval.h"

Interval buttonTimeout;     // set a timout for the ticker

const int buttonPin = 4;    // pin number for the pushbutton
int ledState = LOW;        // the LED state, HIGH or LOW
int previousButtonState = LOW; // previous state of the button

void setup() {
  Serial.begin(9600);           // initialize serial
  pinMode(LED_BUILTIN, OUTPUT); // set the LED to be an output
  pinMode(buttonPin, INPUT);    // set the button pin to be an input
}

void loop() {
  int buttonState = digitalRead(buttonPin);
if (buttonState != previousButtonState) { 
    if (buttonState == HIGH) {
      Serial.println("Button pressed");
      buttonTimeout.setTimeout(changeLED, 2000);
    }
  previousButtonState = buttonState;
  }

  buttonTimeout.check();
}


void changeLED() {
  digitalWrite(LED_BUILTIN, ledState);
  ledState = !ledState;
}
