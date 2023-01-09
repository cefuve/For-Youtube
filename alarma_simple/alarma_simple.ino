//code by cefuve.com

#define reed_switch 2
#define alarm_btn   3
#define led_armed   8
#define led_alert   10

int state_btn_old;
int state_reed_old;
bool isArmed = false;
bool isWait = false;
unsigned long tiempo_actual = 0;

void setup() {
  Serial.begin(9600);
  pinMode(reed_switch, INPUT);
  pinMode(alarm_btn, INPUT_PULLUP);
  pinMode(led_armed, OUTPUT);
  pinMode(led_alert, OUTPUT);
  state_btn_old = digitalRead(alarm_btn);
  state_reed_old = digitalRead(reed_switch);
}

void loop() {
  int state_reed = digitalRead(reed_switch);
  int state_btn = digitalRead(alarm_btn);

  if(state_btn_old == HIGH && state_btn == LOW){
    isArmed = !isArmed;
    digitalWrite(led_armed, isArmed);
    digitalWrite(led_alert, LOW);
    delay(10);
  }

  if(isArmed == true){
    if(state_reed_old == LOW && state_reed == HIGH){
      tiempo_actual = millis();
      isWait = true;
    }
  }

//if(millis() >= tiempo_actual + 3000   Lógica que genera error
  if(millis() - tiempo_actual > 3000 && isWait){
    if(isArmed) digitalWrite(led_alert, HIGH);
    isWait = false;
  }

  state_btn_old = state_btn;
  state_reed_old = state_reed;
  delay(20);
}
