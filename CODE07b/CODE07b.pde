int ledPin = 9; // choose the pin for the LED
int inputPin1 = 3; // button 1
int inputPin2 = 2; // button 2
 
void setup() {
  pinMode(ledPin, OUTPUT); // declare LED as output
  pinMode(inputPin1, INPUT); // make button 1 an input
  pinMode(inputPin2, INPUT); // make button 2 an input
}
 
int value = 0;
void loop(){
  if (digitalRead(inputPin1) == LOW) {
    value--;
  }
  else if (digitalRead(inputPin2) == LOW) {
    value++; 
  }
  value = constrain(value, 0, 255);
  analogWrite(ledPin, value);
  delay(10);
}
