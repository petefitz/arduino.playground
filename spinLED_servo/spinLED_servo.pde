/*
 Debounce
 
 Each time the input pin goes from LOW to HIGH (e.g. because of a push-button
 press), the output pin is toggled from LOW to HIGH or HIGH to LOW.  There's
 a minimum delay between toggles to debounce the circuit (i.e. to ignore
 noise).  
 
 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached from pin 2 to +5V
 * 10K resistor attached from pin 2 to ground
 
 * Note: On most Arduino boards, there is already an LED on the board
 connected to pin 13, so you don't need any extra components for this example.
 
 
 created 21 November 2006
 by David A. Mellis
 modified 3 Jul 2009
 by Limor Fried
 
This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Debounce
 */

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
                
// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 10;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
const int motorPin = 9;

int ledPins[] = {2,3,4,5,6,7,8};

int numbers[10] = 
        /* 0     1     2     3     4     5     6     7     8     9  */
        { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f };

int spin[10] = 
        /* 0     1     2     3     4     5     6     7     8     9  */
        { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20 }; //, 0x7d, 0x07, 0x7f, 0x6f };

int val = 0;
int inc = 1;
int val2 = -1;

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 250;    // the debounce time; increase if the output flickers

void setup() {
  Serial.begin(9600);

  for(int i = 0; i < 7; i++){
    pinMode(ledPins[i],OUTPUT);
  }                    
  
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 

  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  
  val += inc;
  if (val < 0 || val > 180)
    inc = -inc;

  if (val%2==0)
    val2 += inc;
  
  if (val2>5)
    val2 = 0;
  else if (val2<0)
    val2 = 5;
  
  displayLEDs();

  myservo.write(val);

  delay(25);
}

void displayLEDs()
{
  //int disp = numbers[constrain(val/18, 0, 9)];
  
  //int disp = spin[constrain((val/2)%6, 0, 5)];
  int disp = spin[val2];

//  int mp = constrain(map(val%10, 0, 9, 0, 255), 0, 255);
//  Serial.print(mp);
//  Serial.print(",");
  
//  analogWrite(motorPin, mp);
  
  for (int i=0; i<7; i++)
  {
    if (disp & 1)
      digitalWrite(ledPins[i], HIGH);
    else
      digitalWrite(ledPins[i], LOW);

    disp = disp>>1;
  }
}

