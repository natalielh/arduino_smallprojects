/*
  Food Cooler
  An Arduino project

  References:

  Potentiometer:
  https://www.arduino.cc/en/tutorial/potentiometer

  L9110 with pulse width modulation:
  https://www.bananarobotics.com/shop/HG7881-(L9110)-Dual-Channel-Motor-Driver-Module
  
*/

//GLOBAL VARS
//input
int potentiometer = 0;  //analog in pin A0

//output
//1a controls motor speed, 1b controls motor direction
int motor_a1a = 10; //PWM pin
int motor_a1b = 12;
int motor_b1a = 11; //PWM pin
int motor_b1b = 13;

//input from potentiometer
int sensor_value = 0;

void setup() {
  
  //declaring the potentiometer pin as an input
  pinMode(potentiometer, INPUT);
  
  //declaring the motor pins as outputs
  pinMode(motor_a1a, OUTPUT);
  pinMode(motor_a1b, OUTPUT);
  pinMode(motor_b1a, OUTPUT);
  pinMode(motor_b1b, OUTPUT);
  
  // to open the serial monitor, press the magnifying glass on the top right of the screen
  digitalWrite(motor_a1b, HIGH);  //motor direction
  digitalWrite(motor_b1b, HIGH);  //motor direction

  Serial.begin(9600);
}

void loop() {
  
  sensor_value = analogRead(potentiometer);
  
  //MOTOR A
  analogWrite(motor_a1a, map(sensor_value, 0, 1023, 0, 255));  //varying motor speed
  //MOTOR B
  analogWrite(motor_b1a, map(sensor_value, 0, 1023, 0, 255));  //varying motor speed
  
  Serial.println(sensor_value);
  delay(10);  //delay for stabilization
}

