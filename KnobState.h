#ifndef KNOBSTATE_H
#define KNOBSTATE_H

/* bring in the Arduino-y goodness */
#include <Arduino.h>

class KnobState {
    /* define potentiometer knobs */
    char KNOB_1 = 0;
    char KNOB_2 = 0;
    char KNOB_3 = 0;
    char KNOB_4 = 0;

    /* vars for tracking knob positions */
    uint16_t lastValueKnob1 = 0;
    uint16_t lastValueKnob2 = 0;
    uint16_t lastValueKnob3 = 0;
    uint16_t lastValueKnob4 = 0;

  public:
    KnobState();
    KnobState(char knob1, char knob2, char knob3, char knob4);
    void begin();

    boolean haveKnobsChanged();
    uint16_t analogInputToValue(uint8_t pin, uint16_t maxValue);

    uint16_t getValueKnob1();
    uint16_t getValueKnob1(uint16_t maxValue);

    uint16_t getValueKnob2();
    uint16_t getValueKnob2(uint16_t maxValue);

    uint16_t getValueKnob3();
    uint16_t getValueKnob3(uint16_t maxValue);

    uint16_t getValueKnob4();
    uint16_t getValueKnob4(uint16_t maxValue);
};

#endif
