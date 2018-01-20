#include "PixelGadget.h"

PixelGadget::PixelGadget()
{
}

void PixelGadget::begin()
{
  /* fire up Serial */
  Serial.begin(9600);

  /* init the neoPixels */
  neoPixels->begin();
  neoPixels->show();

  /* call begin on knobState */
  knobState.begin();
}

/**
   Performs the PixelGadget code. Must be called in loop.
*/
void PixelGadget::run()
{
  /* update the knob values, check for changes */
  knobState.haveKnobsChanged();
  /* check modes and manage changes */
  checkMode();
  /* display the current state */
  displayState();
}

void PixelGadget::displayState()
{
  /* display the state using the appropriate mode */
  switch (mode)
  {
  case 0:
    modeOff();
    break;

  case 1:
    PixelAnimation::singlePixel(
        neoPixels,
        numberOfPixels,
        knobState);
    break;

  case 2:
    PixelAnimation::singlePixelRotate(
        neoPixels,
        numberOfPixels,
        knobState,
        animationState);
    break;

  case 3:
    PixelAnimation::singlePixelRotateFader(
        neoPixels,
        numberOfPixels,
        knobState,
        animationState);
    break;

  case 4:
    PixelAnimation::doublePixels(
        neoPixels,
        numberOfPixels,
        knobState);
    break;

  case 5:
    PixelAnimation::doublePixelsRotate(
        neoPixels,
        numberOfPixels,
        knobState,
        animationState);
    break;

  case 6:
    PixelAnimation::quadPixels(
        neoPixels,
        numberOfPixels,
        knobState);
    break;

  case 7:
    PixelAnimation::quadPixelsRotate(
        neoPixels,
        numberOfPixels,
        knobState,
        animationState);
    break;

  case 8:
    PixelAnimation::quadPixelsRotateFader(
        neoPixels,
        numberOfPixels,
        knobState,
        animationState);
    break;

  case 9:
    PixelAnimation::halves(
        neoPixels,
        numberOfPixels,
        knobState);
    break;

  case 10:
    PixelAnimation::halvesRotate(
        neoPixels,
        numberOfPixels,
        knobState,
        animationState);
    break;

  case 11:
    PixelAnimation::colorTuner(
        neoPixels,
        numberOfPixels,
        knobState);
    break;

  case 12:
    PixelAnimation::colorFader(
        neoPixels,
        numberOfPixels,
        knobState,
        animationState);
    break;

  case 13:
    PixelAnimation::colorFaderHalves(
        neoPixels,
        numberOfPixels,
        knobState,
        animationState);
    break;

  case 14:
    PixelAnimation::volume(
        neoPixels,
        numberOfPixels,
        knobState,
        animationState);
    break;

  case 15:
    PixelAnimation::collidingHalves(
        neoPixels,
        numberOfPixels,
        knobState,
        animationState);
    break;

  case 16:
    PixelAnimation::sparkle(
        neoPixels,
        numberOfPixels,
        knobState,
        animationState);
    break;

  default:
    /* if we wind up in an unknown mode, reset mode to 0 */
    mode = 0;
    break;
  }
}

void PixelGadget::modeOff()
{
  neoPixels->clear();
  neoPixels->show();
}

/**
   Checks if the mode has changed. If so, clears the nexPixels
   and resets the stateVars.
*/
void PixelGadget::checkMode()
{
  /* if the mode hasn't changed, jump out */
  if (mode == lastMode)
  {
    return;
  }

  /* update the mode var */
  Serial.println("PixelGadget: checkMode->change detected!");
  lastMode = mode;

  Serial.print("PixelGadget: checkMode->mode set to ");
  Serial.println(mode);

  /* the mode has changed */
  resetState();
}

void PixelGadget::resetState()
{
  neoPixels->clear();
  animationState.reset();
}

/* changes the current mode of the PixelGadget */
void PixelGadget::changeMode()
{
  Serial.println("PixelGadget: Mode changed!");
  /* reset the mode variable if we went past the last mode */
  if (mode == MODE_MAX)
  {
    mode = 0;
    return;
  }

  mode++;
  Serial.print("PixelGadget: changeMode->new mode is ");
  Serial.println(mode);
}

/**
   Assigns the reference to the neoPixel object used by the PixelGadget
   and the number of pixels that exist.
*/
void PixelGadget::setNeoPixels(Adafruit_NeoPixel &_neoPixels, uint16_t _numberOfPixels)
{
  neoPixels = &_neoPixels;
  numberOfPixels = _numberOfPixels;
  animationState.setNumberOfPixels(numberOfPixels);
}

/**
   Assigns the potentiometer knob pins.
*/
void PixelGadget::setKnobPins(char knob1, char knob2, char knob3, char knob4)
{
  /* construct a new KnobState object */
  knobState = KnobState(knob1, knob2, knob3, knob4);
}
