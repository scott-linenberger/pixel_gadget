#ifndef ANIMATIONSTATE_H
#define ANIMATIONSTATE_H

/* bring in the Arduino-y goodness */
#include <Arduino.h>

#include "FadingPixel.h";

class AnimationState
{
  /* number of pixels */
  uint8_t numberOfPixels;

  /* array of fading pixels */
  FadingPixel fadingPixels[100];

  /* delays */
  uint16_t delayPosition1 = 0;
  uint16_t delayPosition2 = 0;
  uint16_t delayPosition3 = 0;
  uint16_t delayPosition4 = 0;

  uint16_t delayColor1 = 0;
  uint16_t delayColor2 = 0;
  uint16_t delayColor3 = 0;
  uint16_t delayColor4 = 0;

  /* timeMarks */
  unsigned long timeMarkColor1 = 0;
  unsigned long timeMarkColor2 = 0;
  unsigned long timeMarkColor3 = 0;
  unsigned long timeMarkColor4 = 0;

  unsigned long timeMarkPosition1 = 0;
  unsigned long timeMarkPosition2 = 0;
  unsigned long timeMarkPosition3 = 0;
  unsigned long timeMarkPosition4 = 0;

  /* position values */
  uint8_t position1 = 0;
  uint8_t position2 = 0;
  uint8_t position3 = 0;
  uint8_t position4 = 0;

  /* color values */
  uint8_t color1 = 0;
  uint8_t color2 = 0;
  uint8_t color3 = 0;
  uint8_t color4 = 0;

public:
  AnimationState();
  void setNumberOfPixels(uint8_t _numberOfPixels);
  void reset();

  /* position tickers */
  void tickPosition1();
  void tickPosition2();
  void tickPosition3();
  void tickPosition4();

  /* color tickers */
  void tickColor1();
  void tickColor2();
  void tickColor3();
  void tickColor4();

  void tickFadingPixels();

  /* delays */
  void setDelayPosition1(uint16_t delayValue);
  void setDelayPosition2(uint16_t delayValue);
  void setDelayPosition3(uint16_t delayValue);
  void setDelayPosition4(uint16_t delayValue);

  void setDelayColor1(uint16_t delayValue);
  void setDelayColor2(uint16_t delayValue);
  void setDelayColor3(uint16_t delayValue);
  void setDelayColor4(uint16_t delayValue);

  void setDelayFadingPixels(uint16_t delayValue);

  /* getters */
  uint8_t getColor1();
  uint8_t getColor2();
  uint8_t getColor3();
  uint8_t getColor4();

  uint8_t getPosition1();
  uint8_t getPosition2();
  uint8_t getPosition3();
  uint8_t getPosition4();

  FadingPixel * getFadingPixels();

private:
  void tickPosition(
      unsigned long &timeMark,
      uint16_t delayTime,
      uint8_t &position);

  void tickColor(
      unsigned long &timeMark,
      uint16_t delayTime,
      uint8_t &color);
};

#endif
