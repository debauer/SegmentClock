
#include "effects.h"

void snake(){
	static int k = 0;
	//clearAll();
	switch(k){
		default:
			setStripLedNormalized(k-2, 0x222222);
			setStripLedNormalized(k-1, 0x222222);
			setStripLedNormalized(k, 	0xFFFF00);
			break;
		case 0:
			setStripLedNormalized( 8, 0x222222);
			setStripLedNormalized( 9, 0x222222);
			setStripLedNormalized( 0, 0xFFFF00);
			break;
		case 1:
			setStripLedNormalized(9, 0x222222);
			setStripLedNormalized(0, 0x222222);
			setStripLedNormalized(1, 0xFFFF00);
			break;
		case 12: case 11: case 10:
			break;
			}
	k++;
	delay(100);
	if(k==12){
		k=0;
	}
}

void white(){
  for(int i=0;i<LED_COUNT;i++){
    setColor(i, (CRGB)0xFFFFFF);
  }
}

void sweepLetters(uint8_t next){
  static uint8_t r = 0;
  if(next){
    r = r+1;
    if(r>25){
      r=0;
    }
  }
  setLetter(r);
}

void sweepNr(uint8_t next){
  static uint8_t r = 0;
  if(next){
    r = r+1;
    if(r>9){
      r=0;
    }
  }
  setNr(r,0);
}

void gradientCol(){
  uint8_t i;
  uint8_t time = millis() >> 4;
  uint8_t p = time - i * 8;
  for(i=0;i<=48;i++){
    setColColor(i,hsvToRgb((uint32_t)(p+(i*2)) * 359 / 256, 255, 255)); 
  }
}

void gradientRow(){
  uint8_t i;
  uint8_t time = millis() >> 4;
  uint8_t p = time - i * 8;
  for(i=0;i<=22;i++){
    setRowColor(i,hsvToRgb((uint32_t)(p+(i*2)) * 359 / 256, 255, 255)); 
  }
}