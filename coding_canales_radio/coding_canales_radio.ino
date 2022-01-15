//code by cefuve.com

#define fm_btn  2
#define ch1_btn 3
#define ch2_btn 4
#define ch3_btn 5

int state_fm_old;
int fm = 0;

String fm1[] = {"80.9", "90.1", "94.1"};
String fm2[] = {"99.9", "100.7", "104.3"};

int fm_1 = 0;
int fm_2 = 0; 

void setup() {
  Serial.begin(9600);
  pinMode(fm_btn, INPUT_PULLUP);
  pinMode(ch1_btn, INPUT_PULLUP);
  pinMode(ch2_btn, INPUT_PULLUP);
  pinMode(ch3_btn, INPUT_PULLUP);
  state_fm_old = digitalRead(fm_btn);
}

void loop() {
  int state_fm = digitalRead(fm_btn);
  int state_ch1 = digitalRead(ch1_btn);
  int state_ch2 = digitalRead(ch2_btn);
  int state_ch3 = digitalRead(ch3_btn);

  if(state_fm_old == HIGH && state_fm == LOW){
    fm++;
    if(fm == 2) fm = 0;
  }

  if(fm == 0){
    if(state_ch1 == LOW) fm_1 = 0;
    if(state_ch2 == LOW) fm_1 = 1;
    if(state_ch3 == LOW) fm_1 = 2;
    Serial.print("FM1 / ");
    if(fm_1 == 0) Serial.print("CH1 ");
    if(fm_1 == 1) Serial.print("CH2 ");
    if(fm_1 == 2) Serial.print("CH3 ");
    Serial.println( fm1[fm_1] );
  }
  
  if(fm == 1){
    if(state_ch1 == LOW) fm_2 = 0;
    if(state_ch2 == LOW) fm_2 = 1;
    if(state_ch3 == LOW) fm_2 = 2;
    Serial.print("FM2 / ");
    if(fm_2 == 0) Serial.print("CH4 ");
    if(fm_2 == 1) Serial.print("CH5 ");
    if(fm_2 == 2) Serial.print("CH6 ");
    Serial.println( fm2[fm_2] );
  }
  
  state_fm_old = state_fm;
  delay(5);
}
