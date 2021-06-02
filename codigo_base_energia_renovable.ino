#include <Servo.h>
int estadoPulsador = 0;  //LOW es 0 y HIGH es 1
//variable para guardar el estado anterior del pulsador
int estadoAnterior = 0;  //LOW es 0 y HIGH es 1
int pulsador=13;
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
const int led = 2;

void setup()
{
  Serial.begin(9600);
  //Definiendo pines de entrada y salida
  pinMode(photA, INPUT);
  pinMode(photB, INPUT);
  pinMode(led, OUTPUT);
  pinMode(A2,INPUT);
  pinMode(pulsador,OUTPUT);
  pinMode(A2,INPUT); 
  // Iniciamos el servo para que empiece a trabajar con el pin asignado
  servoMotor.attach(8);
}
void loop()
{ 
   //controlando suministro del panel a la bateria para no sobrecargarla
  int valorPot=analogRead(A2);
  Serial.println(valorPot);
  delay(100);
  while(valorPot>950){
  	digitalWrite(2,LOW);
    valorPot=analogRead(A2);
    estadoPulsador=0;
     digitalWrite(pulsador,estadoPulsador);   
  }
  while(valorPot<950){
  	digitalWrite(2,HIGH);
    valorPot=analogRead(A2);
    estadoPulsador=1;
     digitalWrite(pulsador,estadoPulsador);
  } 
  
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
