#include "AnimationState.h";

AnimationState::AnimationState()
{
}

void AnimationState::setNumberOfPixels(uint8_t _numberOfPixels)
{
  /* assign the number of pixels */
  numberOfPixels = _numberOfPixels;

  /* create a fading pixel object for each pixel */
  for (uint8_t i = 0; i < numberOfPixels; i++) {
    fadingPixels[i] = FadingPixel();
  }
}

void AnimationState::reset()
{
  /* position values */
  position1 = 0;
  position2 = 0;
  position3 = 0;
  position4 = 0;

  /* color values */
  color1 = 0;
  color2 = 0;
  color3 = 0;
  color4 = 0;

  /* timeMarks */
  timeMarkColor1 = 0;
  timeMarkColor2 = 0;
  timeMarkColor3 = 0;
  timeMarkColor4 = 0;

  timeMarkPosition1 = 0;
  timeMarkPosition2 = 0;
  timeMarkPosition3 = 0;
  timeMarkPosition4 = 0;
}

void AnimationState::tickPosition(
    unsigned long &timeMark,
    uint16_t delayTime,
    uint8_t &position)
{
  /* check if the position is due for an update */
  if (millis() - timeMark < delayTime)
  {
    /* delay hasn't timedout, return */
    return;
  }

  /* delay has timedout, update position */
  position++;

  /* check if position needs reset */
  if (position >= numberOfPixels)
  {
    position = 0;
  }

  /* update the timeMark */
  timeMark = millis();
}

void AnimationState::tickColor(
    unsigned long &timeMark,
    uint16_t delayTime,
    uint8_t &color)
{
  /* check if the color  is due for an update */
  if (millis() - timeMark < delayTime)
  {
    /* delay hasn't timedout, return */
    return;
  }

  /* delay has timedout, update the color */
  color++;

  /* check if color needs reset */
  if (color > 255)
  {
    color = 0;
  }

  /* update the  timeMark */
  timeMark = millis();
}

void AnimationState::tickPosition1()
{
  tickPosition(
      timeMarkPosition1,
      delayPosition1,
      position1);
}

void AnimationState::tickPosition2()
{
  tickPosition(
      timeMarkPosition2,
      delayPosition2,
      position2);
}

void AnimationState::tickPosition3()
{
  tickPosition(
      timeMarkPosition3,
      delayPosition3,
      position3);
}

void AnimationState::tickPosition4()
{
  tickPosition(
      timeMarkPosition4,
      delayPosition4,
      position4);
}

void AnimationState::tickColor1()
{
  tickColor(
      timeMarkColor1,
      delayColor1,
      color1);
}

void AnimationState::tickColor2()
{
  tickColor(
      timeMarkColor2,
      delayColor2,
      color2);
}

void AnimationState::tickColor3()
{
  tickColor(
      timeMarkColor3,
      delayColor3,
      color3);
}

void AnimationState::tickColor4()
{
  tickColor(
      timeMarkColor4,
      delayColor4,
      color4);
}

void AnimationState::tickFadingPixels() {
  for(uint8_t i = 0; i < numberOfPixels; i++) {
    fadingPixels[i].tick();
  }
}

void AnimationState::setDelayPosition1(uint16_t delayValue)
{
  delayPosition1 = delayValue;
}

void AnimationState::setDelayPosition2(uint16_t delayValue)
{
  delayPosition2 = delayValue;
}

void AnimationState::setDelayPosition3(uint16_t delayValue)
{
  delayPosition3 = delayValue;
}

void AnimationState::setDelayPosition4(uint16_t delayValue)
{
  delayPosition4 = delayValue;
}

void AnimationState::setDelayColor1(uint16_t delayValue)
{
  delayColor1 = delayValue;
}

void AnimationState::setDelayColor2(uint16_t delayValue)
{
  delayColor2 = delayValue;
}

void AnimationState::setDelayColor3(uint16_t delayValue)
{
  delayColor3 = delayValue;
}

void AnimationState::setDelayColor4(uint16_t delayValue)
{
  delayColor4 = delayValue;
}

void AnimationState::setDelayFadingPixels(uint16_t fadeDelay) {
  for(uint8_t i = 0; i < numberOfPixels; i++) {
    fadingPixels[i].setFadeDelay(fadeDelay);
  }
}

uint8_t AnimationState::getColor1()
{
  return color1;
}

uint8_t AnimationState::getColor2()
{
  return color2;
}

uint8_t AnimationState::getColor3()
{
  return color3;
}

uint8_t AnimationState::getColor4()
{
  return color4;
}

uint8_t AnimationState::getPosition1()
{
  return position1;
}

uint8_t AnimationState::getPosition2()
{
  return position2;
}

uint8_t AnimationState::getPosition3()
{
  return position3;
}

uint8_t AnimationState::getPosition4()
{
  return position4;
}

FadingPixel * AnimationState::getFadingPixels() {
  return fadingPixels;
}