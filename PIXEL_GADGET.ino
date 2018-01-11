#include "PixelGadget.h"

/* vars for the potentiometer knobs */
char KNOB_1 = A1;
char KNOB_2 = A0;
char KNOB_3 = A2;
char KNOB_4 = A3;

/* vars for the NeoPixel ring */
#define PIN_RGBW_RING 6
const int NUM_PIXELS = 24;

/* create a new instance of the PixelGadget */
PixelGadget pixelGadget = PixelGadget();

/* init pixel ring */
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIN_RGBW_RING, NEO_RGBW + NEO_KHZ800);

/* vars for the button(s) */
#define PIN_BUTTON 2
const int DEBOUNCE_TIMEOUT = 50;
unsigned long buttonLastPressed = 0;

void setup() {
  /* init the button */
  /* --MUST BE ON A PIN THAT SUPPORTS INTERRUPTS-- */
  pinMode(PIN_BUTTON, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_BUTTON), changeMode, LOW);

  /* pass a reference to the neopixels to the pixelGadget */
  pixelGadget.setNeoPixels(pixels, NUM_PIXELS);

  /* configure the pixelGadget's I/O */
  pixelGadget.setKnobPins(KNOB_1, KNOB_2, KNOB_3, KNOB_4);
  pixelGadget.begin();
}

/* called by an interrupt: changes animation mode */
void changeMode() {
  /* debounce the button */
  if (millis() - buttonLastPressed < DEBOUNCE_TIMEOUT) {
    return;
  }

  /* update button press for debounce */
  buttonLastPressed = millis();
  
  /* tell the pixelGadget to change modes */
  pixelGadget.changeMode();
}

void loop() {
  /* call the run method */
  pixelGadget.run();
}
