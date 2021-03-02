/*
Coded by cefuve 2021
Webpage: https://www.cefuve.com
Youtube: https://www.youtube.com/user/cefuve
Instagram: https://www.instagram.com/cefuve_electronics/
Facebook: https://www.facebook.com/cefuve.electronics
*/

#define pinLED 2
#define pinBtn 6
#define pinLEDred A5
int count = 0;
int count2 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pinLED, OUTPUT);
  pinMode(pinLEDred, OUTPUT);
  pinMode(pinBtn, INPUT_PULLUP);
}

void loop() {
  count++;
  count2++;
  delay(10);

  lecturaBtn();
  
  if(count == 100){
    ledAzul();
  }

  if(count2 == 50){
    ledRojo();
  }
}



void lecturaBtn(){
  int lectura = digitalRead(pinBtn);
  Serial.println(lectura);
}

void ledAzul(){
  int estadoLED = digitalRead(pinLED);
  digitalWrite(pinLED, !estadoLED);
  count = 0;
}

void ledRojo(){
  int estadoLED = digitalRead(pinLEDred);
  digitalWrite(pinLEDred, !estadoLED);
  count2 = 0;
}
