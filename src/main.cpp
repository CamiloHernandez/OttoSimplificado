#include <Servo.h>
#include <Oscillator.h>
#include <US.h>
#include <OttoSimplificado.h>
Otto Otto;

/*
         ---------------
        |     O   O     |
        |---------------|
YR 3==> |               | <== YL 2
         ---------------
            ||     ||
RR 5==>   -----   ------  <== RL 4
         |-----   ------|
*/

  #define PIN_YL A3 //servo[2]
  #define PIN_YR A1 //servo[3]
  #define PIN_RL A2 //servo[4]
  #define PIN_RR A0 //servo[5]

bool obstacleDetected = false;
int distance = 0;
///////////////////////////////////////////////////////////////////
//-- Setup ------------------------------------------------------//
///////////////////////////////////////////////////////////////////
void setup(){
  //Set the servo pins
  Otto.init(PIN_YL,PIN_YR,PIN_RL,PIN_RR,A6,A5);
  Otto.home();
  delay(50);

  for (int i = 2; i < 13; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }
}

void obstacleMode(){
      distance = Otto.getDistance();
      if(distance<15){
               Otto.walk(2,1300,-1);
               Otto.turn(3,1000,-1);
             delay(50);
        }
        else{
          Otto.walk(2,1000,1);
        }
      }

void loop() {
  obstacleMode();
 }
