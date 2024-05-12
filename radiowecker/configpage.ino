// all things happening on the config page
#include "vars.h"
#include "tft_color_setting.h"
#include "knoepfe.h" //Graphic data for buttons
#include "symbole.h" //Graphic data for symbolic
#include "num_64_44.h" //Graphic data for Fav Buttons

#define DAY_INT 40 // position interval for weekdays on display

// Stuct to store changes of alarm time on config page
typedef struct {
  uint8_t alarmday = 0B00111110;   //valid weekdays (example 00111110 means monday through friday)
  uint8_t h;                       //alarm hour
  uint8_t m;                       //alarm minute
}AlarmEdit;
AlarmEdit alarmConfig;

//selected configuration view
uint8_t configView = 1;


// process a click on the config page
void processConfigpageClick(TS_Point p){
  if (p.y > 180) { //if the y value > 180, we are in the button area
    //we need the p.x position to find which button was clicked
    if (p.x < 64) showCommand(1);
    if ((p.x>64) && (p.x<128)) showCommand(2);
    if ((p.x>128) && (p.x<192)) showCommand(3);
    if ((p.x>192) && (p.x<256)) showCommand(4);
    if (p.x > 256) {//rechter Button zurueck auf Main
      clockmode = true;
      configpage = false;
      radiopage = false;
      showClock();
      return;
    }
  }
  switch (configView) {
    case 4:
      //from 0 to 44 we have the slider for gain
      if ((p.y > 0) && (p.y<44)) setGainValue(p.x, "SettingPage");
      //from 44 to 88 we have the slider for brightness
      if ((p.y > 44) && (p.y<88)) setBrightness(p.x);
      //from 88 to 132 we have the slider for snooze time
      if ((p.y > 88) && (p.y<132)) setSnoozeTime(p.x);
      //from 132 to 175 we have the slider for alarm pause time
      if ((p.y > 132) && (p.y<175)) setAlarmPauseTime(p.x);
      break;
    case 1:
    case 2:
    case 3:
      // Save button
      if ((p.y > 120) && (p.y < 150) && (p.x > 160)) {
        safeAlarmTime();
        break;
      }
      // from 40 to 80 we select a day for the alarm
      if ((p.y > 40) && (p.y < 80)) toggleAlarmDay(p.x);
      // from 89 to 125 we increment the alarmtime
      if ((p.y > 89) && (p.y < 125)) incrementAlarmTime(p.x);
      // from 135 to 175 we decrement the alarmtime
      if ((p.y > 135) && (p.y < 175)) decrementAlarmTime(p.x);
      updateAlarmTime();
  }
}


//display the complete config screen
void showCommand(){
  showCommand(4);
}
void showCommand(uint8_t configPage) {
  configView = configPage;
  setBGLight(100);
  tft.fillScreen(COLOR_BG);
  uint16_t color_temp; // Farbvariable
  //config page 1
  if (configPage == 1) {
      color_temp = ILI9341_GREEN;
      showAlarmTime();
  } else {
      color_temp = COLOR_KNOEPFE;
  }
  tft.fillRect(0,176,64,64,COLOR_KNOEPFE_BG);
  tft.drawBitmap(0,186,num_64_44[0],64,44,color_temp,COLOR_KNOEPFE_BG);
  //config page 2
  if (configPage == 2) {
      color_temp = ILI9341_GREEN;
      showAlarmTime();
  } else {
      color_temp = COLOR_KNOEPFE;
  }
  tft.fillRect(64,176,64,64,COLOR_KNOEPFE_BG);
  tft.drawBitmap(64,186,num_64_44[1],64,44,color_temp,COLOR_KNOEPFE_BG);
  //config page 3
  if (configPage == 3) {
      color_temp = ILI9341_GREEN;
      showAlarmTime();
  } else {
      color_temp = COLOR_KNOEPFE;
  }
  tft.fillRect(128,176,64,64,COLOR_KNOEPFE_BG);
  tft.drawBitmap(128,186,num_64_44[2],64,44,color_temp,COLOR_KNOEPFE_BG);
  //config page 4
  if (configPage == 4) {
      showGain();
      showBrigthness();
      showSnoozeTime();
      showAlarmPauseTime();
      color_temp = ILI9341_GREEN;
  } else {
      color_temp = COLOR_KNOEPFE;
  }  
  tft.drawBitmap(192,176,knopf_sym[6],64,64,color_temp,COLOR_KNOEPFE_BG);
  //Jump to Main (CLOCK SCREEN)
  tft.drawBitmap(256,176,knopf_sym[5],64,64,COLOR_KNOEPFE,COLOR_KNOEPFE_BG);

  start_conf = millis();
}

