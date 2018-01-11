#ifndef PIXELGADGET_H
#define PIXELGADGET_H

/* bring in the Arduino-y goodness */
#include <Arduino.h>

/* bring in Adafruit's neoPixel library */
#include <Adafruit_NeoPixel.h>

/* bring in PixelAnimations */
#include "PixelAnimation.h";

/*bring in the KnobState class */
#include "KnobState.h";

/* bring in the animation state */
#include  "AnimationState.h";

class PixelGadget {
    /* object for tracking potentiometers */
    KnobState knobState = KnobState();

    /* object for keeping track of animation states */
    AnimationState animationState = AnimationState();

    /* define the mode vars */
    /* vars for modes */
    uint8_t mode = -1;
    uint8_t lastMode = 0;
    uint8_t MODE_MAX = 6;

    /* neoPixels */
    Adafruit_NeoPixel * neoPixels;
    uint16_t numberOfPixels;

    /* vars for different animation states */
    uint16_t stateVar1 = 0;
    uint16_t stateVar2 = 0;
    uint16_t stateVar3 = 0;
    uint16_t stateVar4 = 0;

    /* public method declarations */
  public:
    PixelGadget();
    void setKnobPins(char knob1, char knob2, char knob3, char knob4);
    void setNeoPixels(Adafruit_NeoPixel &_neoPixels, uint16_t _numberOfPixels);
    void begin();
    void run();
    void changeMode();

    /* private method declarations */
  private:
    uint16_t analogInputToValue(uint8_t pin, uint16_t maxValue);
    void checkMode();
    void resetState();
    void displayState();
    void modeOff();
};

#endif



