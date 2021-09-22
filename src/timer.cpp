#include <Arduino.h>
#include "timer.h"

Timer::Timer()
{
    previous_millis = 0;
}

bool Timer::time_passed(uint32_t time_ms)
{
    if ((uint32_t)(millis() - previous_millis) > time_ms)
    {
        Timer::reset();
        return true;
    }
    return false;
}

uint32_t Timer::get_ms()
{
    return (uint32_t)(millis() - previous_millis);
}

void Timer::reset()
{
    previous_millis = millis();
}