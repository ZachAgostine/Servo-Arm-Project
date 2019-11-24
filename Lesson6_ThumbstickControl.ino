#include <Servo.h>

int basePin = 9;
int midPin = 10;
int clawPin = 11;

int xPos;     //This is a variable for the x-axis
int yPos;     //This is a variable for the y-axis

Servo base;
Servo mid;
Servo claw;

float basePosition = 0;
int midPosition = 0;
int clawPosition = 120;

bool clawFlag = 0;


void setup() {
 pinMode(basePin, OUTPUT);
 pinMode(midPin, OUTPUT);
 pinMode(clawPin, OUTPUT);

base.attach(basePin);
mid.attach(midPin);
claw.attach(clawPin);

Serial.begin(9600);
}

void loop() {
  analogCheckInput();
  basePosition = map(xPos, 0, 1023, 0, 85);     //This is to safely map the base servo so it's full range is roughly 90 degrees. 
  midPosition = map(yPos, 0, 1023, 0, 80);      //This is to safely map the mid servo so it's full range will not collide with the table.

  base.write(basePosition);
  mid.write(midPosition);

//This is a simple block of code that checks if the claw button has been pressed, and if it is, run the function clawMove.

bool checkButton = digitalRead(2);
if (checkButton == HIGH){
  clawMove();
  delay(1000);
}

}

void analogCheckInput(){
  xPos = analogRead(A3);   
  yPos = analogRead(A4);
}

//This function forms a flip flop.  The claw can only be in two states, open or closed.  So when it is closed, and this function is run, it will open.  When open, it will close. 

void clawMove(){
  if (clawPosition == 120){   //if in closed position...
    clawPosition = 180;       //Open
  }
  else if (clawPosition == 180){    //if in open position...
    clawPosition = 120;             //Close
  }
claw.write(clawPosition);
}
