#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

class Timer
{
    uint32_t previous_millis;

public:
    Timer();

    // returns true if time_ms has passed since reset was last called and resets timer, else false
    bool time_passed(uint32_t time_ms);

    // returns number of ms since timer was last reset
    uint32_t get_ms();

    // reset the timer
    void reset();
};

#endif