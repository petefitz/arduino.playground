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

#include <SoftwareSerial.h>

//LED Pin Variables
int rxPin = 0;
int txPin = 1;

int ledPins[] = {2,3,4,5,6,7,8,9}; //An array to hold the pin each LED is connected to
                                   //i.e. LED #0 is connected to pin 2, LED #1, 3 and so on
                                   //to address an array use ledPins[0] this would equal 2
                                   //and ledPins[7] would equal 9


int sensorPin = 0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
int speakerPin = 10;
int motorPin = 11;

int lastV = 0;

SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);

void setup() {
  //Set each pin connected to an LED to output mode (pulling high (on) or low (off)
  for(int i = 0; i < 8; i++){         //this is a loop and will repeat eight times
      pinMode(ledPins[i],OUTPUT); //we use this to set each LED pin to output
  }                                   //the code this replaces is below
  pinMode(speakerPin, OUTPUT);
  pinMode(motorPin, OUTPUT);

  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  
  mySerial.begin(9600);
}

void loop() {

  int v;

  char someChar = mySerial.read();
  // print out the character:
  mySerial.print(someChar);
  v = someChar - 48;
  v = constrain(v, 0, 7);
  
  // read the value from the sensor:
  //sensorValue = analogRead(sensorPin);    

  //v = map(sensorValue, 0, 1024, -1, 8);  //potentiometer 0 to 1024

  //v = map(sensorValue, 0, 900, -1, 8);  //photoresistor 0 to 900
  
  //v = constrain(v, 0, 7);
  
  for(int i = 0; i < 8; i++){         
    if (i <= v) {
      digitalWrite(ledPins[i], HIGH);
    }
    else {
      digitalWrite(ledPins[i], LOW);
    }
  }                                   
  
  //int t = 2048 - sensorValue;
  //playTone(t, 1);
  
  //int m = map(sensorValue, 0, 1024, 0, 255);  
  //m = constrain(sensorValue, 0, 255);
  //analogWrite(motorPin, m);
  
  if (v != lastV)
  {
    Serial.println(v);
    lastV = v;
  }
}

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}
