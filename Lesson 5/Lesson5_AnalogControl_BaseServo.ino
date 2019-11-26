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
  base.write(basePot);
  Serial.println(basePot);
}
