#ifndef TIMER_H
#define TIMER_H

class Timer
{
    unsigned long previous_millis;

public:
    Timer();

    // returns true if time_ms has passed since reset was last called and resets timer, else false
    bool time_passed(unsigned long time_ms);

    // reset the timer
    void reset();
};

#endif