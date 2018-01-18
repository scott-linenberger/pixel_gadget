#ifndef PIXELANIMATION_H
#define PIXELANIMATION_H
#include "KnobState.h";

/* bring in Adafruit's neoPixel library */
#include <Adafruit_NeoPixel.h>

/*bring in the KnobState class */
#include "KnobState.h";

#include "AnimationState.h"

class PixelAnimation
{
    /* public methods */
  public:
    static void singlePixel(
        Adafruit_NeoPixel *neoPixels,
        uint8_t numberOfPixels,
        KnobState &knobState);

    static void singlePixelRotate(
        Adafruit_NeoPixel *neoPixels,
        uint8_t numberOfPixels,
        KnobState &knobState,
        AnimationState &animationState);

    static void singlePixelRotateFader(
        Adafruit_NeoPixel *neoPixels,
        uint8_t numberOfPixels,
        KnobState &knobState,
        AnimationState &animationState);

    static void doublePixels(
        Adafruit_NeoPixel *neoPixels,
        uint8_t numberOfPixels,
        KnobState &knobState);

    static void doublePixelsRotate(
        Adafruit_NeoPixel *neoPixels,
        uint8_t numberOfPixels,
        KnobState &knobState,
        AnimationState &animationState);

    static void quadPixels(
        Adafruit_NeoPixel *neoPixels,
        uint8_t numberOfPixels,
        KnobState &knobState);

    static void quadPixelsRotate(
        Adafruit_NeoPixel *neoPixels,
        uint8_t numberOfPixels,
        KnobState &knobState,
        AnimationState &animationState);

    static void quadPixelsRotateFader(
        Adafruit_NeoPixel *neoPixels,
        uint8_t numberOfPixels,
        KnobState &knobState,
        AnimationState &animationState);

    static void halves(
        Adafruit_NeoPixel *neoPixels,
        uint8_t numberOfPixels,
        KnobState &knobState);

    static void halvesRotate(
        Adafruit_NeoPixel *neoPixels,
        uint8_t numberOfPixels,
        KnobState &knobState,
        AnimationState &animationState);

    static void colorTuner(
        Adafruit_NeoPixel *neoPixels,
        uint8_t numberOfPixels,
        KnobState &knobState);

    static void colorFader(
        Adafruit_NeoPixel *neoPixels,
        uint8_t numberOfPixels,
        KnobState &knobState,
        AnimationState &animationState);

    static void colorFaderHalves(
        Adafruit_NeoPixel *neoPixels,
        uint8_t numberOfPixels,
        KnobState &knobState,
        AnimationState &animationState);

    static void sparkle(
        Adafruit_NeoPixel *neoPixels,
        uint8_t numberOfPixels,
        KnobState &knobState,
        AnimationState &animationState);

    static void volume(
        Adafruit_NeoPixel *neoPixels,
        uint8_t numberOfPixels,
        KnobState &knobState,
        AnimationState &animationState);

    static uint32_t getColor(
        Adafruit_NeoPixel *neoPixels,
        uint8_t value);

    static uint8_t getPositionOffset(
        uint8_t pos,
        uint8_t numberOfPixels,
        uint8_t offset);
};

#endif
