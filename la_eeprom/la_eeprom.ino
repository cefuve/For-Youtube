//code by cefuve.com
#include <EEPROM.h>

int proceso = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  proceso = EEPROM.read(0);
}

void loop() {
  if(proceso == 0){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    EEPROM.update(0, 0);
  }
  else if(proceso == 1){
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    EEPROM.update(0, 1);
  }
  else if(proceso == 2){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    EEPROM.update(0, 2);
  }
  else if(proceso == 3){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    EEPROM.update(0, 3);
  }
  else if(proceso == 4){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    EEPROM.update(0, 4);
  }else{
    EEPROM.update(0, 0);
    proceso = 0;
  }

  proceso++;
  if(proceso == 5) proceso = 0;
  delay(1000);
}


/*
  EEPROM.read(address);
  EEPROM.write(address, value);
  EEPROM.update(address, value);

  EEPROM.get(address, data);
  EEPROM.put(address, data);

  EEPROM[address];
  EEPROM.length();
 */
