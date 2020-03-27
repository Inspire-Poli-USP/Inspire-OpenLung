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




#include <AccelStepper.h>


int avancoMax=800;       
int avancoMin=40;
int vMin = 10;
int vMax = 800;
int Passos=200; 
int Voltas=8;
int escalaAvanco = 10;
int aceleracao_motor = 5;
int sentido_horario = 0;
int sentido_antihorario = 0;                                          
int numero = 0;                                                       //variavel que armazena a entrada do teclado, para os primeiros testes de bancada 

// Definicao pino ENABLE
int pino_enable = 10;

// Definicao pinos STEP e DIR
AccelStepper motor(1, 7, 4 );


int velocidade() {
  //Serial.println("Entrou velocidade");
  int pot1 = analogRead(A1);                                          // Le o potenciometro 1 - referente a velocidade
  int velocidade_filtro=0;
  int valorPot1 = map(pot1, 0, 1023, vMin, vMax);                      // Converte o sinal lido pelo potenciometro (0~1023), para o range (vMin~vMax)
  //velocidade_filtro=(0.1*valorPot1)+((1-0.1)*velocidade_filtro);       //filtro de leitura do potenciometro (em teste)
  return valorPot1;
}

int avanco() {
 //Serial.println("Entrou avanco");
  int pot2 = analogRead(A0);                                          // Le o potenciometro 1 - referente a velocidade
  int avanco_filtro=0;
  int valorPot2 = map(pot2, 0, 1023, 40, avancoMax);                  // Converte o sinal lido pelo potenciometro (0~1023), para o range (0~avancoMaximo)
           
  //avanco_filtro=(0.1*valorPot2)+((1-0.1)*avanco_filtro);            //filtro de leitura do potenciometro (em teste)
  return valorPot2;
}

void setup()
{
  
  Serial.begin(9600);
  pinMode(pino_enable, OUTPUT);
  // Configuracoes iniciais motor de passo
  motor.setMaxSpeed(1000);
  motor.setAcceleration(aceleracao_motor);
  //motor1.run();
  Serial.println("Digite 1, 2 ou 3 e clique em ENVIAR...");
}

void loop()


{
  
  int velocidade_motor = 0;
  velocidade_motor = velocidade();
  int avanco_motor = avanco();
  //Serial.println(pos);
  //Serial.println(avanco_motor);
  //Serial.println(customDelayMapped);
            // Aguarda os caracteres no serial monitor
  if (Serial.available() > 0)
  {
    numero = Serial.read();
    {
      if (numero == '1')
      {

        Serial.println("Numero 1 recebido - Girando motor sentido horario.\n");
        digitalWrite(pino_enable, LOW);
        sentido_horario = 1;
        sentido_antihorario = 0;
      }

      if (numero == '2')
      {
        Serial.println("Numero 2 recebido - Girando motor sentido anti-horario.");
        digitalWrite(pino_enable, LOW);
        sentido_horario = 0;
        sentido_antihorario = 1;

      }
      if (numero == '3')
      {
        Serial.println("Numero 3 recebido - Parando motor...");
        sentido_horario = 0;
        sentido_antihorario = 0;
        motor.moveTo(0);
        digitalWrite(pino_enable, HIGH);
      }
    }
  }

  // Move o motor no sentido horario
  if (sentido_horario == 1)
  {
    motor.moveTo(avanco_motor);
    motor.setSpeed(velocidade_motor);
    motor.runSpeed();//add
    

    if (motor.currentPosition() >= avanco_motor) {
      //delay(500);
      
      sentido_horario = 0;
      sentido_antihorario = 1;
      motor.setCurrentPosition(0);
      
    }
  }
  // Move o motor no sentido anti-horario
  if (sentido_antihorario == 1)
  {
    motor.moveTo(-avanco_motor);
    motor.setSpeed(-velocidade_motor);
    motor.runSpeed();//add
    
    //Serial.println(motor1.currentPosition());
    if (motor.currentPosition() <= -avanco_motor) {
      //delay (500);
      sentido_horario = 1;
      sentido_antihorario = 0;
      motor.setCurrentPosition(0);
    }
  }
  // Comando para acionar o motor no sentido especificado
  // motor1.run();
  motor.runSpeed();//add
  //delay (500);
 
}




