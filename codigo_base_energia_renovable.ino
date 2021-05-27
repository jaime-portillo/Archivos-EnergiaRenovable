#include <Servo.h>
//variable para manipular el servo
Servo servoMotor;
//asignando A0 a constante photA(fotorresistencia A)
#define photA A0
//asignando A0 a constante photB(fotorresistencia B)
#define photB A1
//Variable para activar el servo por los valores de las ldr
const int activarServo = 200;

void setup()
{
  Serial.begin(9600);
  //Definiendo pines de entrada y salida
  pinMode(photA, INPUT);
  pinMode(photB, INPUT);
  // Iniciamos el servo para que empiece a trabajar con el pin asignado
  servoMotor.attach(8);
}
void loop()
{ 
  //captando valor de PhotA
  int valueA = analogRead(photA);
  //Captando valor de PhotB
  int valueB = analogRead(photB);
  //viendo en serial monitor valor de photA
  Serial.println(valueA);
  //viendo en serial monitor valor de photB
  //Serial.println(valueB);
  //condicional para activar servo motor
  if (valueA>activarServo && valueB>activarServo){
    servoMotor.write(90);
    delay(100);
  }
  //condicional para llevar el servo motor a la posicion original
  if(
    
  }
}
