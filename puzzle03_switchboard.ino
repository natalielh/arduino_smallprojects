 /*
 References 
 https://www.arduino.cc/en/tutorial/switch
 http://www.arduino.cc/en/Tutorial/Button
 https://learn.adafruit.com/adafruit-circuit-playground-express?view=all#downloads
 */
 
#include <Adafruit_CircuitPlayground.h>

// The correct order of the switches being flipped is
// 3 > 2 > 7 > 1 > 8 > 6 > 9

// constant integers for the switch inputs 
const int switchOne = 0;  // A6
const int switchTwo = 1;  // A7
const int switchThree = 2;  // A5
// const int switchFour = 3; // Trojan switch
// const int switchFive = 6; // Trojan switch
const int switchSix = 9;  // A2  
const int switchSeven = 10;  // A3 
const int switchEight = 3;  // A4
const int switchNine = 6; // A1
// const int switchTen = 6;  // Trojan switch

// variables for the digital read switches
int r1, r2, r3, r6, r7, r8, r9 = 0;

void setup() {
  // initiate Circuit Playground
  CircuitPlayground.begin();

  // declare the inputs
  pinMode(switchOne, INPUT);
  pinMode(switchTwo, INPUT);
  pinMode(switchThree, INPUT);
  pinMode(switchSix, INPUT);
  pinMode(switchSeven, INPUT);
  pinMode(switchEight, INPUT);
  pinMode(switchNine, INPUT);
}

void loop() {
  // clear the neo pixels
  CircuitPlayground.clearPixels();

  // 0.5 second delay before the pixels turn on
  delay(500);


  // set these three pixels to red
  CircuitPlayground.setPixelColor(3, 255, 0, 0);
  CircuitPlayground.setPixelColor(4, 255, 0, 0);
  CircuitPlayground.setPixelColor(9, 255, 0, 0);
  
  // read the digital I/O from the switches
  r1 = digitalRead(switchOne);
  r2 = digitalRead(switchTwo);
  r3 = digitalRead(switchThree);
  r6 = digitalRead(switchSix);
  r7 = digitalRead(switchSeven);
  r8 = digitalRead(switchEight);
  r9 = digitalRead(switchNine);

  // if the switch is toggled then set the colour to green, otherwise set it to red
  if (r1 == HIGH) {
    CircuitPlayground.setPixelColor(0, 0, 255, 0);  
  }
  else {
    CircuitPlayground.setPixelColor(0, 255, 0, 0);
  }
  if (r2 == HIGH) {
    CircuitPlayground.setPixelColor(1, 0, 255, 0);    
  }
  else {
    CircuitPlayground.setPixelColor(1, 255, 0, 0);
  }
  if (r3 == HIGH) {
    CircuitPlayground.setPixelColor(2, 0, 255, 0);  
  }
  else {
    CircuitPlayground.setPixelColor(2, 255, 0, 0);
  }
  if (r6 == HIGH) {
    CircuitPlayground.setPixelColor(5, 0, 255, 0);    
  }
  else {
    CircuitPlayground.setPixelColor(5, 255, 0, 0);
  }
  if (r7 == HIGH) {
    CircuitPlayground.setPixelColor(6, 0, 255, 0);  
  }
  else {
    CircuitPlayground.setPixelColor(6, 255, 0, 0);
  }
  if (r8 == HIGH) {
    CircuitPlayground.setPixelColor(7, 0, 255, 0);    
  }
  else {
    CircuitPlayground.setPixelColor(7, 255, 0, 0);
  }
  if (r9 == HIGH) {
    CircuitPlayground.setPixelColor(8, 0, 255, 0);  
  }
  else {
    CircuitPlayground.setPixelColor(8, 255, 0, 0);
  }

  // if all the switches - besides the trojan switches - are toggled, then set the all the switches to green 
  if (r1 == HIGH && r2 == HIGH && r3 == HIGH && r6 == HIGH && r7 == HIGH && r8 == HIGH && r9 ==    HIGH){
    CircuitPlayground.setPixelColor(0, 0, 255, 0);
    CircuitPlayground.setPixelColor(1, 0, 255, 0);
    CircuitPlayground.setPixelColor(2, 0, 255, 0);
    CircuitPlayground.setPixelColor(3, 0, 255, 0);
    CircuitPlayground.setPixelColor(4, 0, 255, 0);
    CircuitPlayground.setPixelColor(5, 0, 255, 0);
    CircuitPlayground.setPixelColor(6, 0, 255, 0);
    CircuitPlayground.setPixelColor(7, 0, 255, 0);
    CircuitPlayground.setPixelColor(8, 0, 255, 0);
    CircuitPlayground.setPixelColor(9, 0, 255, 0);
    
    // play a tone at 440 Hz (A) for 5 seconds, then delay for 5 seconds
    CircuitPlayground.playTone(440, 5000);
    delay(5000);
  }
}

