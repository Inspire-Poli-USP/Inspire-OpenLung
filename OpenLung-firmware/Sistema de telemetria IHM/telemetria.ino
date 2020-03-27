//Programa: Telemetria para respirador mecânico;
//Autor: Fellipy Kühne
//Última atualização : 27/03/2020
//
//    O sistema é simples e está em fase de testes, precisa implementar mais algumas entradas. 
//    Além disso precisamos validar os valores de comparação junto a norma que se aplica aos equipamentos médicos.
//
//


#include <LiquidCrystal.h>
LiquidCrystal lcd(32, 31, 45, 44, 43, 42);                                                         

int buzzer = 50;                                                     //Saída buzzer
int select = 53;                                                     // Botão de entra
int volMed=999;                                                      // Variavel de teste para volume de ar medido pelo sensor do equipamento
int offsetVol=5.55;                                                  // Offset de tolerancia de ar
float tIns;
float rInv;
int vol;
int count = 0;

float inspira() {
  digitalWrite(buzzer, LOW);
  int pot = analogRead(A0);                                          // Le o potenciometro 1 - referente a velocidade
  float valorPot = map(pot, 0, 1023, 0.0, 70.0);                      // Converte o sinal lido pelo potenciometro (0~1023), para o range (vMin~vMax)
  float potToIns = valorPot / 10.0;
  return potToIns;
}


float invies() {
  digitalWrite(buzzer, LOW);
  int pot = analogRead(A0);                                          // Le o potenciometro 1 - referente a velocidade
  float valorPot = map(pot, 0, 1023, 0.0, 70.0);                      // Converte o sinal lido pelo potenciometro (0~1023), para o range (vMin~vMax)
  float potToInv = valorPot / 10.0;
  return potToInv;
}

int volume() {
  digitalWrite(buzzer, LOW);
  int pot = analogRead(A0);                                          // Le o potenciometro 1 - referente a velocidade
  int vol = map(pot, 0, 1023, 0.0, 1000);                      // Converte o sinal lido pelo potenciometro (0~1023), para o range (vMin~vMax)
  return vol;
}

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(buzzer, OUTPUT);
  pinMode(select, INPUT);
}

void loop()

{
  if (count == 0) {
    lcd.setCursor(0, 0);
    lcd.print("CITI-OpenLung:");
    lcd.setCursor(0, 1);
    lcd.print("Press Enter");
    if (digitalRead(select) == HIGH) count ++;
  }


  else if (count == 2) {
    //delay(200);
    lcd.setCursor(0, 0);
    lcd.print("T inspiracao:");
    tIns = inspira();
    lcd.setCursor(0, 1);
    lcd.print(tIns);
    if (digitalRead(select) == HIGH) count ++;
  }

  else if (count == 3) {
    lcd.setCursor(0, 0);
    lcd.clear();
    lcd.print("Invies:");
    rInv = invies();
    lcd.setCursor(0, 1);
    lcd.print(rInv);
    if (digitalRead(select) == HIGH) count++;
  }

  else if (count == 1) {
    lcd.setCursor(0, 0);
    lcd.clear();
    lcd.print("Volume:");
    vol = volume();
    lcd.setCursor(0, 1);
    lcd.print(vol);
    if (digitalRead(select) == HIGH) count++;
  }


  else if (count == 4) {

    digitalWrite(buzzer, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ml:");                       //volume calculado pelo medico
    lcd.setCursor(3, 0);
    lcd.print(vol);

    lcd.setCursor(9, 0);
    lcd.print("ml:");                       //volume medido por ciclo
    lcd.setCursor(12, 0);
    //lcd.print(analogRead(volMed));       //entrada volume sensor              
    lcd.print(volMed);                     //entrada volume sensor
    
    lcd.setCursor(0, 1);
    lcd.print("ri:");                     //relação invies
    lcd.setCursor(3, 1);
    lcd.print("1:");                       //entrada relação invies medico
    lcd.setCursor(5, 1);
    lcd.print(rInv);                       //entrada relação invies medico

    lcd.setCursor(10, 1);
    lcd.print("t:");                     //tempo de inspiração
    lcd.setCursor(12, 1);
    lcd.print(tIns);                     //entrada tempo de inspiração medico


    /////////////////////condição de erro volumetrico/////////////////////
    
    if (vol > (vol+offsetVol)) {
      lcd.clear();
      digitalWrite(buzzer, HIGH);
      lcd.setCursor(0, 0);
      lcd.print("OPEN AMBU");
      lcd.setCursor(0, 1);
      lcd.print("Volume Alto!");

    }
    if (vol < (vol-offsetVol)) {
      lcd.clear();
      digitalWrite(buzzer, HIGH);
      lcd.setCursor(0, 0);
      lcd.print("OPEN AMBU");
      lcd.setCursor(0, 1);
      lcd.print("Volume Baixo!");

    }
    
    
    if (digitalRead(select) == HIGH) count = 1;
  }
  delay (500);
}
