
#ifndef Interval_h
#define Interval_h

#include "Arduino.h"

class Interval
{
  public:
    Interval();
    void setInterval(void (*callback)(), unsigned long delay);
    void setTimeout(void (*callback)(), unsigned long delay);
    void setDelay(unsigned long delay);
    unsigned long check();      // called every time through loop
    void reset();               // reset the interval to the current millis
    void stop();                // stop the interval
    unsigned long getDelay();
  private:
    void (*_callback)();         // callback for the timer
    unsigned long _delay = 0;    // delay between callbacks, in ms
    unsigned long _timeStamp = 0;// last time callback was called
    boolean _repeating = false;  // whether interval should repeat
    boolean _done = false;       // whether interval is done

};

#endif
