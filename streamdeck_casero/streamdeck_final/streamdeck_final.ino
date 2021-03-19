//https://www.sparkfun.com/tutorials/337
//https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide#installing-windows
#include "Keyboard.h"
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'3','2','1'},
  {'6','5','4'},
  {'9','8','7'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  Keyboard.begin();
}
  
void loop(){
  char key = keypad.getKey();

  if (key){
    switch(key){
      case '2': Keyboard.press(KEY_F13);
                delay(50);
                break;
      case '3': Keyboard.press(KEY_F14);
                delay(50);
                break;
      case '4': Keyboard.press('w');
                delay(50);
                break;
      case '5': Keyboard.press(KEY_LEFT_CTRL);
                Keyboard.press(KEY_LEFT_SHIFT);
                Keyboard.press('k');
                delay(50);
                break;
      case '6': Keyboard.press('q');
                delay(50);
                break;
      case '7': Keyboard.press(KEY_F15);
                delay(50);
                break;
      case '8': Keyboard.press(KEY_F16);
                delay(50);
                break;
      case '9': Keyboard.press(KEY_F17);
                delay(50);
                break;
      case '*': Keyboard.press(KEY_F18);
                delay(50);
                break;
      case '0': Keyboard.press(KEY_F19);
                delay(50);
                break;
      case '#': Keyboard.press(KEY_F20);
                delay(50);
                break;
      default:  Serial.println("Tecla no asignada...");
    }
    
    Keyboard.releaseAll();
    Serial.println(key);
  }
}
