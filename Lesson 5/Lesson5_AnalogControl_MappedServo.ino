#include <Servo.h>

int basePin = 9;

float basePosition = 0;

int basePot;          //Variable for our base potentiometer value

Servo base;

void setup() {
 pinMode(basePin, OUTPUT);

base.attach(basePin);

base.write(basePosition);


Serial.begin(9600);
}

void loop() {
  basePot = analogRead(A0);
  basePosition = map(basePot, 0, 1023, 0, 180);   //This is the map function discussed in the lesson. 
  base.write(basePosition);
  Serial.println(basePosition);
}
