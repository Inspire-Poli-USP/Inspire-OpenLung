/* Programa para Balança com o HX711
  Blog Eletrogate - https://blog.eletrogate.com/balanca-digital-com-arduino-aprenda-a-usar-a-celula-de-carga
  Arduino UNO - IDE 1.8.5 - Modulo HX711 - celulas de Carga 50 Kg
  Gustavo Murta   17/abril/2019
  Biblioteca https://github.com/bogde/HX711
  Baseado em https://www.hackster.io/MOHAN_CHANDALURU/hx711-load-cell-amplifier-interface-with-arduino-fa47f3
*/
 
#include "HX711.h"                    // Biblioteca HX711 
 
#define DOUT  A0                      // HX711 DATA OUT = pino A0 do Arduino 
#define CLK  A1                       // HX711 SCK IN = pino A1 do Arduino 
 
HX711 balanca;                        // define instancia balança HX711
 
float calibration_factor = 42130;     // fator de calibração aferido na Calibraçao 
int buzzer = 7;
void setup()
{
  Serial.begin(9600);
  balanca.begin(DOUT, CLK);                          // inicializa a balança
  Serial.println("Balança com HX711 - celula de carga 50 Kg");            
  Serial.println("Pressione t para Tara");           // imprime no monitor serial
  balanca.set_scale(calibration_factor);             // ajusta fator de calibração
  balanca.tare();  // zera a Balança
  pinMode(buzzer, OUTPUT);
}
 
void loop()
{
  digitalWrite(buzzer,LOW);
  Serial.print("Peso: ");                            // imprime no monitor serial
  Serial.print(balanca.get_units(), 3);              // imprime peso na balança com 3 casas decimais 
  float unidade=balanca.get_units();
  Serial.println(" kg");                             // imprime no monitor serial 
  delay(500) ;                                       // atraso de 0,5 segundos 

  if (unidade>3.6){
    Serial.println("PRESSAO PULMONAR ALTA!!");
    digitalWrite(buzzer,HIGH);
    delay(7000);
  }
  
  if (Serial.available())                            // se a serial estiver disponivel
  {
    char temp = Serial.read();                       // le carcter da serial 
    if (temp == 't' || temp == 'T')                  // se pressionar t ou T
    {
      balanca.tare();                                // zera a balança
      Serial.println(" Balança zerada");             // imprime no monitor serial
    }
  }
}
