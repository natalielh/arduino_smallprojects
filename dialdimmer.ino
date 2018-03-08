/*
  LED dial dimmer

  Components:
  1x potentiometer
  1x LED
*/

//GLOBAL VARS
//input
int potentiometer = 0;  //analog in pin A0
//output
int led = 11; //digital pin 11

void setup() {
  //declaring the potentiometer pin as an input
  pinMode(potentiometer, INPUT);
  //declaring the led pin as output
  pinMode(led, OUTPUT);
}

void loop() {
  //output to LED using PWM
  analogWrite(led, map(analogRead(potentiometer), 0, 1023, 0, 255));
}

