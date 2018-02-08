/*
  Moodflowers
  An Arduino project by Natalie Le Huenen

  References:

  Arduino mapping function:
  https://www.arduino.cc/reference/en/language/functions/math/map/
*/

//GLOBAL VARS
//input
int photocell = 0;  //analog in pin A0
//output
int bluepin = 10; //digital pin 10
int yellowpin = 11; //digital pin 11

//setting the initial brightness of LEDs to zero, this is modified based on the photocell's reading
int blue_brightness = 0;
int yellow_brightness = 0;

void setup() {
  //declaring the photocell pin as an input
  pinMode(photocell, INPUT);
  //declaring the blue and yellow LED pins as outputs
  pinMode(bluepin, OUTPUT);
  pinMode(yellowpin, OUTPUT);
  Serial.begin(9600);
  // to open the serial monitor, press the magnifying glass on the top right of the screen
}

void loop() {
  Serial.println(analogRead(photocell));  //print out the value that is read through the photoresistor
  //make the blue LED shine brighter the darker the environment is:
  analogWrite(bluepin, 255 - map(analogRead(photocell), 0, 1023, 0, 255));
  //make the yellow LED shine brighter the brighter the environment is
  analogWrite(yellowpin, map(analogRead(photocell), 0, 1023, 0, 255));
}

