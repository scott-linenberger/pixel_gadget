#ifndef FADINGPIXEL_H
#define FADINGPIXEL_H

#include <Arduino.h>;

class FadingPixel {
  unsigned long timeMark = 0;
  uint16_t fadeDelay = 100;
  boolean isFading = false;
  uint8_t fadeValue = 0;

  public:
  FadingPixel();
  void tick();
  void setFadeDelay(uint16_t delayTime);
  uint8_t getValue();
};

#endif