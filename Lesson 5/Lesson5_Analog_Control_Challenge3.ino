//If you have completed the previous lesson, variables and voidSetup() is identical.  Code discussion is resumed in voidLoop.

#include <Servo.h>

bool button1;
bool button2;
bool button3;
bool button4;
bool button5;
bool button6;

int basePin = 9;
int midPin = 10;
int clawPin = 11;

float basePosition = 0;
int midPosition = 0;
int clawPosition = 135;

  int basePot;          //Variable for our base potentiometer value
  int midPot;           //Variable for our mid potentiometer value
  int clawPot;          //Variable for our claw potentiometer value

Servo base;
Servo mid;
Servo claw;



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

  base.write(basePosition);
  mid.write(midPosition);
  claw.write(clawPosition);


 Serial.begin(9600);
}

void loop() {
  analogCheckInput();                             //Like the function in the previous lesson, this is used to call three lines of code, checking the values of our three potentiometers.
  basePosition = map(basePot, 0, 1023, 0, 180);   //This is the map function discussed in the lesson. 
  midPosition = map(midPot, 0, 1023, 0, 180);
  clawPosition = map(clawPot, 0, 1023, 0, 180);

  base.write(basePosition);
  mid.write(midPosition);
  claw.write(clawPosition);
}


//Functions
void analogCheckInput(){
  basePot = analogRead(A0);
  midPot = analogRead(A1);
  clawPot = analogRead(A2);
}
