void setup() {  // put your setup code here, to run once:
  pinMode(13, OUTPUT);    //This tells the board that pin 13 will output voltage.
  
}

void loop() {  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH); //This tells the board that pin 13 should ouput 5 volts.
  delay(1000);            //Wait for 1 second
  digitalWrite(13, LOW); //This tells the board that pin 13 should ouput 5 volts.
  delay(1000);
}
