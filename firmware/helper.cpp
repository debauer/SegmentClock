
#include "helper.h"

CRGB hsvToRgb(uint16_t h, uint8_t s, uint8_t v)
{
    uint8_t f = (h % 60) * 255 / 60;
    uint8_t p = (255 - s) * (uint16_t)v / 255;
    uint8_t q = (255 - f * (uint16_t)s / 255) * (uint16_t)v / 255;
    uint8_t t = (255 - (255 - f) * (uint16_t)s / 255) * (uint16_t)v / 255;
    uint8_t r = 0, g = 0, b = 0;
    switch((h / 60) % 6){
        case 0: r = v; g = t; b = p; break;
        case 1: r = q; g = v; b = p; break;
        case 2: r = p; g = v; b = t; break;
        case 3: r = p; g = q; b = v; break;
        case 4: r = t; g = p; b = v; break;
        case 5: r = v; g = p; b = q; break;
    }
    return (CRGB){r, g, b};
}

void setColor(uint16_t x, CRGB c, uint8_t segment){
  uint16_t offset = 0;
  offset = segment * 110;
  if(POINTS){
    offset = offset + (POINTS*4);
  }
  if(DOUBLEPOINTS){
    offset = offset + (DOUBLEPOINTS*8);
  }
  leds[offset + x] = c;
}

void setStrip(uint8_t nr, CRGB x){
  for(int i=nr*10;i<nr*10+10;i++){
        leds[i] = x;
  }
}

void setStripLed(uint8_t nr, CRGB x){
  for(uint16_t i = 0; i<LED_COUNT; i=i+10){
    leds[i+nr] = x;
  }
}

void setStripLedNormalized(uint8_t nr, CRGB x){
  for(uint16_t i = 0; i<LED_COUNT; i=i+10){
  	switch((int)(i)/10){
  		case 1: case 12: case 23: case 34: case 3: case 14: case 25: case 36:
  			leds[i+9-nr] = x;
  			break;
  		case 0: case 11: case 22: case 33: case 2: case 13: case 24: case 35:
  			leds[i+nr] = x;
  			break;
  		default: 
  			//leds[i+nr] = x;
  			break;
  	}
  }
}

void setColColor(uint8_t col, CRGB x){
  uint8_t i,t;
  uint8_t c ;
  if(col >=36){t=3;c = 47-col;}
  else if(col >=24){t=2;c = 35-col;}
  else if(col >=12){t=1;c = 23-col;}
  else {t=0;c = 11-col;}
  switch(c){
    case 0:
      setStrip((t*11)+6,x);
      setStrip((t*11)+10,x);
    break;
    case 1: 
      setColor((t*110)+19,x);setColor((t*110)+18,x);setColor((t*110)+20,x);setColor((t*110)+21,x);setColor((t*110)+59,x);setColor((t*110)+99,x);setColor((t*110)+70,x);
      break;
    case 2: 
      setColor((t*110)+17,x);setColor((t*110)+16,x);setColor((t*110)+15,x);setColor((t*110)+22,x);setColor((t*110)+23,x);setColor((t*110)+24,x);setColor((t*110)+58,x);setColor((t*110)+98,x);setColor((t*110)+71,x);
      break;
    case 3: 
      setColor((t*110)+14,x);setColor((t*110)+13,x);setColor((t*110)+12,x);setColor((t*110)+25,x);setColor((t*110)+26,x);setColor((t*110)+27,x);setColor((t*110)+57,x);setColor((t*110)+97,x);setColor((t*110)+72,x);
      break;
    case 4: 
      setColor((t*110)+11,x);setColor((t*110)+10,x);setColor((t*110)+28,x);setColor((t*110)+29,x);setColor((t*110)+56,x);setColor((t*110)+96,x);setColor((t*110)+73,x);
      break;
    case 5: 
      setColor((t*110)+55,x);setColor((t*110)+95,x);setColor((t*110)+74,x);
      break;
    case 6: 
      setColor((t*110)+54,x);setColor((t*110)+94,x);setColor((t*110)+75,x);
      break;
    case 7: 
      setColor((t*110)+9,x);setColor((t*110)+8,x);setColor((t*110)+30,x);setColor((t*110)+31,x);setColor((t*110)+53,x);setColor((t*110)+93,x);setColor((t*110)+76,x);
      break;
    case 8: 
      setColor((t*110)+5,x);setColor((t*110)+6,x);setColor((t*110)+7,x);setColor((t*110)+32,x);setColor((t*110)+33,x);setColor((t*110)+34,x);setColor((t*110)+52,x);setColor((t*110)+92,x);setColor((t*110)+77,x);
      break;
    case 9: 
      setColor((t*110)+2,x);setColor((t*110)+3,x);setColor((t*110)+4,x);setColor((t*110)+35,x);setColor((t*110)+36,x);setColor((t*110)+37,x);setColor((t*110)+51,x);setColor((t*110)+91,x);setColor((t*110)+78,x);
      break;
    case 10: 
      setColor((t*110)+0,x);setColor((t*110)+1,x);setColor((t*110)+38,x);setColor((t*110)+39,x);setColor((t*110)+50,x);setColor((t*110)+90,x);setColor((t*110)+79,x);
      break;
    case 11:
      setStrip((t*11)+4,x);
      setStrip((t*11)+8,x);
    break;
  }
}


void setRowColor(uint8_t row, CRGB x){
  uint8_t i;
  uint8_t r = 22-row;
  for(int t=0; t<4;t++){
    switch(r){
      case 0:
        setStrip((t*11)+5,x);
      break;
      case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 10:
          setColor((t*110)+30-r,x);setColor((t*110)+29+r,x);setColor((t*110)+50-r,x);setColor((t*110)+59+r,x);
          break;
      case 11:
        for(i=70;i<80;i++){
          setColor((t*110)+i,x);
        }
        break;
      case 12:case 13:case 14:case 15:case 16:case 17:case 18:case 19:case 20:case 21:
          setColor((t*110)+0+r-12,x);setColor((t*110)+20-r+11,x);setColor((t*110)+80+r-12,x);setColor((t*110)+110-r+11,x);
          break;
      case 22:
        setStrip((t*11)+9,x);
        break;
    }
  }
}

void clearAll(){
  CRGB c = 0x000000;
  for(uint16_t i = 0; i<LED_COUNT; i++){
    leds[i] = c;
  }
}

void setLetter(uint8_t l, uint8_t element){
  CRGB c = 0x000000;
  for(int i=0; i<11; i++){
    if(letter[l][i]==0){
      setStrip((element*11)+i,c);
    }else if(letter[l][i]==2){
      for(int k=0;k<5;k++){
        setColor((element*110)+i*10+k,c);
      }
    }else if(letter[l][i]==3){
      for(int k=0;k<5;k++){
        setColor((element*110)+i*10+9-k,c);
      }
    }
  }
}

void setNr( uint8_t nr, uint8_t element){
  CRGB c = 0x000000;
  setStrip((element*11)+0,c);setStrip((element*11)+1,c);setStrip((element*11)+2,c);setStrip((element*11)+3,c);
  for(int i=0; i<7; i++){
    if(number[nr][i]==0){
      setStrip((element*11)+i+4,c);
    }
  }
}