/*\
  SetIntervalExample

  Shows how to use the setInterval function of the Interval library.
  Runs two Intervals: one toggles the builtin LED once every two seconds
  The other prints a message to the Serial Monitor every second.

  Circuit:
    - Builtin LED

  created 15 Dec. 2016
  by Tom Igoe
*/
#include "Interval.h"

Interval ledTimer;       // set a timer for the LED
Interval tickTimer;      // set a timer for the ticker

int blinkState = HIGH;   // the LED state, HIGH or LOW

void setup() {
  Serial.begin(9600);          // initialize serial
  pinMode(LED_BUILTIN, OUTPUT);         // set the LED to be an output
  // timer's callback function is blink, interval is 2000ms:
  ledTimer.setInterval(blink, 2000);
  // timer's callback function is tick, interval is 1000ms:
  tickTimer.setInterval(tick, 1000);
}

void loop() {
  int sensorValue = analogRead(A0); // read sensor
  ledTimer.setDelay(sensorValue);   // use it to change ledTimer delay

  // you have to poll the Intervals once per loop
  // to make sure they haven't reached their end:
  ledTimer.check();                 // check the LED timer
  tickTimer.check();                // check the motor timer
}

void blink() {
  blinkState = !blinkState;
  digitalWrite(LED_BUILTIN, blinkState);
}

void tick() {
  Serial.println("tick");
}
