/*
   Poli Inspira
   emoretto at usp.br
   v4
*/

/* Biblioteca de terceiros */
#include <AccelStepper.h>
#include <TimerOne.h>

/* Bibliotecas do Arduino */
#include <avr/wdt.h> //Biblioteca que cão de guarda (WDT)
#include <EEPROM.h>

/* Bibliotecas e cabeçalhos locais */
#include "debug.h"
#include "tiposDefs.h"

/* Definição dos pinos/porta do Arduino */
#define Z_ENABLE_PIN        2
#define Z_DIR_PIN           3
#define Z_STEP_PIN          4
#define Z_MIN_PIN          12
#define POSITION_PIN       11
#define PRESSURE_PIN       A0

/* Definições da comunicação serial */
const char marcaDeInicio = '<';
const char marcaDeFinal = '>';

/* Objeto para controle do motor de passo */
AccelStepper stepper(AccelStepper::DRIVER, Z_STEP_PIN, Z_DIR_PIN);

/* Variável da operação em andamento */
Operacao_t operacao;

bool start = false;
float pressure = 0.0;

//Connection stuff
const byte numChars = 32;
char receivedChars[numChars];
boolean newData = false;

/* Variáveis para controle do LED de statu */
uint32_t proximoPiscaLED = 0;
uint32_t intervaloPiscaLED = 300;

/* Variaveis de atualização do envio de dados */
uint32_t proximaAtualizacaoOperacao = 0;
uint32_t intervaloAtualizaOperacao = 100;

void setup() {
  
  /* Configura portas como saída */
  pinMode(Z_STEP_PIN, OUTPUT);
  pinMode(Z_DIR_PIN, OUTPUT);
  pinMode(Z_ENABLE_PIN, OUTPUT);
  pinMode(PRESSURE_PIN, INPUT);
  pinMode(POSITION_PIN, OUTPUT);

  /* Inicia portas de saída */
  digitalWrite( Z_ENABLE_PIN, HIGH);

  //Timer1.initialize(1000);
  //Timer1.attachInterrupt(doStep); // blinkLED to run every 0.0015 seconds

  // houston
  Serial.begin(115200);
  while (!Serial);
  Serial.println();
  Serial.println("Started!");
  Serial.print( F( "Compilado em: " ) );
  Serial.print( __DATE__);
  Serial.print( F( " ") );
  Serial.println(__TIME__);

  /* Ler dados da EEPROM */
  //EEPROM.put( 0, operacao ); //Grava valores padrão da operação

  if ( EEPROM.read(0) < 5 ) { //Lê apenas se não for a primeira vez
    EEPROM.get( 0, operacao );
  } else {
    EEPROM.put( 0, operacao );
  }

  /* Verifica se houve reinicio */
  if (operacao.estado == 1 ) {
    Serial.println("*** Reinicio detectado");
    /* Desmarca flag */
    operacao.estado = 0;

    /* Incrementa contador de reinicios */
    operacao.contadorReinicio++;

    /* Grava informações na EEPOM */
    EEPROM.put(0, operacao );
  }

  /* Mostra configurações lidas da EEPROM */
  Serial.print(F("Contador de reinicios: "));
  Serial.println(operacao.contadorReinicio);
  mostraConfigurecoes();

  // start your engines
  stepper.setMaxSpeed(operacao.currentSpeed);
  stepper.setAcceleration(operacao.currentAcc);
  stepper.moveTo(operacao.currentCourse * operacao.stepsPerRevFactor);

  /* Ativa WDT */
  wdt_enable(WDTO_8S);  
}

void loop() {

  /* Reinicia contador do WDT */
  wdt_reset();

  /* Recebe comandos pela porta serial */
  if ( Serial.available() > 0 ) {
    recebeComando();
  }
  
    /* Executa operação */
  if ( operacao.estado == estadoOperando ) {
    executaOperacao();
  }

#if defined(debbug_on)
  /*
  if (millis() % 10 == 0) {
    pressure = (float)analogRead(PRESSURE_PIN);
    pressure = pressure - 225.28;
    Serial.println(pressure);
    Serial.println(map(pressure, 0, 1024, 0, 37.037));
  }
  */
#endif

}

void doStep() {
  if (start)
    stepper.run();
}

void recebeComando() {
  static byte ndx = 0;
  static char receivedChars[numChars];

  /* Recebe os bytes pela porta serial */
  char rc = '*';
  while ((Serial.available() > 0) && ( ndx < numChars ) && (rc != marcaDeFinal)) {
    while ((Serial.available() > 0) && ( ndx < numChars ) && (rc != marcaDeFinal)) {
      rc = Serial.read();
      if ((rc != marcaDeFinal)&&(rc != marcaDeInicio)&&(rc != '\n')&&(rc != '\r')){
        receivedChars[ndx++] = rc;
      }      
    }
    delay(2);
  }
  if ( rc == marcaDeFinal ) {
    receivedChars[ndx] = '\0';
    trataComando(String(receivedChars));
    ndx = 0;
  }
}

