//code by cefuve.com

#define clk 3
#define dt  2

int state_clk_old;
int state_dt_old;
int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(clk, INPUT);
  pinMode(dt, INPUT);
  state_clk_old = digitalRead(clk);
  state_dt_old = digitalRead(dt);
}

void loop() {
  int state_clk = digitalRead(clk);
  int state_dt = digitalRead(dt);
  
  if(state_clk_old == HIGH && state_clk == LOW){
    if(state_dt == LOW){
      count--;
      //Serial.println("antihorario");
    }else{
      count++;
      //Serial.println("horario");
    }
    Serial.println(count);
  }

  delay(10);
  state_clk_old = state_clk;
}

/*
* circuito necesita antirebote

>> antihorario
clk dt  dec
 0  0 -  0
 0  1 -  1
 1  1 -  3
 1  0 -  2

>> horario
clk dt  dec
 0  0 -  0
 1  0 -  2
 1  1 -  3
 0  1 -  1

clk en flanco de bajada
si dt = HIGH - horario
si dt = LOW - antihorario

clk en flanco de subida
si dt = HIGH - antihorario
si dt = LOW - horario
  
*/
