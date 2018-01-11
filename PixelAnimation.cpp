#include "PixelAnimation.h"

void PixelAnimation::singlePixel(
    Adafruit_NeoPixel *neoPixels,
    uint8_t numberOfPixels,
    KnobState &knobState)
{

    neoPixels->clear();

    /* get the position of knob 1 */
    uint16_t pixelPosition = knobState.getValueKnob1(numberOfPixels);

    /* get the color from knob 2 */
    uint8_t positionKnob2 = knobState.getValueKnob2(255);
    uint32_t color = PixelAnimation::getColor(neoPixels, positionKnob2);

    neoPixels->setPixelColor(pixelPosition, color);
    neoPixels->show();
}

void PixelAnimation::singlePixelRotate(
    Adafruit_NeoPixel *neoPixels,
    uint8_t numberOfPixels,
    KnobState &knobState,
    AnimationState &animationState)
{
    /* get the value of knob 1 w/ 1000ms max */
    uint16_t delayValue = knobState.getValueKnob1(500);
    /* set the delay in animationState */
    animationState.setDelayPosition1(delayValue);

    /* tick the position */
    animationState.tickPosition1();

    /* get the color from knob 2 */
    uint8_t positionKnob2 = knobState.getValueKnob2(255);
    uint32_t color = PixelAnimation::getColor(neoPixels, positionKnob2);

    neoPixels->clear();
    neoPixels->setPixelColor(
        animationState.getPosition1(),
        color);
    neoPixels->show();
}

void PixelAnimation::singlePixelRotateFader(
    Adafruit_NeoPixel *neoPixels,
    uint8_t numberOfPixels,
    KnobState &knobState,
    AnimationState &animationState)
{
    /* get the value of knob 1 for motion timeout*/
    uint16_t delayValue = knobState.getValueKnob1(500);
    /* set the delay in animationState */
    animationState.setDelayPosition1(delayValue);

    /* get the value of knob 2  for fade timeout*/
    uint16_t delayValue2 = knobState.getValueKnob2(500);
    /* set the delay in animationState */
    animationState.setDelayColor1(delayValue2);

    /* tick the position */
    animationState.tickPosition1();

    /* tick the color */
    animationState.tickColor1();

    /* set the color */
    uint32_t color = PixelAnimation::getColor(
        neoPixels,
        animationState.getColor1());

    neoPixels->clear();
    neoPixels->setPixelColor(
        animationState.getPosition1(),
        color);
    neoPixels->show();
}

void PixelAnimation::doublePixels(
    Adafruit_NeoPixel *neoPixels,
    uint8_t numberOfPixels,
    KnobState &knobState)
{
    neoPixels->clear();

    /* get the position of knob 1 */
    uint16_t pixelPosition1 = knobState.getValueKnob1(numberOfPixels);

    /* get the position of knob 2 */
    uint16_t pixelPosition2 = knobState.getValueKnob2(numberOfPixels);

    /* get the position of knob 3 */
    uint16_t positionKnob3 = knobState.getValueKnob3(255);
    uint32_t color1 = PixelAnimation::getColor(neoPixels, positionKnob3);

    /* get the position of knob 4 */
    uint8_t positionKnob4 = knobState.getValueKnob4(255);
    uint32_t color2 = PixelAnimation::getColor(neoPixels, positionKnob4);

    neoPixels->setPixelColor(pixelPosition1, color1);
    neoPixels->setPixelColor(pixelPosition2, color2);

    neoPixels->show();
}

void PixelAnimation::quadPixels(
    Adafruit_NeoPixel *neoPixels,
    uint8_t numberOfPixels,
    KnobState &knobState)
{
    uint16_t offset = knobState.getValueKnob1(numberOfPixels);
    uint16_t positionKnob2 = knobState.getValueKnob2(255);
    uint32_t color = PixelAnimation::getColor(neoPixels, positionKnob2);

    int posPixel1 =
        PixelAnimation::getPositionOffset(0, numberOfPixels, offset);

    int posPixel2 =
        PixelAnimation::getPositionOffset(numberOfPixels / 4, numberOfPixels, offset);

    int posPixel3 =
        PixelAnimation::getPositionOffset(numberOfPixels / 2, numberOfPixels, offset);

    int posPixel4 =
        PixelAnimation::getPositionOffset((numberOfPixels / 4) * 3, numberOfPixels, offset);

    neoPixels->clear();
    neoPixels->setPixelColor(posPixel1, color);
    neoPixels->setPixelColor(posPixel2, color);
    neoPixels->setPixelColor(posPixel3, color);
    neoPixels->setPixelColor(posPixel4, color);
    neoPixels->show();
}

void PixelAnimation::quadPixelsRotate(
    Adafruit_NeoPixel *neoPixels,
    uint8_t numberOfPixels,
    KnobState &knobState,
    AnimationState &animationState)
{
    /* update the motion delay */
    uint16_t delayValue = knobState.getValueKnob1(500);
    /* set the delay in animationState */
    animationState.setDelayPosition1(delayValue);

    /* tick position1 */
    animationState.tickPosition1();

    uint16_t offset = animationState.getPosition1();

    /* get the color */
    uint16_t positionKnob2 = knobState.getValueKnob2(255);
    uint32_t color = PixelAnimation::getColor(neoPixels, positionKnob2);

    int posPixel1 =
        PixelAnimation::getPositionOffset(0, numberOfPixels, offset);

    int posPixel2 =
        PixelAnimation::getPositionOffset(numberOfPixels / 4, numberOfPixels, offset);

    int posPixel3 =
        PixelAnimation::getPositionOffset(numberOfPixels / 2, numberOfPixels, offset);

    int posPixel4 =
        PixelAnimation::getPositionOffset((numberOfPixels / 4) * 3, numberOfPixels, offset);

    neoPixels->clear();
    neoPixels->setPixelColor(posPixel1, color);
    neoPixels->setPixelColor(posPixel2, color);
    neoPixels->setPixelColor(posPixel3, color);
    neoPixels->setPixelColor(posPixel4, color);
    neoPixels->show();
}

