#include <Servo.h>
//variable para manipular el servo
Servo servoMotor;
//asignando A0 a constante photA(fotorresistencia A)
#define photA A0
//asignando A0 a constante photB(fotorresistencia B)
#define photB A1
//Variable para activar el servo por los valores de las ldr
const int activarServo = 200;
//variable para regresar el servo motor a la posicion inicial
const bool servoInicio = false;
//Asignando led rojo a pin 2, estos led se usaran para el 
//control de la carga de la bateria, rojo = necesita cargar
//y verde= carga completa  (esto para no sobrecargar la bateria)
const int redLed = 2;
//Asignando led verde a pin 3
const int greenLed = 3;

void setup()
{
  Serial.begin(9600);
  //Definiendo pines de entrada y salida
  pinMode(photA, INPUT);
  pinMode(photB, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  // Iniciamos el servo para que empiece a trabajar con el pin asignado
  servoMotor.attach(8);
  
}
void loop()
{ 
  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, HIGH);
  
  //captando valor de PhotA
  int valueA = analogRead(photA);
  //Captando valor de PhotB
  int valueB = analogRead(photB);
  //viendo en serial monitor valor de photA
  //Serial.println(valueA);
  //viendo en serial monitor valor de photB
  //Serial.println(valueB);
  //condicional para activar servo motor
  if (valueA>activarServo && valueB>activarServo){
    servoMotor.write(90);
    delay(100);
  }
  //condicional para llevar el servo motor a la posicion original
  if(valueA<activarServo && valueB<activarServo && servoInicio==true){
     servoMotor.write(0);
    delay(100);
  }
}
