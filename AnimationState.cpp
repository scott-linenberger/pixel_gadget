#include "AnimationState.h";

AnimationState::AnimationState()
{
}

void AnimationState::reset()
{
  int1 = 0;
  int2 = 0;
}

void AnimationState::markTime1()
{
  timeMark1 = millis();
}

void AnimationState::markTime2()
{
  timeMark2 = millis();
}

boolean AnimationState::hasTimedOut1()
{
  if (millis() - timeMark1 >= delay1InMs)
  {
    return true;
  }

  return false;
}

boolean AnimationState::hasTimedOut2()
{
  if (millis() - timeMark2 >= delay2InMs)
  {
    return true;
  }

  return false;
}

void AnimationState::setDelay1InMs(uint16_t delayInMs)
{
  delay1InMs = delayInMs;
}

void AnimationState::setDelay2InMs(uint16_t delayInMs)
{
  delay2InMs = delayInMs;
}

uint32_t AnimationState::getInt1()
{
  return int1;
}

uint32_t AnimationState::getInt2()
{
  return int2;
}

void AnimationState::setInt1(uint32_t value)
{
  int1 = value;
}

void AnimationState::setInt2(uint32_t value) {
  int2 = value;
}

void AnimationState::incrementInt1()
{
  int1++;
}

void AnimationState::incrementInt2()
{
  int2++;
}

void AnimationState::decrementInt1()
{
  int1--;
}

void AnimationState::decrementInt2()
{
  int2--;
}
