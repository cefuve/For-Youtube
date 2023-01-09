//coded by cefuve.com
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C //0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define pin_min 2
#define pin_hour 3
int hour = 23;
int minute = 59;
int second = 50;

long tiempo_actual = 0;
bool modo_edicion = false;
bool wait = false;
bool blink_time = false;

int old_min = 1;
int old_hour = 1;
int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pin_min, INPUT);
  pinMode(pin_hour, INPUT);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.display();
  delay(100);
  display.clearDisplay();
  display.setTextSize(4);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  //Modo edición
  int lectura_min = digitalRead(pin_min);
  int lectura_hour = digitalRead(pin_hour);

  if(lectura_min == 0 && lectura_hour == 0){
    count++;
    wait = true;
    delay(1);
  }else{
    if(wait == true){
      wait = false;
      delay(400);
      return;
    }
  }

  if(lectura_min == 1 && lectura_hour == 1){
    if(count > 1500){
      modo_edicion = !modo_edicion;
      second = 0;
      old_min = 1;
      old_hour = 1;
    }
    count = 0;
  }

  if(lectura_min == 1 && old_min == 0 && modo_edicion){
    minute++;
    if(minute == 60) minute = 0;
    printTime();
  }
  
  if(lectura_hour == 1 && old_hour == 0 && modo_edicion){
    hour++;
    if(hour == 24) hour = 0;
    printTime();
  }

  
  old_min = lectura_min;
  old_hour = lectura_hour;
  if(modo_edicion) return;


  //Reloj digital
  
//if(millis() >= tiempo_actual + 1000)   Lógica que genera error
  if(millis() - tiempo_actual > 1000){
    tiempo_actual = millis();
    blink_time = !blink_time;
    second++;

    if(second == 60){
      second = 0;
      minute++;
    }
    if(minute == 60){
      minute = 0;
      hour++;
    }
    if(hour == 24){
      hour = 0;
    }

    printTime();
  }
}

void printTime() {
  display.clearDisplay();
  display.setCursor(4, 5);

  if(hour < 10) display.print("0");
  display.print(hour);
  if(blink_time) display.print(":");
  if(!blink_time) display.print(" ");
  if(minute < 10) display.print("0");
  display.print(minute);
  
  display.display();
  
  Serial.print(hour);
  Serial.print(":");
  Serial.print(minute);
  Serial.print(":");
  Serial.println(second);
}
