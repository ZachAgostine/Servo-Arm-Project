#include <Servo.h>

int basePin = 9;
int midPin = 10;

int xPos;     //This is a variable for the x-axis
int yPos;     //This is a variable for the y-axis

Servo base;
Servo mid;

float basePosition = 0;
int midPosition = 0;


void setup() {
 pinMode(basePin, OUTPUT);
 pinMode(midPin, OUTPUT);

base.attach(basePin);
mid.attach(midPin);

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
