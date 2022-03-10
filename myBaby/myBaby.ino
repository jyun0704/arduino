int touchPin = 3;
int tiltPin = 4;
int buzzerPin = 5;

int touchStatus = 0;
int tiltStatus = 0;

#include "U8glib.h"
U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE);

void draw_generalState() {
  u8g.drawBox(27, 26, 7, 7);
  u8g.drawBox(92, 26, 7, 7);
}

void draw_touch() {
  u8g.drawBox(23, 23, 6, 3);
  u8g.drawBox(32, 23, 6, 3);
  u8g.drawBox(20, 26, 21, 6);
  u8g.drawBox(23, 32, 15, 3);
  u8g.drawBox(26, 35, 9, 3);
  u8g.drawBox(29, 38, 3, 3);

  u8g.drawBox(89, 23, 6, 3);
  u8g.drawBox(98, 23, 6, 3);
  u8g.drawBox(86, 26, 21, 6);
  u8g.drawBox(89, 32, 15, 3);
  u8g.drawBox(92, 35, 9, 3);
  u8g.drawBox(95, 38, 3, 3);
}

void draw_cry() {
  u8g.drawBox(25, 29, 4, 4) ;
  u8g.drawBox(29, 31, 4, 4) ;
  u8g.drawBox(33, 29 , 4, 4);

  u8g.drawBox(91, 29, 4, 4);
  u8g.drawBox(95, 31, 4, 4) ;
  u8g.drawBox(99, 29, 4, 4) ;

  u8g.drawBox(22, 36, 2, 2) ;
  u8g.drawBox(21, 41, 2, 2);
  u8g.drawBox(20, 45, 2, 2) ;
  u8g.drawBox(21, 50, 2, 2) ;
  u8g.drawBox(19, 55, 2, 2) ;
  u8g.drawBox(15, 57, 2, 2) ;
  u8g.drawBox(24, 57, 2, 2) ;

  u8g.drawBox(103, 36, 2, 2);
  u8g.drawBox(102, 41, 2, 2) ;
  u8g.drawBox(104, 46, 2, 2);
  u8g.drawBox(104, 50, 2, 2);
  u8g.drawBox(107, 55, 2, 2) ;
  u8g.drawBox(102, 57, 2, 2);

  u8g.drawBox(7, 60, 2, 2) ;
  u8g.drawBox(11, 61, 2, 2);
  u8g.drawBox(15, 61, 2, 2);
  u8g.drawBox(20, 61, 2, 2) ;
  u8g.drawBox(25, 61, 2, 2);
  u8g.drawBox(29, 60, 2, 2) ;
  u8g.drawBox(33, 61, 2, 2);
  u8g.drawBox(38, 60, 2, 2) ;
  u8g.drawBox(43, 60, 2, 2) ;
  u8g.drawBox(47, 61, 2, 2);
  u8g.drawBox(52, 61, 2, 2) ;
  u8g.drawBox(57, 60, 2, 2) ;
  u8g.drawBox(61, 61, 2, 2);
  u8g.drawBox(66, 60, 2, 2) ;
  u8g.drawBox(70, 61, 2, 2);
  u8g.drawBox(75, 60, 2, 2) ;
  u8g.drawBox(79, 60, 2, 2) ;
  u8g.drawBox(85, 61, 2, 2);
  u8g.drawBox(91, 60, 2, 2) ;
  u8g.drawBox(95, 61, 2, 2) ;
  u8g.drawBox(100, 60, 2, 2);
  u8g.drawBox(104, 60, 2, 2);
  u8g.drawBox(108, 60, 2, 2);
  u8g.drawBox(112, 61, 2, 2);
  u8g.drawBox(116, 61, 2, 2);
}

void chearOLED() {
  u8g.firstPage();
  do {
  } while (u8g.nextPage());
}

void setup() {
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, OUTPUT);

  u8g.setColorIndex(1);

  u8g.firstPage();
  do {
    draw_generalState();
  } while (u8g.nextPage());
  delay(1000);
}

void loop() {
  touchStatus = digitalRead(touchPin);
  tiltStatus = digitalRead(tiltPin);

  if (touchStatus == HIGH) {

    u8g.firstPage();
    do {
      draw_touch();
    } while (u8g.nextPage());
    delay(1000);
  }
  else {

    u8g.firstPage();
    do {
      draw_generalState();
    } while (u8g.nextPage());
    delay(1000);
  }

  if (tiltStatus == HIGH) {
    tone(buzzerPin, 1000, 1000);
    delay(2000);


    u8g.firstPage();
    do {
      draw_cry();
      delay(200);
    } while (u8g.nextPage());
    delay(1000);
  }
  else {
  }
}
