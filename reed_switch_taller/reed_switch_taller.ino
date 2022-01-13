//code by cefuve.com

#define reed_switch 2

void setup() {
  Serial.begin(9600);
  pinMode(reed_switch, INPUT);
}

void loop() {
  int state_reed = digitalRead(reed_switch);

  if(state_reed == LOW){
    Serial.println("puerta cerrada");
  }else{
    Serial.println("puerta ABIERTA!");
  }
}
