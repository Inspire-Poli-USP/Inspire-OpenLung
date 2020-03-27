// Bounce.pde

#include "AccelStepper.h"


#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19


AccelStepper stepper(1,Z_STEP_PIN, Z_DIR_PIN);

bool start = false;

//Connection stuff
const byte numChars = 32;
char receivedChars[numChars];
boolean newData = false;


long t0=0;

void setup()
{  

   pinMode(Z_STEP_PIN  , OUTPUT);
   pinMode(Z_DIR_PIN    , OUTPUT);
   pinMode(Z_ENABLE_PIN    , OUTPUT);

  // Change these to suit your stepper if you want
  stepper.setMaxSpeed(2500);
  stepper.setAcceleration(2500);
  stepper.moveTo(750);


  Serial.begin(9600);
  Serial.println("Started!");
  
}



void loop()
{
  recvWithStartEndMarkers();

   //Incoming info
    if(newData){
               
       String input(receivedChars);

       if(input.startsWith("v")){          
          //Serial.println("Start");
          int speed = input.substring(1).toInt();          
          stepper.setMaxSpeed(speed);          
       }

         if(input.startsWith("c")){          
          //Serial.println("Start");
          int speed = input.substring(1).toInt();          
          stepper.moveTo(speed);
          
       }

         if(input.startsWith("a")){          
          //Serial.println("Start");
          int speed = input.substring(1).toInt();          
          stepper.setAcceleration(speed);
          
       }
      

       if(input == "i"){
          start = true;
          Serial.println("Start");
       }


       if(input == "f")
          start = false;

        //clear input
        newData = false;
    }
    

  if(start){
       
    // If at the end of travel go to the other end
    if (stepper.distanceToGo() == 0){
      stepper.moveTo(-stepper.currentPosition());

       //tempo de meio ciclo
       Serial.print(millis() - t0);      
       Serial.println("ms");
       //Serial.println(t0);
       t0 = millis();  
          
    }
      
    stepper.run();
    
  }else if(stepper.currentPosition() != 0){

      if (stepper.distanceToGo() == 0)
      stepper.moveTo(-stepper.currentPosition());
      
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
