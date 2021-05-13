//coded by cefuve.com
int count = 0;
int lectura_anterior = 1;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
}

void loop() {
  int lectura = digitalRead(2);

  if(lectura == 0){
    count++;
    delay(1);
  }

  if(lectura_anterior == 0 && lectura == 1){
    if(count > 2500){
      Serial.println("Pulsación larga");
    }else{
      Serial.println("Pulsación corta");
    }
    count = 0;
  }

  lectura_anterior = lectura;
}
