
#ifndef Interval_h
#define Interval_h

#include "Arduino.h"

class Interval
{
  public:
    void (*callback)();         // callback for the timer
    boolean repeating = false;  // whether interval should repeat
    boolean done = false;       // whether interval is done
    void setInterval(void (*callback)(), unsigned long _delay);
    void setTimeout(void (*callback)(), unsigned long _delay);
    void setDelay(unsigned long _delay);
    unsigned long check();       // called every time through loop
  private:
    unsigned long delay;        // delay between callbacks, in ms
    unsigned long timeStamp;    // last time callback was called
};

#endif
