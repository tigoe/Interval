#include "Arduino.h"
#include "Interval.h"

Interval::Interval() {
  this->timeStamp = millis();
}

// set the callback and delay all at once. Should this be begin()?
void Interval::setInterval(void (*callback)(), unsigned long _delay) {
  this->callback = callback;
  this->delay = _delay;
  this->timeStamp = millis();
  this->repeating = true;
}

// set the callback and delay all at once, for a timeout:
void Interval::setTimeout(void (*callback)(), unsigned long _delay) {
  this->callback = callback;
  this->delay = _delay;
  this->timeStamp = millis();
  this->repeating = false;
  this->done = false;
}

// check the timer, call the callback if the delay has passed:
unsigned long Interval::check() {
  if (millis() - this->timeStamp >= this->delay && !this->done) {
    this->callback();
    if (this->repeating) {
      // if repeating is true, reset the timeStamp for next interval:
      this->reset();
    } else {
      // if not, stop the interval:
      this->stop();
    }
  }
  return this->done;
}

void Interval::setDelay(unsigned long _delay) {
  this->delay = _delay;
}

// reset the interval to the current millis():
void Interval::reset() {
  this->delay = millis();
}

// stop the interval:
void Interval::stop() {
  this->timeStamp = 0;
  this->done - true;
}
