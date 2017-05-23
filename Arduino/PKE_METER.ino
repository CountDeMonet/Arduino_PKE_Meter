#include <Servo.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

Servo SERVO1;

int LEDNum = 0; // current LED that is lit
unsigned long previousMillis;   // will store last time LED was updated

const int LED1 = 12;
const int LED2 = 11;
const int LED3 = 10;
const int LED4 = 9;
const int LED5 = 8;
const int LED6 = 7;
const int LED7 = 6;
const int BUZZER = 5;
const int BUTTON1 = 3;
const int BUTTON2 = 4;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);

  digitalWrite(BUTTON1, HIGH);
  digitalWrite(BUTTON2, HIGH);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(1000);

  // Clear the buffer.
  display.clearDisplay();

  SERVO1.attach(13);
  SERVO1.write(90);
}

void loop() {
  int convertedVal = 0;
  if (digitalRead(BUTTON1) == false) { 
     convertedVal = 40;  
  }else if(digitalRead(BUTTON2) == false) { 
    convertedVal = 90; 
  }
  
  // do the led stuff
  LEDLoop(convertedVal);

  // do the servo stuff
  ServoLoop(convertedVal);

  // delay in between reads for stability
  delay(1);
}

int prevB = 0;
void drawDisplay(int level, int bar) {
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(29, 5);
  display.print("GHOSTBUSTERS");

  int b1 = random(prevB, bar);
  int b2 = random(prevB, bar);
  int b3 = random(prevB, bar);
  int b4 = random(prevB, bar);
  int b5 = random(prevB/2, bar/2);
  int b6 = random(prevB/2, bar/2);
  prevB = bar;

  display.fillRect(2, display.height() - (5 + b1), 5, b1, WHITE);
  display.fillRect(10, display.height() - (5 + b2), 5, b2, WHITE);
  display.fillRect(18, display.height() - (5 + b5), 5, b5, WHITE);
  display.fillRect(display.width() - 23, display.height() - (5 + b6), 5, b6, WHITE);
  display.fillRect(display.width() - 15, display.height() - (5 + b4), 5, b4, WHITE);
  display.fillRect(display.width() - 7, display.height() - (5 + b3), 5, b3, WHITE);
  
  display.drawCircle(display.width() / 2, display.height() / 2 + 7, level, WHITE);
  
  display.display();
}

void clearLoop() {
  display.clearDisplay();
  prevB = 0;
}

void LEDLoop(int convertedVal) {
  int ledSpeed = map(convertedVal, 0, 100, 500, 20);

  // check to see if it's time to change the state of the LED
  unsigned long currentMillis = millis();

  if ((currentMillis - previousMillis >= ledSpeed))
  {
    previousMillis = millis();

    if ( LEDNum == 0 ) {
      TriggerBuzzer();
      clearLoop();
      digitalWrite(LED3, true);
      LEDNum = 1;
      drawDisplay(21, 5);
    } else if ( LEDNum == 1 ) {
      TriggerBuzzer();
      digitalWrite(LED3, false);
      digitalWrite(LED1, true);
      LEDNum = 2;
      drawDisplay(18, 20);
    } else if ( LEDNum == 2 ) {
      TriggerBuzzer();
      digitalWrite(LED1, false);
      digitalWrite(LED6, true);
      LEDNum = 3;
      drawDisplay(15, 30);
    } else if ( LEDNum == 3 ) {
      TriggerBuzzer();
      digitalWrite(LED6, false);
      digitalWrite(LED4, true);
      LEDNum = 4;
      drawDisplay(12, 45);
    } else if ( LEDNum == 4 ) {
      TriggerBuzzer();
      digitalWrite(LED4, false);
      digitalWrite(LED7, true);
      LEDNum = 5;
      drawDisplay(9, 50);
    } else if ( LEDNum == 5 ) {
      TriggerBuzzer();
      digitalWrite(LED7, false);
      digitalWrite(LED5, true);
      LEDNum = 6;
      drawDisplay(6, 55);
    } else if ( LEDNum == 6 ) {
      TriggerBuzzer();
      digitalWrite(LED5, false);
      digitalWrite(LED2, true);
      LEDNum = 7;
      drawDisplay(3, 65);
    }else if ( LEDNum == 7 ) {
      TriggerBuzzer();
      clearLoop();
      digitalWrite(LED2, false);
      digitalWrite(LED3, true);
      LEDNum = 1;
      drawDisplay(21, 5);
    }
  }
}

void TriggerBuzzer() {
  tone(BUZZER, 2000); // Send 2KHz sound signal...
  delay(20);        // ...for 20 msec
  noTone(BUZZER);
}

void ServoLoop(int convertedVal) {
  int servoVal = map(convertedVal, 0, 100, 110, 40);
  SERVO1.write(servoVal);
}

