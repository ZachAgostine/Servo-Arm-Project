#include <Servo.h>

//Button status
bool button1;
bool button2;

//Servo Pin Variables
int basePin = 9;

//Variables for Initial Servo Positions - you may want to modify these values depending on how the arm was built
float basePosition = 0;

Servo base;

void setup() {
  pinMode(basePin, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  
  base.attach(basePin);
}

void loop() {
   button1 = digitalRead(2); // checks if button 1 is pressed
   button2 = digitalRead(3);  //checks if button 2 is pressed
   
  if (button1 == HIGH) {    //This is a case statement.  We are asking the code to compare two values.  If the comparison is TRUE, exectue the code in the { brackets }.  If FALSE, the { bracket } code is skipped, and the next if statement is checked. 
       base.write(0);   //replace '0' with any number from 0 - 180
  }
  else if (button2 == HIGH) {
       base.write(180);   //replace '180' with any number from 0 - 180
  }


}
