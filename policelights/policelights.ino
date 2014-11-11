/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int ledR = 8;
int ledW = 9;
int ledB = 10;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(ledR, OUTPUT);     
  pinMode(ledW, OUTPUT);     
  pinMode(ledB, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(ledR, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(ledW, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(ledB, LOW);    // turn the LED off by making the voltage LOW

  for (int i = 0; i < 5; i++)
  {
    digitalWrite(ledR, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(50);               // wait for a second
    digitalWrite(ledR, LOW);    // turn the LED off by making the voltage LOW
    delay(50);               // wait for a second
  }
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(ledW, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(50);               // wait for a second
    digitalWrite(ledW, LOW);    // turn the LED off by making the voltage LOW
    delay(50);               // wait for a second
  }
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(ledB, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(50);               // wait for a second
    digitalWrite(ledB, LOW);    // turn the LED off by making the voltage LOW
    delay(50);               // wait for a second
  }
}
