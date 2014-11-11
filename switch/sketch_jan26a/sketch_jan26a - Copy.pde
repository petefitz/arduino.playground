/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13. 
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead(). 
 
 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground
 
 * Note: because most Arduinos have a built-in LED attached 
 to pin 13 on the board, the LED is optional.
 
 
 Created by David Cuartielles
 Modified 16 Jun 2009
 By Tom Igoe
 
 http://arduino.cc/en/Tutorial/AnalogInput
 
 */

#include <Servo.h>
Servo myServo;
int servoPos = 0;

//LED Pin Variables
int ledPins[] = {2,3,4,5,6,7}; //An array to hold the pin each LED is connected to
                                   //i.e. LED #0 is connected to pin 2, LED #1, 3 and so on
                                   //to address an array use ledPins[0] this would equal 2
                                   //and ledPins[7] would equal 9

int leftPin = 8;
int rightPin = 9;
int servoPin = 10;

void setup() {
  //Set each pin connected to an LED to output mode (pulling high (on) or low (off)
  for(int i = 0; i < 6; i++){         //this is a loop and will repeat eight times
      pinMode(ledPins[i],OUTPUT); //we use this to set each LED pin to output
  }                                   //the code this replaces is below
  pinMode(leftPin, INPUT);
  pinMode(rightPin, INPUT);
  
  myServo.attach(servoPin);
  
  Serial.begin(9600);
}

void loop() {

  int newValue;
  newValue = servoPos;
  
  int isPressed;
  
  isPressed = digitalRead(leftPin);
  if (isPressed == LOW)
  {
    isPressed = 1;
    while (digitalRead(leftPin) == LOW && isPressed-- > 0)
    {
      //Serial.println("Let go Left");
      delay(15);
    }
    if (newValue > 0)
    {
      newValue--;
    }
  }
  
  isPressed = digitalRead(rightPin);
  if (isPressed == LOW)
  {
    isPressed = 1;
    while (digitalRead(rightPin) == LOW && isPressed-- > 0)
    {
      //Serial.println("Let go Right");
      delay(15);
    }
    if (newValue < 179)
    {
      newValue++;
    }
  }
  
  if (newValue != servoPos)
  {
    servoPos = newValue;
    myServo.write(servoPos);

    int led;
    led = servoPos / 30; //map(servoPos, 0, 179, 0, 5);    
    for(int i = 0; i < 6; i++){         
      if (i == led) {
        digitalWrite(ledPins[i], HIGH);
      }
      else {
        digitalWrite(ledPins[i], LOW);
      }
    }                                   

    Serial.print(servoPos);
    Serial.print("\t");
    Serial.println(led);
  }
}
