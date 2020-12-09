/*UNIVERDIDAD TECNICA DEL NORTE
*FICA-CITEL
*SISTEMAS EMBEBIDOS
*DEBER#5
*MOTORES
*LISSETH ALBAN
*/

#include <Servo.h>
  
int val = 0; //comunicacion serial
  
Servo servo;

int motor = 13;
int boton1 = 2; // prender
int boton2 = 3; // apagar

void setup() {
pinMode(motor, OUTPUT);
pinMode(boton1, INPUT);
pinMode(boton2, INPUT);

Serial.begin(9600); //Iniciamos el serial
servo.attach(3); //Conectamos al pin digital 13
}
void loop(){
if (digitalRead(boton1) == HIGH) {
digitalWrite(motor, HIGH);
}
else if (digitalRead(boton2) == HIGH) {
digitalWrite(motor, LOW);
}
if(Serial.available() > 0) //revisa si hay alguna entrada por serial
   {
      val = Serial.parseInt(); //guardar  como entero
      if(val >= 0 and val <= 180)
      {
         servo.write(val); //va a la posición entrada
      }
   }
   delay(500);
}
