#include <Servo.h>

int basePin = 9;
int midPin = 10;
int clawPin = 11;

Servo base;
Servo mid;
Servo claw;

//This is the control array we are going to use to control the series of positions our arm will cycle through.  Be sure to replace these values with the ones collected in the lesson. 

int controlArray[9][3] = {
  {45, 0, 180},   //Initial Position
  {8, 0, 180},    //Move Base clockwise
  {8, 68, 180},   //Lower Mid
  {8, 68, 130},   //Close Claw
  {8, 0, 130},    //Raise Mid
  {90, 0, 130},   //Move Base Counterclockwise
  {90, 68, 130},    //Lower Mid
  {90, 68, 180},    //Open Claw
  {90, 0, 180},   //Mid Up
};


void setup() {
  for (int i=2; i<8; i++){
    pinMode(i, INPUT);
  }

  pinMode(basePin, OUTPUT);
 pinMode(midPin, OUTPUT);
 pinMode(clawPin, OUTPUT);

base.attach(basePin);
mid.attach(midPin);
claw.attach(clawPin);

Serial.begin(9600);
}


//We can use the variable i to two two things.  We are running our array from top to bottom, or from instruction 0 - 9.  If we want each for loop to run the next instruction, we can use the same number to run the for loop and reference the array instruction.  

void loop() {
  for (int i; i < 10; i++){
      base.write(controlArray[i][0]);
      mid.write(controlArray[i][1]);
      claw.write(controlArray[i][2]);
      delay(200);
  }

}