void trataComando( String input ) {
  if (input.startsWith("v")) { //velocidade
    operacao.currentSpeed = input.substring(1).toFloat();
    stepper.setMaxSpeed(operacao.currentSpeed * (float)operacao.stepsPerRevFactor);
    DBG_PRINT(F("currentSpeed: ")); DBG_PRINTLN(operacao.currentSpeed);
  } else if (input.startsWith("c")) { //curso
    operacao.currentCourse = (long)input.substring(1).toInt() * operacao.stepsPerRevFactor;
    stepper.moveTo(operacao.currentCourse);
    DBG_PRINT(F("currentCourse: ")); DBG_PRINTLN(operacao.currentCourse);
  } else if (input.startsWith("a")) { //aceleracao
    operacao.currentAcc = input.substring(1).toFloat();
    //stepper.setAcceleration(currentAcc*stepsPerRevFactor);
    DBG_PRINT(F("currentAcc: ")); DBG_PRINTLN(operacao.currentAcc);
  } else if (input.startsWith("m")) { //mover (comando manual)
    paraOperacao();
    DBG_PRINT(F("Manual, "));
    long value = (long)input.substring(1).toInt();
    stepper.runToNewPosition(value * operacao.stepsPerRevFactor);
    stepper.setCurrentPosition(0);
    DBG_PRINT(F("value: ")); DBG_PRINTLN(value);
  } if (input.startsWith("r")) { // Inpiracao/Expiracao rate
    paraOperacao();
    operacao.currentRate  = input.substring(1).toFloat();
    DBG_PRINT(F("currentRate: ")); DBG_PRINTLN(operacao.currentRate);
  } if (input == "i") { //inicio
    iniciaOperacao();
  } if (input == "f") { //fim
    finalizaOperacao();
  }
  
  /* Salva novas configurações na EEPROM */
  EEPROM.put( 0, operacao );
}

void executaOperacao() {

  if ( millis() > proximaAtualizacaoOperacao ) {
    proximaAtualizacaoOperacao = millis() + intervaloAtualizaOperacao;
    analogWrite(POSITION_PIN, (int) map(stepper.currentPosition(), 0, 1460, 0, 255));    
    DBG_PRINT( "currentPosition: "); DBG_PRINTLN(stepper.currentPosition());    
  }

  // If at the end of travel go to the other end
  if (stepper.currentPosition() == 0L) {
    stepper.setMaxSpeed(operacao.currentSpeed);
    //stepper.setAcceleration(currentAcc);
    stepper.moveTo(operacao.currentCourse);
  } else if (stepper.currentPosition() == operacao.currentCourse) { // || pressure >= 200){
    stepper.setMaxSpeed(operacao.currentSpeed / operacao.currentRate);
    //stepper.setAcceleration(currentAcc/currentRate);
    stepper.moveTo(0L);
  }
  stepper.run();
}

void finalizaOperacao() {
  /* Falta implemtanção */
  paraOperacao();
}

void paraOperacao() {
  /* Verifica se já está prado */
  if ( operacao.estado == estadoParado ) {
    DBG_PRINTLN(F("*** Já está parado"));
    return;
  }

  operacao.estado = estadoParado;
  DBG_PRINTLN(F("Operação parada"));
}

void iniciaOperacao() {
  /* Verifica se já está em operação */
  if ( operacao.estado == estadoOperando ) {
    DBG_PRINTLN(F("*** Já está em operação"));
    return;
  }
  operacao.estado = estadoOperando;
  
  /* Inicia LED piscando */
  proximoPiscaLED = millis();
    
  /* Melhorar implementaçao, falta fim de curso para definir posição 0 */
  if (stepper.currentPosition() != 0) {
    stepper.moveTo(0L);
    stepper.run();
  }
  stepper.setCurrentPosition(0);
  //.moveTo(-stepper.currentPosition());
  
  DBG_PRINTLN(F("Operação iniciada"));
  mostraConfigurecoes();  
}

void mostraConfigurecoes() {
  DBG_PRINT(F("currentSpeed: ")); DBG_PRINTLN(operacao.currentSpeed);
  DBG_PRINT(F("currentCourse: ")); DBG_PRINTLN(operacao.currentCourse);
  DBG_PRINT(F("currentAcc: ")); DBG_PRINTLN(operacao.currentAcc);
  DBG_PRINT(F("currentRate: ")); DBG_PRINTLN(operacao.currentRate);
}
