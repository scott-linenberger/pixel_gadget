#ifndef ANIMATIONSTATE_H
#define ANIMATIONSTATE_H

/* bring in the Arduino-y goodness */
#include <Arduino.h>

class AnimationState {
  /* delays */
  uint16_t delay1InMs;
  uint16_t delay2InMs;
  
  /* timeMarks */
  unsigned long timeMark1;
  unsigned long timeMark2;
  
  /* ints */
  uint32_t int1 = 0;
  uint32_t int2 = 0;

  public:
  AnimationState();
  void reset();

  void markTime1();
  void markTime2();

  boolean hasTimedOut1();
  boolean hasTimedOut2();

  void setDelay1InMs(uint16_t delayInMs);
  void setDelay2InMs(uint16_t delayInMs);

  uint32_t getInt1();
  uint32_t getInt2();

  void setInt1(uint32_t value);
  void setInt2(uint32_t value);

  void incrementInt1();
  void incrementInt2();
  
  void decrementInt1();
  void decrementInt2();
};

#endif
