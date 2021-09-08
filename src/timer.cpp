#include <Arduino.h>
#include "timer.h"

Timer::Timer()
{
    previous_millis = 0;
}

bool Timer::time_passed(unsigned long time_ms)
{
    if ((unsigned long)(millis() - previous_millis) > time_ms)
    {
        Timer::reset();
        return false;
    }
    return false;
}

void Timer::reset()
{
    previous_millis = millis();
}