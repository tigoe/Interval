
#ifndef Interval_h
#define Interval_h

#include "Arduino.h"

class Interval
{
  public:
    Interval();
    void (*callback)();         // callback for the timer
    boolean repeating = false;  // whether interval should repeat
    boolean done = false;       // whether interval is done
    void setInterval(void (*callback)(), unsigned long _delay);
    void setTimeout(void (*callback)(), unsigned long _delay);
    void setDelay(unsigned long _delay);
    unsigned long check();      // called every time through loop
    void reset();               // reset the interval to the current millis
    void stop();                // stop the interval
  private:
    unsigned long delay;        // delay between callbacks, in ms
    unsigned long timeStamp;    // last time callback was called
};

#endif
