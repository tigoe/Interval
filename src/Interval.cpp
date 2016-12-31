#include "Arduino.h"
#include "Interval.h"

Interval::Interval() {
  _timeStamp = millis();
  _delay = 0;
  _timeStamp = 0;
  _repeating = false;
}

// set the callback and delay all at once. Should this be begin()?
void Interval::setInterval(void (*callback)(), unsigned long delay) {
  _callback = callback;
  _delay = delay;
  _timeStamp = millis();
  _repeating = true;
}

// set the callback and delay all at once, for a timeout:
void Interval::setTimeout(void (*callback)(), unsigned long delay) {
  _callback = callback;
  _delay = delay;
  _timeStamp = millis();
  _repeating = false;
  _done = false;
}

// check the timer, call the callback if the delay has passed:
unsigned long Interval::check() {
  // if the interval hasn't been initialized, return:
  if (_timeStamp == 0 && _delay == 0) return 0;

  if ((millis() - _timeStamp >= _delay) && !_done) {
    _callback();
    if (_repeating) {
      // if repeating is true, reset the timeStamp for next interval:
      reset();
    } else {
      // if not, stop the interval:
      stop();
    }
  }
  return (millis() - _timeStamp);
}

void Interval::setDelay(unsigned long delay) {
  _delay = delay;
}

unsigned long Interval::getDelay() {
   return _delay;
}


// reset the interval to the current millis():
void Interval::reset() {
  _timeStamp = millis();
  _done = false;
}

// stop the interval:
void Interval::stop() {
  _timeStamp = 0;
  _done = true;
}
