/*
  Puzzle #1: TNT detonation
  original reference: http://www.instructables.com/id/Arduino-defuseable-bomb-perfect-for-airsoft-games-/
*/

#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>
#define pound 14

Servo servo;  // create new servo object
int servo_pos = 0; // store position of servo

int Scount = 12; // count seconds
int Mcount = 10; // count minutes
int Hcount = 0; // count hours
int DefuseTimer = 0; // set timer to 0

long secMillis = 0; // store last time for second add
long interval = 1000; // interval for seconds

char password[4]; // number of characters in our password
int currentLength = 0; //defines which number we are currently writing
int i = 0; 
char entered[4];

int ledPin = 4; //red led
int ledPin2 = 3; //yellow led
int ledPin3 = 2; //green led

LiquidCrystal lcd(7,8,10,11,12,13); // the pins we use on the LCD

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {5, A5, A4, A2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {A1, A0, A3}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

//////////////////////////////////////////////////////////////////
void setup(){
  servo.attach(9); // CONFIGURE SERVO TO DIGITAL PIN

  pinMode(ledPin, OUTPUT); // sets the digital pin as output
  pinMode(ledPin2, OUTPUT); // sets the digital pin as output
  pinMode(ledPin3, OUTPUT); // sets the digital pin as output

  // allow a custom "correct code" to be set upon resetting
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter Code: ");
  while (currentLength < 4)
  {
    lcd.setCursor(currentLength + 6, 1);
    lcd.cursor();
    char key = keypad.getKey();
    key == NO_KEY;
    if (key != NO_KEY)
    {
      if ((key != '*')&&(key != '#'))
      { 
      lcd.print(key);
      password[currentLength] = key;
      currentLength++;
      }
    }
  }

  if (currentLength == 4)
  {
    delay(500);
    lcd.noCursor();
    lcd.clear();
    lcd.home();
    lcd.print("You've Entered: ");
    lcd.setCursor(6,1);
    lcd.print(password[0]);
    lcd.print(password[1]);
    lcd.print(password[2]);
    lcd.print(password[3]);

    delay(2000);
    lcd.clear();
    currentLength = 0;
  }
}

/////////////////////////////////////////////////////////
void loop()
{
  timer();
  char key2 = keypad.getKey(); // get the key
  
  if (key2 == '*')
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Code: ");
      
      while (currentLength < 4)
        {
          
          timer();
          
          char key2 = keypad.getKey(); 
          if (key2 == '#')
            {
              currentLength = 0;
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("Code: ");
            }
          else                  
          if (key2 != NO_KEY)    
            {
              
              lcd.setCursor(currentLength + 7, 0);
              lcd.cursor();
              
              lcd.print(key2);
              entered[currentLength] = key2;
              currentLength++;
              //tone1.play(NOTE_C6, 200);
              delay(100);
              lcd.noCursor();
              lcd.setCursor(currentLength + 6, 0);
              lcd.print("*");
              lcd.setCursor(currentLength + 7, 0);
              lcd.cursor();
            }
        }

      if (currentLength == 4) 
        {
          // check the entered array against the 'correct code' array
          if (entered[0] == password[0] && entered[1] == password[1] && entered[2] == password[2] && entered[3] == password[3])
            {
              // password correct!!!
              lcd.noCursor();
              lcd.clear();
              lcd.home();
              servo.write(0); /////////////////// tell servo to move to position
              lcd.print("CODE CORRECT!");
              delay(2000);
              lcd.clear();
              lcd.print("DETONATED!");
              currentLength = 0;
              digitalWrite(ledPin3, HIGH);
              delay(2500);
              lcd.setCursor(0,1);
              lcd.print("...");
              servo.write(180);
              delay(2500);
              servo.write(0);
              
              delay(100000);  // make the arduino stay at this state
            }
      else
        {
          lcd.noCursor();
          lcd.clear();
          lcd.home();
          lcd.print("CODE INCORRECT!");

          delay(1500);
          lcd.clear();
          currentLength = 0;
  
        }
      }  
    }
}

////////////////////////////// COUNTDOWN FOR "AIR LEFT" TIMER ON DISPLAY
void timer()
{
  Serial.print(Scount);
  Serial.println();
  
  if (Hcount <= 0)
  {
    if ( Mcount < 0 )
    {
      lcd.noCursor();
      lcd.clear();
      lcd.home();
      lcd.print("YOU HAVE ");
      lcd.setCursor (0,1);
      lcd.print("DIED!");
      
      while (Mcount < 0) 
      {
        // visual "game over" feedback through LEDs
        digitalWrite(ledPin, HIGH); // sets the LED on
        delay(100); 
        digitalWrite(ledPin, LOW); // sets the LED off
        delay(100); 
        digitalWrite(ledPin2, HIGH); // sets the LED on
        delay(100); 
        digitalWrite(ledPin2, LOW); // sets the LED off
        delay(100); 
        digitalWrite(ledPin3, HIGH); // sets the LED on
        delay(100); 
        digitalWrite(ledPin3, LOW); // sets the LED off
        delay(100);
      }
    } 
  }


  // OUTPUT FOR CURRENT TIME
  lcd.setCursor (0,1); // sets cursor to 2nd line
  lcd.print ("Timer:");

  if (Hcount >= 10)
    {
      lcd.setCursor (7,1);
      lcd.print (Hcount);
    }
  if (Hcount < 10) 
    {
      lcd.setCursor (7,1);
      lcd.write ("0");
      lcd.setCursor (8,1);
      lcd.print (Hcount);
    }

  lcd.print (":");

  if (Mcount >= 10)
    {
      lcd.setCursor (10,1);
      lcd.print (Mcount);
    }
  if (Mcount < 10) 
    {
      lcd.setCursor (10,1);
      lcd.write ("0");
      lcd.setCursor (11,1);
      lcd.print (Mcount);
    }
    
  lcd.print (":");

  if (Scount >= 10) 
    {
      lcd.setCursor (13,1);
      lcd.print (Scount);
    }
  if (Scount < 10) 
    {
      lcd.setCursor (13,1);
      lcd.write ("0");
      lcd.setCursor (14,1);
      lcd.print (Scount);
    }

  if (Hcount <0) 
    {
      Hcount = 0; 
    }

  if (Mcount <0) 
    {
      Hcount --; 
      Mcount = 59; 
    }

  if (Scount <1) // if 60 do this operation
    {
      Mcount --; // add 1 to Mcount
      Scount = 59; // reset Scount
    }

  if (Scount > 0) // do this oper. 59 times
    {
      unsigned long currentMillis = millis();
  
      if(currentMillis - secMillis > interval) 
        {
          //tone1.play(NOTE_G5, 200);
          secMillis = currentMillis;
          Scount --; // add 1 to Scount
          digitalWrite(ledPin2, HIGH); // sets the LED on
          delay(10); // waits for a second
          digitalWrite(ledPin2, LOW); // sets the LED off
          delay(10); // waits for a second
          //lcd.clear();
        }
    }
}

