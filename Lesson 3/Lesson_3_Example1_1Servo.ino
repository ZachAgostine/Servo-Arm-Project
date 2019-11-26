#include <Servo.h>

//Servo Pin Variables
int basePin = 9;

//Variables for Initial Servo Positions - you may want to modify these values depending on how the arm was built
float basePosition = 0;

Servo base;

void setup() {
  pinMode(basePin, OUTPUT);
  base.attach(basePin);
}

void loop() {
   base.write(0);   //replace '0' with any number from 0 - 180

}
