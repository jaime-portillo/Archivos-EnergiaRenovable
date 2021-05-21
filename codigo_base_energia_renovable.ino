//asignando A0 a constante photA(fotorresistencia A)
#define photA A0
//asignando A0 a constante photB(fotorresistencia B)
#define photB A1
void setup()
{
  Serial.begin(9600);
  //Definiendo pines de entrada y salida
  pinMode(photA, INPUT);
  pinMode(photB, INPUT);
}

void loop()
{
  //captando valor de PhotA
  int valueA = analogRead(photA);
  //Captando valor de PhotB
  int valueB = analogRead(photB);
  //Serial.println(valueA);
  //Serial.println(valueB);
  delay(100);
  //condicional para activar actuadores
  if (){
  	
  }else{
  	
  }
}