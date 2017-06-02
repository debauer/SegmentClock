#ifndef DEFINES_H_   /* Include guard */
#define DEFINES_H_

// wiring 11SEG -> point -> doublepoint -> 11SEG
#define SEGMENTS 4
#define POINTS 0 // SEGMENTS -1
#define DOUBLEPOINTS 0 // SEGMENTS -1
#define LED_COUNT 440 // (SEGMENTS*10*11)+(POINTS*4)+(DOUBLEPOINTS*8)

#define ROWS 22
#define COLUMNS 12*SEGMENTS+2*POINTS // or DOUBLEPOINTS of no POINTS

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

#endif