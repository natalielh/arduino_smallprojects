/*
  Puzzle #2: Generator
*/

int switchPin = 2; 
int potentiometerIn; 
int fwdPin = 5;   
int revPin = 6;

void setup() {
  // put your setup code here, to run once:
   pinMode(switchPin, INPUT_PULLUP);
   pinMode(fwdPin, OUTPUT); 
   pinMode(revPin, OUTPUT); 
   pinMode(9, OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
    potentiometerIn = analogRead(A0);

   if(digitalRead(switchPin) == LOW ) 
  {
    digitalWrite(5, HIGH); 
    digitalWrite(6, LOW);
    digitalWrite(9, HIGH);
    
      
  }
  else 
  {
   digitalWrite(5, LOW);
   digitalWrite(6, LOW);
   digitalWrite(9, LOW);
  }
}

