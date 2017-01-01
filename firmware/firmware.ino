// #include <FastGPIO.h>
// #define APA102_USE_FAST_GPIO

#include <APA102.h>

// Define which pins to use.
const uint8_t dataPin = 8;
const uint8_t clockPin = 7;

APA102<dataPin, clockPin> ledStrip;

// wiring 11SEG -> point -> doublepoint -> 11SEG
#define SEGMENTS 1
#define POINTS 0
#define DOUBLEPOINTS 0
#define LED_COUNT (SEGMENTS*10*11)+(POINTS*4)+(DOUBLEPOINTS*8)

#define LETTER_A 0
#define LETTER_B 1
#define LETTER_C 2
#define LETTER_D 3
#define LETTER_E 4
#define LETTER_F 5
#define LETTER_G 6
#define LETTER_H 7
#define LETTER_I 8
#define LETTER_J 9
#define LETTER_K 10
#define LETTER_L 11
#define LETTER_M 12
#define LETTER_N 13
#define LETTER_O 14
#define LETTER_P 15
#define LETTER_Q 16
#define LETTER_R 17
#define LETTER_S 18
#define LETTER_T 19
#define LETTER_U 20
#define LETTER_V 21
#define LETTER_W 22
#define LETTER_X 23
#define LETTER_Y 24
#define LETTER_Z 25

const uint16_t ledCount = LED_COUNT;
rgb_color colors[ledCount];


// geht nicht: M,N,Q,T,W,X,Y,Z
uint8_t letter[26][11] = {{0,0,1,1,0,0,0,1,1,0,1}, // A
                         {0,0,0,0,1,1,1,1,1,1,1}, // B
                         {0,0,0,0,0,1,1,0,0,1,1}, // C
                         {0,0,0,0,1,1,1,0,1,1,1}, // D
                         {0,0,0,0,0,1,1,3,0,1,1}, // E
                         {0,0,0,0,0,1,1,3,0,0,1}, // F
                         {0,0,0,0,2,1,1,2,1,1,1}, // G
                         {0,0,0,0,1,0,1,1,1,0,1}, // H
                         {0,0,0,0,1,0,0,0,1,0,0}, // I
                         {0,0,0,0,1,3,0,0,1,1,0}, // J
                         {0,1,1,0,0,0,1,0,0,0,1}, // K
                         {0,0,0,0,0,0,1,0,0,1,1}, // L
                         {1,1,1,1,1,1,1,1,1,1,1}, // M
                         {1,1,1,1,1,1,1,1,1,1,1}, // N
                         {0,0,0,0,1,1,1,0,1,1,1}, // O
                         {0,0,0,0,1,1,1,1,0,0,1}, // P
                         {1,1,1,1,1,1,1,1,1,1,1}, // Q
                         {0,1,0,0,1,1,1,1,0,0,1}, // R
                         {0,0,0,0,0,1,1,1,1,1,0}, // S
                         {1,1,1,1,1,1,1,1,1,1,1}, // T
                         {0,0,0,0,1,0,1,0,1,1,1}, // U
                         {1,1,0,0,1,0,1,0,0,0,0}, // V
                         {1,1,1,1,1,1,1,1,1,1,1}, // W
                         {1,1,1,1,1,1,1,1,1,1,1}, // X
                         {1,1,1,1,1,1,1,1,1,1,1}, // Y
                         {1,1,1,1,1,1,1,1,1,1,1} // Z
                         };

uint8_t number[10][8] = {{1,1,1,0,1,1,1}, // 0
                    {1,0,0,0,1,0,0},  // 1
                    {1,1,0,1,0,1,1},  // 2
                    {1,1,0,1,1,1,0},  // 3
                    {1,0,1,1,1,0,0},  // 4
                    {0,1,1,1,1,1,0},  // 5
                    {0,1,1,1,1,1,1},  // 6
                    {1,1,0,0,1,0,0},  // 7
                    {1,1,1,1,1,1,1},  // 8
                    {1,1,1,1,1,1,0}};  // 9

const uint8_t brightness = 1; // max 31

rgb_color hsvToRgb(uint16_t h, uint8_t s, uint8_t v)
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
    return (rgb_color){r, g, b};
}

