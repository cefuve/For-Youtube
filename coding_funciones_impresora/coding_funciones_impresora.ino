//coded by cefuve.com
//Mayo 2021
#define   gLED      A0
#define   yLED      A1
#define   btn_on    2
#define   btn_page  3
#define   btn_x     4

bool printState = false;
bool printing = false;

int old_on_read = 1;
int old_page_read = 1;
int old_x_read = 1;

int count = 0;
int time_count = 0;

void setup() {
    Serial.begin(9600);
    pinMode(gLED, OUTPUT);
    pinMode(yLED, OUTPUT);
    pinMode(btn_on, INPUT);
    pinMode(btn_page, INPUT);
    pinMode(btn_x, INPUT);
}

void loop() {
    int on_read = digitalRead(btn_on);
    int page_read = digitalRead(btn_page);
    int x_read = digitalRead(btn_x);


    //Reconoce cuando suelto el botón
    if (on_read == 1 && old_on_read == 0) {
        if (count > 0) {
            if (count == 3){                                  //presioné 3 veces avanzar
                Serial.println("Alineación de cabezales");
                printing = true;
            }else if( count == 10){                           //presioné 10 veces avanzar
                Serial.println("Hoja de diagnóstico");
                printing = true;
            }
            count = 0;
        }else{
            printState = !printState;
            printing = false;
        }

        digitalWrite(gLED, printState);
    }


    //Reconoce impresora encendida
    if (printState) {
      
        if (page_read == 0) {
            digitalWrite(yLED, HIGH);
        }else{
            digitalWrite(yLED, LOW);
        }

        if (page_read == 0 && old_page_read == 1) {
            if (on_read == 0) count++;
            Serial.println(count);
        }

        if (printing) {
            //Parpadear LED green
            time_count++;
            if (time_count >= 50){
                int gLED_read = digitalRead(gLED);
                digitalWrite(gLED, !gLED_read);
                time_count = 0;
            }
        }

        if (x_read == 0 && old_x_read == 1 && printing == true){
            printing = false;
            Serial.println("Impresión cancelada!");
            count = 0;
            time_count = 0;
            digitalWrite(gLED, HIGH);
        }
        
    }
    
    

    old_on_read = on_read;
    old_page_read = page_read;
    old_x_read = x_read;
    delay(10);
}
