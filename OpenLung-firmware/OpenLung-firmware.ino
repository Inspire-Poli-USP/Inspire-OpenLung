// Poli Inspira

// emoretto at usp.br
// v4

#include "AccelStepper.h"

#define Z_STEP_PIN         3
#define Z_DIR_PIN          2
#define Z_ENABLE_PIN       1
#define Z_MIN_PIN          12
#define Z_MAX_PIN          11

int stepsPerRevFactor = 2;

AccelStepper stepper(1,Z_STEP_PIN, Z_DIR_PIN);

bool start = false;

//Connection stuff
const byte numChars = 32;
char receivedChars[numChars];
boolean newData = false;


//speed in steps per second
//acceleration in steps per second

int currentSpeed = 2000;
int currentAcc = 1000;
int currentCourse = 500;
float currentRate = 2; //stepper driver rate

long t0=0;

void setup()
{  

   pinMode(Z_STEP_PIN  , OUTPUT);
   pinMode(Z_DIR_PIN    , OUTPUT);
   pinMode(Z_ENABLE_PIN    , OUTPUT);

  // start your engines
  stepper.setMaxSpeed(currentSpeed);
  stepper.setAcceleration(currentAcc);
  stepper.moveTo(currentCourse*stepsPerRevFactor);

  // houston
  Serial.begin(9600);
  Serial.println("Started!");
}



void loop()
{
  recvWithStartEndMarkers();

   //Incoming info
    if(newData){
               
       String input(receivedChars);

        //velocidade
       if(input.startsWith("v")){          
          currentSpeed = input.substring(1).toInt();          
          stepper.setMaxSpeed(currentSpeed*stepsPerRevFactor);          
       }

        //curso
       if(input.startsWith("c")){          
          currentCourse = input.substring(1).toInt(); 
          currentCourse = currentCourse*stepsPerRevFactor;        
          stepper.moveTo(currentCourse);
       }

        //aceleracao
       if(input.startsWith("a")){          
          currentAcc = input.substring(1).toInt();          
          stepper.setAcceleration(currentAcc*stepsPerRevFactor);
       }

       //mover (comando manual)
       if(input.startsWith("m")){          
          start = false;
          int value = input.substring(1).toInt();
          stepper.runToNewPosition(value*stepsPerRevFactor);
          stepper.setCurrentPosition(0);
       }

        // Inpiracao/Expiracao rate
       if(input.startsWith("r")){          
          start = false;
          currentRate  = input.substring(1).toFloat();
       }
      
        //inicio
       if(input == "i"){
          stepper.setCurrentPosition(0);
          //.moveTo(-stepper.currentPosition());
          start = true;
          Serial.println("Start");
       }

        //fim
       if(input == "f")
          start = false;

        //clear input
        newData = false;
    }
    

  if(start){
       
    // If at the end of travel go to the other end
    if (stepper.currentPosition() == 0){

     stepper.setMaxSpeed(currentSpeed);
     stepper.setAcceleration(currentAcc);
     stepper.moveTo(currentCourse);

       //tempo de meio ciclo
       //Serial.println(millis() - t0);      
       //Serial.println("ms");
      // t0 = millis();  
          
    }

    else if (stepper.currentPosition() == currentCourse){

        stepper.setMaxSpeed(currentSpeed/currentRate);
        stepper.setAcceleration(currentAcc/currentRate);    
        
        stepper.moveTo(0);
    }
      
    stepper.run();
    
  }else if(stepper.currentPosition() != 0){

      stepper.moveTo(0);
      stepper.run();
  }
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
