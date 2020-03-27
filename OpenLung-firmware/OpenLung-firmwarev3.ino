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


int avancoMax = 800;
int avancoMin = 40;
int vMin = 10;
int vMax = 800;
int avancoAbs = 0;                                                    //variavel que armazena o avanço atual do motor
int offset = 30;                                                      //offset da chave fim de curso
int x = 0;
int aceleracao_motor = 5;
int sentido_horario = 0;
int sentido_antihorario = 0; 
                                                    
// Definicao pino ENABLE
int pino_enable = 10;

// Definicao pinos STEP e DIR
AccelStepper motor(1, 7, 4 );

// Definição entrada chave fim de curso
int key = 12;


int velocidade() {
  //Serial.println("Entrou velocidade");
  int pot1 = analogRead(A1);                                          // Le o potenciometro 1 - referente a velocidade
  int velocidade_filtro = 0;
  int valorPot1 = map(pot1, 0, 1023, vMin, vMax);                      // Converte o sinal lido pelo potenciometro (0~1023), para o range (vMin~vMax)
  //velocidade_filtro=(0.1*valorPot1)+((1-0.1)*velocidade_filtro);       //filtro de leitura do potenciometro (em teste)
  return valorPot1;
}

int avanco() {
  //Serial.println("Entrou avanco");
  int pot2 = analogRead(A0);                                          // Le o potenciometro 1 - referente a velocidade
  int avanco_filtro = 0;
  int valorPot2 = map(pot2, 0, 1023, 40, avancoMax);                  // Converte o sinal lido pelo potenciometro (0~1023), para o range (0~avancoMaximo)

  //avanco_filtro=(0.1*valorPot2)+((1-0.1)*avanco_filtro);            //filtro de leitura do potenciometro (em teste)
  return valorPot2;
}

void setup()
{

  Serial.begin(9600);
  pinMode(pino_enable, OUTPUT);                              //Define a variável pino_enable(10) como saída
  pinMode(key, INPUT);                                      //Define a variável key(12) como entrada
  // Configuracoes iniciais motor de passo
  motor.setMaxSpeed(1000);
  motor.setAcceleration(aceleracao_motor);
  //motor1.run();
  Serial.println("Digite 1, 2 ou 3 e clique em ENVIAR...");
}

void loop()


{
  Serial.println(x);
  int velocidade_motor = 0;
  velocidade_motor = velocidade();
  //digitalRead(key);

  //if (digitalRead(key)==HIGH)
  //if (digitalRead(key)==LOW)
  switch (x) {

    case (0):
      while (digitalRead(key) == HIGH) {

        motor.moveTo(-avancoMax);                               // deve recuar até atingir a chave fim de curso
        motor.setSpeed(-velocidade_motor);
        motor.runSpeed();//add
        Serial.println("Recuando");

        if (digitalRead(key) == LOW) {
          x = 1;
          sentido_horario = 1;
          sentido_antihorario = 0;
          Serial.println("stop");
          motor.setCurrentPosition(0);

        }

      }
    case (1):
      if (sentido_horario == 1)
      {
        int avanco_motor = avanco();                                                      //mudança de posição da função que define o avanço,
        avancoAbs = avanco_motor;                                                        //para contabilizar somente no avanço e não durante o recuo
        motor.moveTo(avancoAbs);
        motor.setSpeed(velocidade_motor);
        motor.runSpeed();//add
        Serial.println("avanço");

        if (motor.currentPosition() >= avancoAbs) {
          delay(100);

          sentido_horario = 0;
          sentido_antihorario = 1;
          //motor.setCurrentPosition(0);
          Serial.println("finalizou avanço");

        }
      }

      // Move o motor no sentido anti-horario
      if (sentido_antihorario == 1)
      {
        motor.moveTo(offset);                                                             // não deve ir a 0 para nao colidir com a chave fim de curso verificar valor ideal
        motor.setSpeed(-velocidade_motor);
        motor.runSpeed();


        if (motor.currentPosition() <= offset) {
          delay (100);
          sentido_horario = 1;
          sentido_antihorario = 0;
        }
      }
      // Comando para acionar o motor no sentido especificado
  }
  motor.runSpeed();


}

