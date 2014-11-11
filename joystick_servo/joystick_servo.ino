// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo horizservo;  // create servo object to control a servo 
Servo vertservo;  // create servo object to control a servo 
 
int pos = 0;    // variable to store the servo position 

const int VERT = 0; // analog
const int HORIZ = 1; // analog

const int SEL = 7; // digital
const int LED = 13; // digital

const int HSERVO = 9;
const int VSERVO = 8;

int horizPos = 90;
int vertPos = 90;

void setup() 
{ 
  horizservo.attach(HSERVO);  // attaches the servo on pin 9 to the servo object 
  vertservo.attach(VSERVO);  // attaches the servo on pin 9 to the servo object 
  
  horizservo.write(horizPos);              // tell servo to go to position in variable 'pos' 
  vertservo.write(vertPos);              // tell servo to go to position in variable 'pos' 

  pinMode(LED, OUTPUT);
  
  // make the SEL line an input
  pinMode(SEL,INPUT);
  // turn on the pull-up resistor for the SEL line (see http://arduino.cc/en/Tutorial/DigitalPins)
  digitalWrite(SEL,HIGH);
} 
 
 
void loop() 
{ 
  int vertical, horizontal, select;
  
  // read all values from the joystick
  
  vertical = analogRead(VERT); // will be 0-1023
  horizontal = analogRead(HORIZ); // will be 0-1023
  select = digitalRead(SEL); // will be HIGH (1) if not pressed, and LOW (0) if pressed

  if(select == HIGH)
  {
    digitalWrite(LED, LOW);
  }
  else
  {
    digitalWrite(LED, HIGH);
  }

  int pos;
  
  pos = map(horizontal, 0, 1023, 0, 180);
  if (pos != horizPos)
  {
    horizPos = pos;
    horizservo.write(horizPos);              // tell servo to go to position in variable 'pos' 
  }

  pos = map(vertical, 0, 1023, 0, 180);
  if (pos != vertPos)
  {
    vertPos = pos;
    vertservo.write(vertPos);              // tell servo to go to position in variable 'pos' 
  }

  delay(15);                       // waits 15ms for the servo to reach the position 
}
