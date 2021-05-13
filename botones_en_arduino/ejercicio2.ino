//coded by cefuve.com
int count = 0;
int temporizador = 200;
int temp_count = 0;
int delayms = 3;

int lectura_anterior = 1;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
}

void loop() {
  int lectura = digitalRead(2);

  if(lectura == 0){
    temporizador--;
    if(temporizador == 0){
      count++;
      temp_count++;
      temporizador = 200;
      Serial.println(count);
    }

    if(temp_count > 10) delayms = 1;
    delay(delayms);
  }

  if(lectura_anterior == 1 && lectura == 0){
    count++;
    temporizador = 200;
    Serial.println(count);
  }

  if(lectura_anterior == 0 && lectura == 1){
    delayms = 3;
    temp_count = 0;
  }

  lectura_anterior = lectura;
}
