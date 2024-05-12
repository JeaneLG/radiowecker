//global vars and definitions for radiowecker not defined in ino file
#ifndef RADIOWECKER_VARS_h
#define RADIOWECKER_VARS_h

#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#include "fonts.h"

//pins for display
#define TFT_CS   5
#define TFT_DC   4
#define TFT_RST  22
#define TFT_LED  15
#define LED_ON 0

//define names for fonts
#define FNT9 &AT_Standard9pt7b
#define FNT12 &AT_Bold12pt7b

//day and month names in German
const char* const PROGMEM days[] = {"Sonntag","Montag","Dienstag","Mittwoch","Donnerstag","Freitag","Samstag"};
const char* const PROGMEM days_short[] = {"So","Mo","Di","Mi","Do","Fr","Sa"};
const char* PROGMEM months[] = {"Jan.","Feb.","März","April","Mai","Juni","Juli","Aug.","Sept.","Okt.","Nov.","Dez."};

//instance of display driver
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);


// prototype for 'textInBox' defined in tft_display.ino
void textInBox(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const char* text, uint8_t align = ALIGNLEFT, boolean big = false, uint16_t fc = ILI9341_WHITE , uint16_t bg = ILI9341_BLACK, uint8_t lines = 1);

//Prototype created (i have now optional Arguments) the function down like before
void showSlider(uint16_t y, float value, uint16_t vmax, uint16_t bgColor = ILI9341_LIGHTGREY, uint16_t lineColor = ILI9341_BLACK);

#endif
