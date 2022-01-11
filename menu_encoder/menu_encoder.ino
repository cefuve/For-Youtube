//code by cefuve.com

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define clk 2
#define dt  3
#define btn 4
#define led 10

LiquidCrystal_I2C lcd(0x27, 16, 2);

String opciones[] = {"LED ON", "LED OFF", "1 Hz", "Monostable"};
int max_opciones = sizeof(opciones)/sizeof(opciones[0]);
int state_clk_old;
int state_btn_old;
int count = 0;
bool hz_1 = false;
bool mono = false;
unsigned long tiempo_actual = 0;
unsigned long tiempo_actual2 = 0;

void setup() {
  Serial.begin(9600);
  Serial.println(max_opciones);
  lcd.begin();
  lcd.backlight();
  pinMode(led, OUTPUT);
  pinMode(clk, INPUT);
  pinMode(dt, INPUT);
  pinMode(btn, INPUT_PULLUP);
  state_clk_old = digitalRead(clk);
  state_btn_old = digitalRead(btn);
  mostrar_menu();
}

void loop() {
  int state_btn = digitalRead(btn);

  encoder();
  if(state_btn_old == HIGH && state_btn == LOW){
    run_option();
  }

  if(millis() >= tiempo_actual + 500){
    tiempo_actual = millis();
    if(hz_1) digitalWrite(led, !digitalRead(led));
  }

  if(millis() >= tiempo_actual2 + 6000){
    if(mono) digitalWrite(led, LOW);
  }

  state_btn_old = state_btn;
}


void run_option(){
  if(count == 0){
    digitalWrite(led, HIGH);
  }
  if(count == 1){
    digitalWrite(led, LOW);
  }
  if(count == 2){
    hz_1 = true;
  }else{
    hz_1 = false;
  }
  if(count == 3){
    digitalWrite(led, HIGH);
    tiempo_actual2 = millis();
    mono = true;
  }else{
    mono = false;
  }
}


void encoder(){
  int state_clk = digitalRead(clk);
  int state_dt = digitalRead(dt);
  
  if(state_clk_old == HIGH && state_clk == LOW){
    if(state_dt == LOW){
      count--;
    }else{
      count++;
    }
    if(count < 0) count = max_opciones - 1;
    if(count > max_opciones-1) count = 0;
    
    mostrar_menu();
  }

  delay(5);
  state_clk_old = state_clk;
}

void mostrar_menu(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Menu:");
  lcd.setCursor(0,1);
  lcd.print(opciones[count]);
}
