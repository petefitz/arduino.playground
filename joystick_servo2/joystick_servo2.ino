#include <Servo.h> 
 
Servo horizservo;  // create servo object to control a servo 
Servo vertservo;  // create servo object to control a servo 

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
  // set up serial port for output
  Serial.begin(9600);

  horizservo.attach(HSERVO);  // attaches the servo on pin 9 to the servo object 
  vertservo.attach(VSERVO);  // attaches the servo on pin 9 to the servo object 
  
  pinMode(LED, OUTPUT);
  
  // make the SEL line an input
  pinMode(SEL,INPUT);
  // turn on the pull-up resistor for the SEL line (see http://arduino.cc/en/Tutorial/DigitalPins)
  digitalWrite(SEL,HIGH);

  horizservo.write(horizPos);              // tell servo to go to position in variable 'pos' 
  vertservo.write(vertPos);              // tell servo to go to position in variable 'pos' 
} 
 
void loop() 
{ 
  int vertical, horizontal, select;
  
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

  int newHorizPos = GetNewPosition(horizPos, horizontal);
  int newVertPos = GetNewPosition(vertPos, vertical);
  
  if (newHorizPos != horizPos)
  {
     horizPos = newHorizPos;
     horizservo.write(horizPos);
  }

  if (newVertPos != vertPos)
  {
     vertPos = newVertPos;
     vertservo.write(vertPos);              // tell servo to go to position in variable 'pos' 
  }

  Serial.print(horizPos,DEC);
  Serial.print('-');
  Serial.println(vertPos,DEC);

  delay(15);                       // waits 15ms for the servo to reach the position 
}

int GetNewPosition(int currentPos, int reading)
{
  int newPos = currentPos;
  
  if (reading > 640)
  {
    newPos+=1;
  }
  if (reading > 1008)
  {
    newPos+=1;
  }
  if (reading < 384)
  {
    newPos-=1;
  }
  if (reading < 16)
  {
    newPos-=1;
  }

  if (newPos < 0)
  {
    newPos = 0;
  }
  else if (newPos > 180)
  {
    newPos = 180;
  }
  
  return newPos;
}