//-------------------Alarm pause functions-------------------
// draw alarm pause info symbol if active
void drawAlarmPauseInfo(){
    uint16_t color_pause; // Farbvariable
    if (alarmPause) { // Alarm Pause aktiv
        color_pause = COLOR_ALARM_PAUSE_SYMBOL;
    } else {
        color_pause = COLOR_BG;
    }  
    tft.drawBitmap(238, 0, symbole[1], 17, 17, color_pause, COLOR_BG);
}
// display the area to show the alarm pause time on config screen
void showAlarmPauseTime() {
  char txt[20];
  tft.fillRect(0,132,320,44,COLOR_SETTING_BG);
  tft.drawRect(0,132,320,44,COLOR_SETTING_BORDER);
  sprintf(txt,"%i min",alarmPauseTime);
  textInBox(231,140,80,20,txt,ALIGNRIGHT,false,ILI9341_BLACK,COLOR_SETTING_BG,1);
  tft.setCursor(5,155);
  tft.setFont(FNT9);
  tft.setTextColor(ILI9341_BLACK);
  encodeUnicode("Wecker Pause",txt);
  tft.print(txt);
  showSlider(159,alarmPauseTime,30);
}
// set the alarm pause time for x-position where the slider was clicked
void setAlarmPauseTime(uint16_t value) {
  char txt[10];
  //calculate alarm Pause time from x-Position 0 to 30 minutes
  float v = (value - 15) * 0.10;
  if (v > 30) v = 30;
  if (v < 0) v = 0;
  alarmPauseTime = v;
  //save alarm pause time and adjust slider 
  pref.putUShort("alarmPauseTime",alarmPauseTime);
  showSlider(159,alarmPauseTime,30);
  sprintf(txt,"%i min",alarmPauseTime);
  displayMessage(231,140,80,20,txt,ALIGNRIGHT,false,ILI9341_BLACK,COLOR_SETTING_BG,1);
}

//-------------------Alarm Time functions--------------------
//
void showAlarmTime() {
  if (configView == 1) {
    alarmConfig.alarmday = alarmday1;
    alarmConfig.h = alarm1 /60;
    alarmConfig.m = alarm1 % 60;
  } else {
    if (configView == 2){
      alarmConfig.alarmday = alarmday2;
      alarmConfig.h = alarm2 /60;
      alarmConfig.m = alarm2 % 60;
    } else {
      alarmConfig.alarmday = alarmday3;
      alarmConfig.h = alarm3 /60;
      alarmConfig.m = alarm3 % 60;
    }
  }
  tft.fillRect(0,0,320,176,COLOR_SETTING_BG);
  tft.drawRect(0,0,320,176,COLOR_SETTING_BORDER);
  tft.setCursor(2, 30);
  tft.setTextColor(COLOR_SETTING_ALARM_TEXT, COLOR_SETTING_BG);
  tft.setTextSize(2);
  tft.print("Weckzeit ");
  tft.print(configView);
  tft.setTextSize(1);
  tft.print("  ");
  tft.setTextColor(COLOR_SETTING_BORDER2, COLOR_SETTING_BG);
  tft.print("Version: ");
  tft.print(PROGRAM_VERSION);
  tft.setTextSize(2);
  tft.setTextColor(COLOR_SETTING_ALARM_TEXT, COLOR_SETTING_BG);
  tft.setCursor(150, 140);
  tft.print("Speichern");
  tft.drawRect(146,111,169,40,COLOR_SETTING_BORDER);
  tft.drawRect(144,109,173,44,COLOR_SETTING_BORDER2);
  tft.drawBitmap(16,92,symbole2[0],32,16,COLOR_SETTING_UP_DOWN);
  tft.drawRect(8,91,48,18,COLOR_SETTING_BORDER);
  tft.drawBitmap(68,92,symbole2[0],32,16,COLOR_SETTING_UP_DOWN);
  tft.drawRect(67,91,34,18,COLOR_SETTING_BORDER);
  tft.drawBitmap(101,92,symbole2[0],32,16,COLOR_SETTING_UP_DOWN);
  tft.drawRect(100,91,34,18,COLOR_SETTING_BORDER);
  tft.drawBitmap(16,150,symbole2[1],32,16,COLOR_SETTING_UP_DOWN);
  tft.drawRect(8,149,48,18,COLOR_SETTING_BORDER);
  tft.drawBitmap(68,150,symbole2[1],32,16,COLOR_SETTING_UP_DOWN);
  tft.drawRect(67,149,34,18,COLOR_SETTING_BORDER);
  tft.drawBitmap(101,150,symbole2[1],32,16,COLOR_SETTING_UP_DOWN);
  tft.drawRect(100,149,34,18,COLOR_SETTING_BORDER);
  updateAlarmTime();
}
// update alarm time displayed on config page
void updateAlarmTime(){
  tft.setTextSize(1);
  uint8_t mask;
  uint16_t xPos;
  // Display the weekdays
  for (uint8_t i=1; i<8; i++) {
    mask = 1 << (i%7);
    if ((alarmConfig.alarmday & mask) == 0) {
      tft.setTextColor(COLOR_SETTING_ALARM_TEXT);
      tft.fillRect(9+(i-1)*DAY_INT,54,27,20,COLOR_SETTING_BG);
    }
    else {
      tft.setTextColor(COLOR_SETTING_BG);
      tft.fillRect(9+(i-1)*DAY_INT,54,27,20,COLOR_SETTING_ALARM_TEXT);
    }
    xPos = 10+(i-1)*DAY_INT;
    // fine tuning of position for weekday
    switch (i) {
      case 2: // Di
        xPos = xPos+3;
        break;
      case 3: // Mi
        xPos = xPos+2;
        break;
      case 5: // Fr
        xPos = xPos+3;
        break;
      case 6: // Sa
        xPos = xPos+1;
        break;
      case 7: // So
        xPos = xPos+1;
        break;
    }
    tft.setCursor(xPos, 70);
    tft.print(days_short[i%7]);
  }
  // display the alarmtime
  tft.fillRect(0,115,140,30,COLOR_SETTING_BG);
  tft.setTextColor(COLOR_SETTING_ALARM_TEXT, COLOR_SETTING_BG);
  tft.setCursor(10, 140);
  char buf[45];
  sprintf(buf,"%02i : %02i\n",alarmConfig.h,alarmConfig.m);
  tft.setTextSize(2);
  tft.print(buf);
  // reset text size
  tft.setTextSize(1);
}

