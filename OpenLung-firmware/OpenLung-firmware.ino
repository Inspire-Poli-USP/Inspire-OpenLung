/*
 * Poli Inspira
 * emoretto at usp.br
 * v4
*/

#include <avr/wdt.h> //Biblioteca que cão de guarda (WDT)
#include <EEPROM.h>
#include "AccelStepper.h"
#include <TimerOne.h>

#define Z_ENABLE_PIN        2
#define Z_DIR_PIN           3
#define Z_STEP_PIN          4
#define Z_MIN_PIN          12
#define POSITION_PIN       11
#define LED_STATUS_PIN     LED_BUILTIN

#define PRESSURE_PIN A0

int stepsPerRevFactor = 2;

AccelStepper stepper(AccelStepper::DRIVER, Z_STEP_PIN, Z_DIR_PIN);

bool start = false;
float pressure = 0.0;

//Connection stuff
const byte numChars = 32;
char receivedChars[numChars];
boolean newData = false;


//speed in steps per second
//acceleration in steps per second

int currentSpeed = 1500;
int currentAcc = 10000;
int currentCourse = 350;
float currentRate = 2; //stepper driver rate

/* Variáveis para controle do LED de statu */
uint32_t proximoPiscaLED = 0;
uint32_t intervaloPiscaLED = 300;

void setup() {
  /* Configura portas como saída */
  pinMode(Z_STEP_PIN, OUTPUT);
  pinMode(Z_DIR_PIN, OUTPUT);
  pinMode(Z_ENABLE_PIN, OUTPUT);
  pinMode(PRESSURE_PIN, INPUT);
  pinMode(POSITION_PIN, OUTPUT);
  pinMode(LED_STATUS_PIN, OUTPUT );
  
  /* Inicia portas de saída */
  digitalWrite(LED_STATUS_PIN, HIGH ); //LED ligado até final de setup()
  digitalWrite( Z_ENABLE_PIN, HIGH);

  // start your engines
  stepper.setMaxSpeed(currentSpeed);
  stepper.setAcceleration(currentAcc);
  stepper.moveTo(currentCourse * stepsPerRevFactor);

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

  uint32_t contadorReinicio = 0;  
  EEPROM.get(1,contadorReinicio);
  if ( EEPROM.read(0) == 1 ) {
    Serial.println("Reinicio detectado");
    /* Desmarca flag */
    EEPROM.write(0,(uint8_t)0);
    
    /* Incrementa contador de reinicios */
    contadorReinicio++;
    EEPROM.put(1,contadorReinicio);
  }
  
  
  /* Ativa WDT */ 
  wdt_enable(WDTO_8S);
  
  /* LED deligado indicando final de setup() */
  digitalWrite(LED_STATUS_PIN, LOW ); 
  Serial.print(F("Contador de reinicios: "));
  Serial.println(contadorReinicio);
}

void loop() {
  /* Reinicia contador do WDT */
  wdt_reset();
  
  //start = true;
  recvWithStartEndMarkers();

  //Incoming info
  if (newData) {

    String input(receivedChars);

    if (input.startsWith("v")) { //velocidade
      currentSpeed = input.substring(1).toInt();
      stepper.setMaxSpeed(currentSpeed * stepsPerRevFactor);
    } else  if (input.startsWith("c")) {     //curso
      currentCourse = input.substring(1).toInt();
      currentCourse = currentCourse * stepsPerRevFactor;
      stepper.moveTo(currentCourse);
    } else  if (input.startsWith("a")) { //aceleracao
      currentAcc = input.substring(1).toInt();
      //stepper.setAcceleration(currentAcc*stepsPerRevFactor);
    } else if (input.startsWith("m")) { //mover (comando manual)
      start = false;
      int value = input.substring(1).toInt();
      stepper.runToNewPosition(value * stepsPerRevFactor);
      stepper.setCurrentPosition(0);
    } else if (input.startsWith("r")) { // Inpiracao/Expiracao rate
      start = false;
      currentRate  = input.substring(1).toFloat();
    } else if (input == "i") { //start
      
      start = true;
      
      /* Inicia pisca do LED de status */
      proximoPiscaLED = millis();

      /* Marca como em operaçao */
      EEPROM.write(0, (uint8_t)1);
  
      stepper.setCurrentPosition(0);
      //.moveTo(-stepper.currentPosition());
      
    } else if (input == "f") {  //fim
      start = false;

      /* Finaliza pisca do LED de status */
      proximoPiscaLED = 0;
      digitalWrite(LED_STATUS_PIN, LOW );

      /* desmarca como em operaçao */
      EEPROM.write(0, (uint8_t)0);
    }

    //clear input
    newData = false;
  }


  if (start) {

    if ((proximoPiscaLED > 0 )&&(millis()>proximoPiscaLED)){
      digitalWrite(LED_STATUS_PIN, !digitalRead(LED_STATUS_PIN) );  
      proximoPiscaLED += intervaloPiscaLED;
    } 

    if (millis() % 100 == 0) {
      Serial.println(map(stepper.currentPosition(),0,1460,0,255));
      analogWrite(POSITION_PIN, (int) map(stepper.currentPosition(), 0, 1460, 0, 255));
    }


    // If at the end of travel go to the other end
    if (stepper.currentPosition() == 0) {
      Serial.println("0");

      stepper.setMaxSpeed(currentSpeed);
      //stepper.setAcceleration(currentAcc);
      stepper.moveTo(currentCourse);

    } else if (stepper.currentPosition() == currentCourse) { // || pressure >= 200){
      Serial.println("1");
      stepper.setMaxSpeed(currentSpeed / currentRate);
      //stepper.setAcceleration(currentAcc/currentRate);
      stepper.moveTo(0);
    }

    stepper.run();

  } else if (stepper.currentPosition() != 0) {
    Serial.println("m0");
    stepper.moveTo(0);
    stepper.run();
  } 

  /* if(millis() %10 == 0){
      pressure = analogRead(PRESSURE_PIN);

      pressure = pressure - 225.28;
       //Serial.println(pressure);
     Serial.println(map(pressure,0,1024,0,37.037));

    }*/

}

void doStep() {
  if (start)
    stepper.run();
}

void recvWithStartEndMarkers() {
  static boolean recvInProgress = false;
  static byte ndx = 0;
  char startMarker = '<';
  char endMarker = '>';
  char rc;

  // if (Serial.available() > 0) {
  while (Serial.available() > 0 && newData == false) {
    rc = Serial.read();

    if (recvInProgress == true) {
      if (rc != endMarker) {
        receivedChars[ndx] = rc;
        ndx++;
        if (ndx >= numChars) {
          ndx = numChars - 1;
        }
      }
      else {
        receivedChars[ndx] = '\0'; // terminate the string
        recvInProgress = false;
        ndx = 0;
        newData = true;
      }
    }

    else if (rc == startMarker) {
      recvInProgress = true;
    }
  }
}
