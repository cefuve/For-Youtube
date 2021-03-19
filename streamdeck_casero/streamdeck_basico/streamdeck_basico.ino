/*
https://www.sparkfun.com/tutorials/337
https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide#installing-windows

Código de ejemplo que se ejecuta solo una vez
al energizar la placa Pro Micro, el cual abrirá
el bloc de notas de windows y escribirá un texto.
Si tu computador demora mucho en abrir el bloc de
notas, tendrás que agregar tiempos de espera entre
acciones.
*/

#include "Keyboard.h"

void setup(){
  Keyboard.begin();
  delay(500); //Esperar que se inicie el teclado

 
  //Abrir ventana "ejecutar"
  Keyboard.press(KEY_LEFT_GUI);
  delay(50);
  Keyboard.press('r');
  delay(50);
  Keyboard.releaseAll();


  //Escribir notepad
  Keyboard.print("notepad");
  delay(50);


  //Presionar la tecla Enter
  //para abir el bloc de notas
  Keyboard.press(KEY_RETURN);
  delay(50);
  Keyboard.releaseAll();


  //Escribir algún mensaje
  delay(1000); //darle tiempo a que se abra el bloc de notas
  Keyboard.print("by cefuve.com");
}
  
void loop(){
}
