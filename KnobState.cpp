#include "KnobState.h";

KnobState::KnobState() {
  
}

KnobState::KnobState(char knob1, char knob2, char knob3, char knob4) {
  /* assign knobs to instance vars */
  KNOB_1 = knob1;
  KNOB_2 = knob2;
  KNOB_3 = knob3;
  KNOB_4 = knob4;
}

void KnobState::begin() {
  /* setup the potentiometer knobs */
  /* init potentiometer pins */
  pinMode(KNOB_1, INPUT);
  pinMode(KNOB_2, INPUT);
  pinMode(KNOB_3, INPUT);
  pinMode(KNOB_4, INPUT);
}

/**
   Updates the lastValue for each knob and returns true if any
   of the knob positions have changed.
*/
boolean KnobState::haveKnobsChanged() {
  /* read the knob values */
  uint16_t valueKnob1 = analogInputToValue(KNOB_1, 255);
  uint16_t valueKnob2 = analogInputToValue(KNOB_2, 255);
  uint16_t valueKnob3 = analogInputToValue(KNOB_3, 255);
  uint16_t valueKnob4 = analogInputToValue(KNOB_4, 255);

  boolean hasChanged = false;

  if (valueKnob1 != lastValueKnob1 ) {
    hasChanged = true;
  }

  if (valueKnob2 != lastValueKnob2 ) {
    hasChanged = true;
  }

  if (valueKnob3 != lastValueKnob3 ) {
    hasChanged = true;
  }

  if (valueKnob4 != lastValueKnob4 ) {
    hasChanged = true;
  }

  /* update the last knob values */
  if (hasChanged) {
    lastValueKnob1 = valueKnob1;
    lastValueKnob2 = valueKnob2;
    lastValueKnob3 = valueKnob3;
    lastValueKnob4 = valueKnob4;
  }

  return hasChanged;
}

/**
   Represents the analog value on the specified pin as a percentage
   of the maxValue parameter. For example, if you are using a potentiometer
   and it's turned half way and you provided 100 as the maxValue param,
   the output would be 50.
*/
uint16_t KnobState::analogInputToValue(uint8_t pin, uint16_t maxValue) {
  uint16_t reading = analogRead(pin);
  float valueAsPercent = (float) reading / 1020.00;
  return valueAsPercent * maxValue;
}

uint16_t KnobState::getValueKnob1() {
  analogRead(KNOB_1);
}

uint16_t KnobState::getValueKnob1(uint16_t maxValue) {
  return analogInputToValue(KNOB_1, maxValue);
}

uint16_t KnobState::getValueKnob2() {
  analogRead(KNOB_2);
}

uint16_t KnobState::getValueKnob2(uint16_t maxValue) {
  return analogInputToValue(KNOB_2, maxValue);
}

uint16_t KnobState::getValueKnob3() {
  analogRead(KNOB_3);
}

uint16_t KnobState::getValueKnob3(uint16_t maxValue) {
  return analogInputToValue(KNOB_3, maxValue);
}

uint16_t KnobState::getValueKnob4() {
  analogRead(KNOB_4);
}

uint16_t KnobState::getValueKnob4(uint16_t maxValue) {
  return analogInputToValue(KNOB_4, maxValue);
}

