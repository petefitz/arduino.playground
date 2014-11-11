int ledPin = 13; // choose the pin for the LED
int inputPin1 = 3; // button 1
int inputPin2 = 2; // button 2
 
void setup() {
  pinMode(ledPin, OUTPUT); // declare LED as output
  pinMode(inputPin1, INPUT); // make button 1 an input
  pinMode(inputPin2, INPUT); // make button 2 an input
}
 
void loop(){
  if (digitalRead(inputPin1) == LOW) {
    digitalWrite(ledPin, LOW); // turn LED OFF
  } else if (digitalRead(inputPin2) == LOW) {
    digitalWrite(ledPin, HIGH); // turn LED ON
  }
}
