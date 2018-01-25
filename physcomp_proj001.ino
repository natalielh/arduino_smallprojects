/*
  RESOURCES USED:
  Adafruit Arduino - Lesson 3. RGB LED: https://learn.adafruit.com/adafruit-arduino-lesson-3-rgb-leds/arduino-sketch
  Arduino Fading LED Tutorial: https://www.arduino.cc/en/Tutorial/Fade
*/

int redPin = 11;
int greenPin = 10;
int bluePin = 9;

int redBrightness = 255;  //initial red brightness of led #1
int blueBrightness = 0; //initial blue brightness of led #2
//int greenBrightness = 0;

int redFadeAmount = 3;
int blueFadeAmount = -3;
//int greenFadeAmount = 3;

void setup() {
  //configure 3 PWM arduino pins as outputs for the LEDs connected in parallel
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
    // set the brightness of red pin:
    analogWrite(redPin, redBrightness);
    analogWrite(bluePin, blueBrightness);
  
    // change the brightness for next time through the loop:
    redBrightness = redBrightness - redFadeAmount;
    blueBrightness = blueBrightness - blueFadeAmount;
  
    // reverse the direction of the fading at the ends of the fade:
    //since they are matched up, we only need to check red
    if (redBrightness <= 0 || redBrightness >= 255) {
     redFadeAmount = -redFadeAmount;
     blueFadeAmount = -blueFadeAmount;
     delay(3000);  //pause when reaching 100% blue or 100% red
   }
  
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}

