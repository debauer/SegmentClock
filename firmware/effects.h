#ifndef EFFECTS_H
#define EFFECTS_H

#include <FastLED.h>
#include "helper.h"

#include "defines.h"
#include "arrays.h"

#ifdef __cplusplus
extern "C" {
#endif

void snake();
void sweepNr(uint8_t next=1);
void gradientCol();
void gradientRow();
void white();

#ifdef __cplusplus
}
#endif

#endif