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
       if (basePosition < 180) { //First, we need to make sure we do not over-rotate our servo, so we only run the code below if its position is less than 180
          basePosition++;         //Add '1' to our basePosition variable.  This is known as incrementing. 
          base.write(basePosition); //Now we tell the base servo to move to the new servo position. 
    }
  }
  
  else if (button2 == HIGH) {
       if (basePosition > 0) {
          basePosition--;         //This subtracts '1' from our basePosition variable, called decrementing.  We use this to rotate our base servo in the oppostie direction. 
          base.write(basePosition);
     }
  }


}
