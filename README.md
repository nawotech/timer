# timer
Stupid simple Arduino timer

## How to use
1. Create a timer
```c++
Timer MyTimer;
```

2. In the main loop, add check for time passed
```c++
loop()
{
  if (MyTimer.time_passed(1000))
  {
    // code here will be run every 1000 ms
  }
}
```

3. To manually reset the timer, call reset
```c++
MyTimer.reset();
```

*That's it*