// enable/disable a day for the alarm
void toggleAlarmDay(uint16_t xPos){
  uint8_t mask = 0B00000000;
  if (xPos < 8+DAY_INT) mask = 0B00000010;                             // Mo
  if ((xPos > 8+DAY_INT)   && (xPos < 8+2*DAY_INT)) mask = 0B00000100; // Di
  if ((xPos > 8+2*DAY_INT) && (xPos < 8+3*DAY_INT)) mask = 0B00001000; // Mi
  if ((xPos > 8+3*DAY_INT) && (xPos < 8+4*DAY_INT)) mask = 0B00010000; // Do
  if ((xPos > 8+4*DAY_INT) && (xPos < 8+5*DAY_INT)) mask = 0B00100000; // Fr
  if ((xPos > 8+5*DAY_INT) && (xPos < 8+6*DAY_INT)) mask = 0B01000000; // Sa
  if ((xPos > 8+6*DAY_INT) && (xPos < 8+7*DAY_INT)) mask = 0B00000001; // So
  alarmConfig.alarmday = alarmConfig.alarmday ^ mask;
}
void incrementAlarmTime(uint16_t xPos){
  uint8_t min1, min2;
  min1 = alarmConfig.m / 10;
  min2 = alarmConfig.m % 10;
  if (xPos < 64) alarmConfig.h = (alarmConfig.h+1) % 24;
  if ((xPos > 69) && (xPos < 99)) {
    min1 = (min1+1) % 6;
    alarmConfig.m = min1 * 10 + min2;
  }
  if ((xPos > 105) && (xPos < 145)) {
    min2 = (min2+1) % 10;
    alarmConfig.m = min1 * 10 + min2;
  }
}
void decrementAlarmTime(uint16_t xPos){
  uint8_t min1, min2;
  min1 = alarmConfig.m / 10;
  min2 = alarmConfig.m % 10;
  if (xPos < 64) {
    if (alarmConfig.h == 0) alarmConfig.h = 24;
    alarmConfig.h = alarmConfig.h-1;
  }
  if ((xPos > 69) && (xPos < 99)) {
    if (min1 == 0) min1 = 5;
    else min1 = min1-1;
    alarmConfig.m = min1 * 10 + min2;
  }
  if ((xPos > 105) && (xPos < 145)) {
    if (min2 == 0) min2 = 9;
    else min2 = min2-1;
    alarmConfig.m = min1 * 10 + min2;
  }
}

// safe the changed alarm time and show 'OK'
void safeAlarmTime() {
  start_conf -= 9000;
  tft.fillRect(140,108,190,48,COLOR_SETTING_BG);
  tft.drawRect(175,111,65,35,COLOR_SETTING_BORDER);
  tft.setTextColor(COLOR_SETTING_ALARM_TEXT);
  tft.setCursor(180, 140);
  tft.setTextSize(2);
  tft.print("OK");
  tft.setTextSize(1);
  uint16_t alarmtime;
  alarmtime = alarmConfig.h * 60 + alarmConfig.m;
  if (configView == 1) {
    alarm1 = alarmtime;
    alarmday1 = alarmConfig.alarmday;
    pref.putUInt("alarm1",alarm1);
    pref.putUShort("alarmday1",alarmday1);
  } else {
    if (configView == 2) {
      alarm2 = alarmtime;
      alarmday2 = alarmConfig.alarmday;
      pref.putUInt("alarm2",alarm2);
      pref.putUShort("alarmday2",alarmday2);
    } else {
      if (configView == 3) {
        alarm3 = alarmtime;
        alarmday3 = alarmConfig.alarmday;
        pref.putUInt("alarm3",alarm3);
        pref.putUShort("alarmday3",alarmday3);
      }
    }
  }
  if (alarmday < 8) findNextAlarm(); // if alarm is enabled update next alarm
}
