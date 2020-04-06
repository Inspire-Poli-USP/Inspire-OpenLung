// Poli Inspira

// emoretto at usp.br
// v4

#include "AccelStepper.h"
#include <TimerOne.h>

#define Z_ENABLE_PIN  2
#define Z_DIR_PIN     3
#define Z_STEP_PIN    4
#define Z_MIN_PIN     12
#define POSITION_PIN  11
#define PRESSURE_PIN  A0

int stepsPerRevFactor = 2;

AccelStepper stepper(AccelStepper::DRIVER,Z_STEP_PIN, Z_DIR_PIN);

bool start = false;
float pressure = 0.0;
long t0=0;

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

void setup() {  
   pinMode(Z_STEP_PIN  , OUTPUT);
   pinMode(Z_DIR_PIN    , OUTPUT);
   pinMode(Z_ENABLE_PIN    , OUTPUT);
   pinMode(PRESSURE_PIN, INPUT);
   pinMode(POSITION_PIN, OUTPUT);

   digitalWrite( Z_ENABLE_PIN, HIGH);

  // start your engines
  stepper.setMaxSpeed(currentSpeed);
  stepper.setAcceleration(currentAcc);
  stepper.moveTo(currentCourse*stepsPerRevFactor);

  //Timer1.initialize(1000);
  //Timer1.attachInterrupt(doStep); // blinkLED to run every 0.0015 seconds

  // houston
  Serial.begin(115200);
  Serial.println("Started!");
}

void loop() {
  //start = true;
  recvWithStartEndMarkers();

   //Incoming info
  if (newData) {     
    String input(receivedChars);

    //velocidade
    if (input.startsWith("v")) {          
      currentSpeed = input.substring(1).toInt();          
      stepper.setMaxSpeed(currentSpeed*stepsPerRevFactor);          
    }

    //curso
    if (input.startsWith("c")) {          
      currentCourse = input.substring(1).toInt(); 
      currentCourse = currentCourse*stepsPerRevFactor;        
      stepper.moveTo(currentCourse);
    }

    //aceleracao
    if (input.startsWith("a")) {          
      currentAcc = input.substring(1).toInt();          
      //stepper.setAcceleration(currentAcc*stepsPerRevFactor);
    }

    //mover (comando manual)
    if (input.startsWith("m")) {          
      start = false;
      int value = input.substring(1).toInt();
      stepper.runToNewPosition(value*stepsPerRevFactor);
      stepper.setCurrentPosition(0);
    }

    // Inpiracao/Expiracao rate
    if (input.startsWith("r")) {          
      start = false;
      currentRate  = input.substring(1).toFloat();
    }
  
    //inicio
    if (input == "i") {
      stepper.setCurrentPosition(0);
      //.moveTo(-stepper.currentPosition());
      start = true;
    }

    //fim
    if (input == "f")
      start = false;

    //clear input
    newData = false;
  }  
  
  if (start) { 
    if (millis() % 100) {
        //Serial.println(map(stepper.currentPosition(),0,1460,0,255));
        analogWrite(POSITION_PIN, (int) map(stepper.currentPosition(),0,1460,0,255));
    }

    // If at the end of travel go to the other end
    if (stepper.currentPosition() == 0) {
      stepper.setMaxSpeed(currentSpeed);
      //stepper.setAcceleration(currentAcc);
      stepper.moveTo(currentCourse);
    }
    else if (stepper.currentPosition() == currentCourse) { // || pressure >= 200) {
        stepper.setMaxSpeed(currentSpeed/currentRate);
        //stepper.setAcceleration(currentAcc/currentRate);    
        stepper.moveTo(0);
    }
    
    stepper.run();
  }
  else if (stepper.currentPosition() != 0) {
        stepper.moveTo(0);
        stepper.run();
  }

  /* if (millis() %10 == 0) {
      pressure = analogRead(PRESSURE_PIN);
      pressure = pressure - 225.28;
        //Serial.println(pressure);
      Serial.println(map(pressure,0,1024,0,37.037));
      
    }*/     
}//--------------------------------------------------

void doStep() { 
  if (start) stepper.run();
}

void recvWithStartEndMarkers() {
  static boolean recvInProgress = false;
  static byte ndx = 0;
  char startMarker = '<';
  char endMarker = '>';
  char rc;

// if (Serial.available() > 0) {
  while(Serial.available() > 0 && newData == false) {
    rc = Serial.read();

    if (recvInProgress == true) {
      if (rc != endMarker) {
        receivedChars[ndx] = rc;
        ndx++;
        if (ndx >= numChars) ndx = numChars-1;
      }
      else{
        receivedChars[ndx] = '\0'; // terminate the string
        recvInProgress = false;
        ndx = 0;
        newData = true;
      }
    }
    else if (rc == startMarker) recvInProgress = true;
  }
}
