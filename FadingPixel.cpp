#include "FadingPixel.h"

FadingPixel::FadingPixel()
{
  /* randomize the initial fade value */
  fadeValue = random(0, 255);
}

void FadingPixel::tick()
{
  /* check if the fade delay has timed out */
  if (millis() - timeMark < fadeDelay)
  {
    /* timeout hasn't occured, return */
    return;
  }

  /* increment or decrement based on fading */
  if (isFading)
  {
    fadeValue--;
  }
  else
  {
    fadeValue++;
  }

  /* check if value exceeds the max  or min */
  /* toggle fading accordingly */
  if (fadeValue > 255)
  {
    /* max reached, now fade down */
    fadeValue = 255;
    isFading = true;
  }

  if (fadeValue < 0)
  {
    /* min reached, now glow up */
    fadeValue = 0;
    isFading = false;
  }
  
  timeMark = millis();
}

void FadingPixel::setFadeDelay(uint16_t delayTime)
{
  fadeDelay = delayTime;
}

uint8_t FadingPixel::getValue() {
  return fadeValue;
}