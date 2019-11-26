#include <Servo.h>

//Button Pin Variables
bool button1;
bool button2;
bool button3;
bool button4;
bool button5;
bool button6;

//Servo Pin Variables
int basePin = 9;
int midPin = 10;
int clawPin = 11;

//Variables for Initial Servo Positions - you may want to modify these values depending on how the arm was built
float basePosition = 0;
int midPosition = 0;
int clawPosition = 135;

//Declare Servos
Servo base;
Servo mid;
Servo claw;



void setup() {              //Remember, this code only runs once, so we are using it to set up our pins

  //This is a for loop.  We are using it as a more efficent way to write all 6 of our button pins as inputs.
  for (int i=2; i<8; i++){    //Variable i is equal to 2.  This loop will run as long as our variable i is less than 8.  Each time this loop runs, 1 is added to variable i.  This is called incrementing. 
    pinMode(i, INPUT);        //Remeber i equals 2, so when this runs, pin 2 will be declared as an input pin.  When the loop runs again, i will equal 3, and pin 3 will be declared as an input.
  }

//Delcare our servo pins as outputs
 pinMode(basePin, OUTPUT);
 pinMode(midPin, OUTPUT);
 pinMode(clawPin, OUTPUT);

base.attach(basePin);
mid.attach(midPin);
claw.attach(clawPin);


//Write our servos to the initial poisitions
  base.write(basePosition);
  mid.write(midPosition);
  claw.write(clawPosition);


 Serial.begin(9600);
}


//Remember, this loop will run infinitely
void loop() {
  checkInput(); //This is a function - scroll to the bottom to see what code this function executes.  You should see each of our input button variables being updated.   
                //Placing this function here is the same as writing those 6 lines of code.  

                //Pay attention to the functions below in the case statement.
                

                
  if (button1 == HIGH) {    //This is a case statement.  We are asking the code to compare two values.  If the comparison is TRUE, exectue the code in the { brackets }.  If FALSE, the { bracket } code is skipped, and the next if statement is checked. 
    basePositive();
  }
  else if (button2 == HIGH) {
    baseNegative();
  }
  else if (button3 == HIGH) {
    midPositive();
  }
  else if (button4 == HIGH) {
    midNegative();
  }
  else if (button5 == HIGH) {
    clawPositive();
  }
  else if (button6 == HIGH) {
    clawNegative();
  }
  else {                      //In case statements, an else statement can run code if every other compariston returns FALSE.  In this example, we are telling the Arduino that if no buttons are being pressed, the arm should remain at its current base. mid and claw positions. 
  base.write(basePosition);
  mid.write(midPosition);
  claw.write(clawPosition);
  }
  delay(10);
}                           //This is the end of the loop, and the code will now return to the first line of 'void Loop()'.  The code below are functions, which are only run when they are called.




//Functions
void basePositive(){        //This is a collection of code known as a function.  We have named it basePositive because we are adding '1' to the base position value, thus moving it counterclockwise.  
  if (basePosition < 180) { //First, we need to make sure we do not over-rotate our servo, so we only run the code below if its position is less than 180
    basePosition++;         //Add '1' to our basePosition variable.  This is known as incrementing. 
    base.write(basePosition); //Now we tell the base servo to move to the new servo position. 
  }
}

void baseNegative(){
  if (basePosition > 0) {
    basePosition--;         //This subtracts '1' from our basePosition variable, called decrementing.  We use this to rotate our base servo in the oppostie direction. 
    base.write(basePosition);
  }
}

void midPositive(){
  if (midPosition < 180) {
    midPosition++;
    mid.write(midPosition);
  }
}

void midNegative(){
  if (midPosition > 0) {
    midPosition--;
    mid.write(midPosition);
  }
}

void clawPositive(){
  if (clawPosition < 180) {
    clawPosition++;
    claw.write(clawPosition);
  }
}

void clawNegative(){
  if (clawPosition > 0) {
    clawPosition--;
    claw.write(clawPosition);
  }
}

void checkInput(){
   button1 = digitalRead(2);
   button2 = digitalRead(3);
   button3 = digitalRead(4);
   button4 = digitalRead(5);
   button5 = digitalRead(6);
   button6 = digitalRead(7);
}
