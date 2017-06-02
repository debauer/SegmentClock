#ifndef helper_H
#define helper_H

#include <FastLED.h>
#include "helper.h"

#include "defines.h"
#include "arrays.h"

#ifdef __cplusplus
extern "C" {
#endif

CRGB hsvToRgb(uint16_t h, uint8_t s, uint8_t v);
void setColColor(uint8_t col, CRGB x);
void setStrip(uint8_t nr, CRGB x);
void setColor(uint16_t x, CRGB c, uint8_t segment = 0);
void setColColor(uint8_t col, CRGB x);
void setRowColor(uint8_t row, CRGB x);
void setStripLed(uint8_t nr, CRGB x);
void setStripLedNormalized(uint8_t nr, CRGB x);
void clearAll();
void setNr( uint8_t nr, uint8_t element = 0);
void setLetter(uint8_t l, uint8_t element = 0);

#ifdef __cplusplus
}
#endif

#endif