void PixelAnimation::quadPixelsRotateFader(
    Adafruit_NeoPixel *neoPixels,
    uint8_t numberOfPixels,
    KnobState &knobState,
    AnimationState &animationState)
{
    /* update the motion delay */
    uint16_t delayValue = knobState.getValueKnob1(500);
    /* set the delay in animationState */
    animationState.setDelayPosition1(delayValue);

    /* get the value of knob 2 for fade timeout*/
    uint16_t delayValue2 = knobState.getValueKnob2(500);
    /* set the delay in animationState */
    animationState.setDelayColor1(delayValue2);

    /* tick position 1 */
    animationState.tickPosition1();

    /* tick color 1 */
    animationState.tickColor1();

    uint16_t offset = animationState.getPosition1();

    /* get the color */
    uint32_t color =
        PixelAnimation::getColor(
            neoPixels,
            animationState.getColor1());

    int posPixel1 =
        PixelAnimation::getPositionOffset(0, numberOfPixels, offset);

    int posPixel2 =
        PixelAnimation::getPositionOffset(numberOfPixels / 4, numberOfPixels, offset);

    int posPixel3 =
        PixelAnimation::getPositionOffset(numberOfPixels / 2, numberOfPixels, offset);

    int posPixel4 =
        PixelAnimation::getPositionOffset((numberOfPixels / 4) * 3, numberOfPixels, offset);

    neoPixels->clear();
    neoPixels->setPixelColor(posPixel1, color);
    neoPixels->setPixelColor(posPixel2, color);
    neoPixels->setPixelColor(posPixel3, color);
    neoPixels->setPixelColor(posPixel4, color);
    neoPixels->show();
}

void PixelAnimation::halves(
    Adafruit_NeoPixel *neoPixels,
    uint8_t numberOfPixels,
    KnobState &knobState)
{

    /* get the position of knob 1 */
    uint16_t positionKnob1 = knobState.getValueKnob1(255);
    uint32_t color1 = PixelAnimation::getColor(neoPixels, positionKnob1);

    /* get the position of knob 2 */
    uint8_t positionKnob2 = knobState.getValueKnob2(255);
    uint32_t color2 = PixelAnimation::getColor(neoPixels, positionKnob2);

    /* figure out the offset using knob 3 */
    uint16_t offset = knobState.getValueKnob3(numberOfPixels);

    /* half 1 */
    for (uint8_t i = 0; i < numberOfPixels / 2; i++)
    {
        int pos1 =
            PixelAnimation::getPositionOffset(i, numberOfPixels, offset);
        neoPixels->setPixelColor(pos1, color1);
    }

    /* half 2 */
    for (uint8_t j = numberOfPixels / 2; j < numberOfPixels; j++)
    {
        int pos2 =
            PixelAnimation::getPositionOffset(j, numberOfPixels, offset);
        neoPixels->setPixelColor(pos2, color2);
    }

    neoPixels->show();
}

void PixelAnimation::halvesRotate(
    Adafruit_NeoPixel *neoPixels,
    uint8_t numberOfPixels,
    KnobState &knobState,
    AnimationState &animationState)
{
    /* get the position of knob 1 */
    uint16_t positionKnob1 = knobState.getValueKnob1(255);
    uint32_t color1 = PixelAnimation::getColor(neoPixels, positionKnob1);

    /* get the position of knob 2 */
    uint8_t positionKnob2 = knobState.getValueKnob2(255);
    uint32_t color2 = PixelAnimation::getColor(neoPixels, positionKnob2);

    /* update the motion delay */
    uint16_t delayValue = knobState.getValueKnob3(500);
    /* set the delay in animationState */
    animationState.setDelayPosition1(delayValue);

    /* tick position 1 */
    animationState.tickPosition1();

    uint8_t offset = animationState.getPosition1();

    /* half 1 */
    for (uint8_t i = 0; i < numberOfPixels / 2; i++)
    {
        int pos1 =
            PixelAnimation::getPositionOffset(i, numberOfPixels, offset);
        neoPixels->setPixelColor(pos1, color1);
    }

    /* half 2 */
    for (uint8_t j = numberOfPixels / 2; j < numberOfPixels; j++)
    {
        int pos2 =
            PixelAnimation::getPositionOffset(j, numberOfPixels, offset);
        neoPixels->setPixelColor(pos2, color2);
    }

    neoPixels->show();
}

uint8_t PixelAnimation::getPositionOffset(
    uint8_t pos,
    uint8_t numberOfPixels,
    uint8_t offset)
{

    int value = pos + offset;

    if (value < numberOfPixels)
    {
        return value;
    }

    return value % numberOfPixels;
}

/**
   Adafruit's colorWheel implementation for getting a color between 0 and 255
*/
uint32_t PixelAnimation::getColor(
    Adafruit_NeoPixel *neoPixels,
    uint8_t value)
{
    byte wheelPosition = value & 255;

    if (wheelPosition < 85)
    {
        return neoPixels->Color(255 - wheelPosition * 3, 0, wheelPosition * 3);
    }

    if (wheelPosition < 170)
    {
        wheelPosition -= 85;
        return neoPixels->Color(0, wheelPosition * 3, 255 - wheelPosition * 3);
    }

    wheelPosition -= 170;
    return neoPixels->Color(wheelPosition * 3, 255 - wheelPosition * 3, 0);
}
