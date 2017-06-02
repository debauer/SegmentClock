// #include <FastGPIO.h>
// #define APA102_USE_FAST_GPIO

#include <FastLED.h>
#include "defines.h"
#define MAIN
#include "arrays.h"
#undef MAIN
#include "helper.h"
#include "effects.h"


#define UPDATES_PER_SECOND 100

const uint8_t brightness = 10; //0-255

void setup(){
  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<APA102, 12,11>(leds, LED_COUNT).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  brightness );
  
  clearAll();
}


void loop(){
  static uint16_t h=0;
  //gradientRow();
  gradientCol();
  //white();
  //setNr(1,1);
  //snake();
  //setStripLed(1,0xFF0000);
  /*setLetter(LETTER_F,0);
  setLetter(LETTER_U,1);
  setLetter(LETTER_C,2);
  setLetter(LETTER_K,3);*/
  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);
  // *** REPLACE FROM HERE ***

}
