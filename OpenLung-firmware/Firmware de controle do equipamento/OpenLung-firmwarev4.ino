// Programa : Sistema de controle AMBU
// Autor : Fellipy Kühne
// Última atualização : 24/03/2020
//
//   O programa em questão deve permitir que um usuário consiga controlar um motor de passo, sua velocidade e o avanço,
//   para isso ele utiliza duas entradas variáveis (potenciometros), e converte sua leitura dentro de um range estipulado.
//
//
//   Obs.:Ainda será necessário implementar uma chave fim de curso, que irá limitar a posição minima na máquina. Assim o avanço será calculado a partir do acionamento
//   da chave para cada paciente.
//   Obs.: O programa em questão ainda está em fase de validaçao.
//
//
///////Hardware utilizado:
//
// Fonte 24v 5A
// Arduino Uno
// 2x Potenciometros 1k
// 1x driver de motor de passo (a4988)
// 1x Capacitor eletrolitico 100uf x 63v (filtro de entrada de tensão do driver)
// 1x Chave fim de curso
// 1x motor de passo modelo Nema17 ou Nema23 compatíveis com o driver
// 1x Resistor 10k

#include <AccelStepper.h>

long avancoMax = 800;
long avancoMin = 40;
long offset = 30;                                                      //offset da chave fim de curso
float relacaoInspiracaoExpiracao = 2.0;
float vMin = 10.0;
float vMax = 800.0;
float aceleracao_motor = 5.0;
float velocidade_motor = 0.0;
uint8_t sentido = true; //horário

// Definicao pino ENABLE
int pino_enable = 10;
//int pino_enable = A2; //Usando RAMPS

// Definicao pinos STEP e DIR
AccelStepper motor(AccelStepper::DRIVER, 7, 4 );
//AccelStepper motor(1, A6, A7 ); //Usando RAMPS

// Definição entrada chave fim de curso
int key = 12;

float velocidade() {
  //Serial.println("Entrou velocidade");
  int pot1 = analogRead(A1);                                          // Le o potenciometro 1 - referente a velocidade
  int velocidade_filtro = 0;
  float valorPot1 = (float)map(pot1, 0, 1023, (int)vMin, (int)vMax);                      // Converte o sinal lido pelo potenciometro (0~1023), para o range (vMin~vMax)
  //velocidade_filtro=(0.1*valorPot1)+((1-0.1)*velocidade_filtro);       //filtro de leitura do potenciometro (em teste)
  return valorPot1;
}

long avanco() {
  //Serial.println("Entrou avanco");
  int pot2 = analogRead(A0);                                          // Le o potenciometro 1 - referente a velocidade
  int avanco_filtro = 0;
  long valorPot2 = (long)map(pot2, 0, 1023, 40L, avancoMax);                  // Converte o sinal lido pelo potenciometro (0~1023), para o range (0~avancoMaximo)
  //avanco_filtro=(0.1*valorPot2)+((1-0.1)*avanco_filtro);            //filtro de leitura do potenciometro (em teste)
  return valorPot2;
}

void setup() {
  /* Inicia comunicação serial (debug pelo serial monitor)*/
  Serial.begin(9600);
  while (!Serial);

  /* Inicia pinos */
  pinMode(pino_enable, OUTPUT);  //Define a variável pino_enable(10) como saída
  pinMode(key, INPUT);           //Define a variável key(12) como entrada
  pinMode( A0, INPUT_PULLUP );
  pinMode( A1, INPUT_PULLUP );

  /* Configuração inicial do motor */
  motor.setMaxSpeed(vMax);
  motor.setAcceleration(aceleracao_motor);

  /* Posiciona motor em home */
  if (digitalRead(key) == HIGH) {
    Serial.println(F("Go home"));
    motor.moveTo(-avancoMax);
    motor.setSpeed(vMax / 2.0);
    unsigned long tempoMaximoRetorno = millis() + 10000UL;
    while ((digitalRead(key) == HIGH)&& (millis() < tempoMaximoRetorno)) {
      motor.runSpeed();
    }   
  }
  
  /* Alarme de erro no go home */
  if (digitalRead(key) == HIGH){
    Serial.println( F( "Motor não chegou em home"));      
  } else {
    Serial.println(F("home"));    
  }  
  motor.setCurrentPosition(0);  
}

unsigned long calculoFrequencia = 0;

void loop() {
  velocidade_motor = velocidade();  
  if (sentido) {
    Serial.print( "\tFrequencia: ");
    Serial.println( 60000UL / calculoFrequencia );
    calculoFrequencia = 0;
    Serial.print("Inspira: ");
    long avancoAbs = avanco();
    motor.moveTo(avancoAbs);
    motor.setSpeed(velocidade_motor);      
  } else { // Move o motor no sentido anti-horario
    Serial.print("\tExpira:  ");
    motor.moveTo(offset);                                                           
    motor.setSpeed(-velocidade_motor / relacaoInspiracaoExpiracao);
  }
  unsigned long tempo = millis();
  while (motor.distanceToGo() != 0 ) {
    motor.runSpeed(); 
  }
  delay(100);
  sentido = !sentido;
  tempo = millis() - tempo;
  Serial.print(tempo );
  calculoFrequencia += tempo;
}