void setStrip(uint8_t nr, rgb_color x){
  for(int i=nr*10;i<nr*10+10;i++){
        colors[i] = x;
  }
}

void setColColor(uint8_t col, rgb_color x){
  uint8_t i;
  switch(col){
    case 0:
      setStrip(6,x);
      setStrip(10,x);
    break;
    case 1: 
      colors[19] = x;colors[18] = x;colors[20] = x;colors[21] = x;colors[59] = x;colors[99] = x;colors[70] = x;
      break;
    case 2: 
      colors[17] = x;colors[16] = x;colors[15] = x;colors[22] = x;colors[23] = x;colors[24] = x;colors[58] = x;colors[98] = x;colors[71] = x;
      break;
    case 3: 
      colors[14] = x;colors[13] = x;colors[12] = x;colors[25] = x;colors[26] = x;colors[27] = x;colors[57] = x;colors[97] = x;colors[72] = x;
      break;
    case 4: 
      colors[11] = x;colors[10] = x;colors[28] = x;colors[29] = x;colors[56] = x;colors[96] = x;colors[73] = x;
      break;
    case 5: 
      colors[55] = x;colors[95] = x;colors[74] = x;
      break;
    case 6: 
      colors[54] = x;colors[94] = x;colors[75] = x;
      break;
    case 7: 
      colors[9] = x;colors[8] = x;colors[30] = x;colors[31] = x;colors[53] = x;colors[93] = x;colors[76] = x;
      break;
    case 8: 
      colors[5] = x;colors[6] = x;colors[7] = x;colors[32] = x;colors[33] = x;colors[34] = x;colors[52] = x;colors[92] = x;colors[77] = x;
      break;
    case 9: 
      colors[2] = x;colors[3] = x;colors[4] = x;colors[35] = x;colors[36] = x;colors[37] = x;colors[51] = x;colors[91] = x;colors[78] = x;
      break;
    case 10: 
      colors[0] = x;colors[1] = x;colors[38] = x;colors[39] = x;colors[50] = x;colors[90] = x;colors[79] = x;
      break;
    case 11:
      setStrip(4,x);
      setStrip(8,x);
    break;
  }
}

void setRowColor(uint8_t row, rgb_color x){
  uint8_t i;
  switch(row){
    case 0:
      setStrip(5,x);
    break;
    case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 10:
        colors[30-row] = x;colors[29+row] = x;colors[50-row] = x;colors[59+row] = x;
        break;
    case 11:
      for(i=70;i<80;i++){
        colors[i] = x;
      }
      break;
    case 12:case 13:case 14:case 15:case 16:case 17:case 18:case 19:case 20:case 21:
        colors[0+row-12] = x;colors[20-row+11] = x;colors[80+row-12] = x;colors[110-row+11] = x;
        break;
    case 22:
      setStrip(9,x);
      break;
  }
}

void clearAll(){
  rgb_color c = {0,0,0};
  for(int i = 0; i<ledCount; i++){
    colors[i] = c;
  }
}

void setLetter(uint8_t l){
  rgb_color c = {0,0,0};
  for(int i=0; i<11; i++){
    if(letter[l][i]==0){
      setStrip(i,c);
    }else if(letter[l][i]==2){
      for(int k=0;k<5;k++){
        colors[i*10+k] = c;
      }
    }else if(letter[l][i]==3){
      for(int k=0;k<5;k++){
        colors[i*10+9-k] = c;
      }
    }
  }
}

void setNr(uint8_t nr){
  rgb_color c = {0,0,0};
  setStrip(0,c);setStrip(1,c);setStrip(2,c);setStrip(3,c);
  for(int i=0; i<7; i++){
    if(number[nr][i]==0){
      setStrip(i+4,c);
    }
  }
}

void setup(){
  clearAll();
}
uint8_t r = 0, h=0;
void loop(){
  uint8_t i;
  uint8_t time = millis() >> 4;
  uint8_t p = time - i * 8;
  for(i=0;i<=22;i++){
    setRowColor(i,hsvToRgb((uint32_t)(p+(i*5)) * 359 / 256, 255, 255)); 
  }
  h=h+1;
  setNr(r);
  if(h>5){
    h=0;
    r = r+1;
    if(r>9){
      r=0;
    }
  }
  //setLetter(1);
  ledStrip.write(colors, ledCount, brightness);
}
