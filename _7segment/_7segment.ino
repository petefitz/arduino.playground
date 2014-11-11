const int LED_A = 2;
const int LED_B = 3;
const int LED_C = 4;
const int LED_D = 5;
const int LED_E = 6;
const int LED_F = 7;
const int LED_G = 8;
const int LED_H = 9;

void setup() {
  pinMode(13, OUTPUT);     

  digitalWrite(13, HIGH);   // set the LED on
  delay(10);              // wait for a second
  digitalWrite(13, LOW);    // set the LED off
  delay(10);              // wait for a second

  pinMode(LED_A, OUTPUT);   // led are output for low will be on
  pinMode(LED_B, OUTPUT);   // led 2 is output
  pinMode(LED_C, OUTPUT);   // led 3 is output
  pinMode(LED_D, OUTPUT);   // led 4 is output
  pinMode(LED_E, OUTPUT);   // led 5 is output
  pinMode(LED_F, OUTPUT);   // led 6 is output
  pinMode(LED_G, OUTPUT);   // led 7 is output
  pinMode(LED_H, OUTPUT);   // led 8 is output

  digitalWrite(LED_A, HIGH);  // stops power to led 1 
  digitalWrite(LED_B, HIGH);  // stops power to led 2 
  digitalWrite(LED_C, HIGH);  // stops power to led 3 
  digitalWrite(LED_D, HIGH);  // stops power to led 4 
  digitalWrite(LED_E, HIGH);  // stops power to led 5 
  digitalWrite(LED_F, HIGH);  // stops power to led 6 
  digitalWrite(LED_G, HIGH);  // stops power to led 7 
  digitalWrite(LED_H, HIGH);  // stops power to led 8
}

void loop() {
  digitalWrite(LED_A, LOW);  // stops power to led 1 
  digitalWrite(LED_B, LOW);  // stops power to led 2 
  digitalWrite(LED_C, LOW);  // stops power to led 3 
  digitalWrite(LED_D, LOW);  // stops power to led 4 
  digitalWrite(LED_E, LOW);  // stops power to led 5 
  digitalWrite(LED_F, LOW);  // stops power to led 6 
  digitalWrite(LED_G, HIGH);  // stops power to led 7 
  digitalWrite(LED_H, HIGH);  // stops power to led 8

  delay(500);   // delays before starting

  digitalWrite(LED_A, HIGH);  // stops power to led 1 
  digitalWrite(LED_B, LOW);  // stops power to led 2 
  digitalWrite(LED_C, LOW);  // stops power to led 3 
  digitalWrite(LED_D, HIGH);  // stops power to led 4 
  digitalWrite(LED_E, HIGH);  // stops power to led 5 
  digitalWrite(LED_F, HIGH);  // stops power to led 6 
  digitalWrite(LED_G, HIGH);  // stops power to led 7 
  digitalWrite(LED_H, HIGH);  // stops power to led 8

  delay(500);   // delays before starting

  digitalWrite(LED_A, LOW);  // stops power to led 1 
  digitalWrite(LED_B, LOW);  // stops power to led 2 
  digitalWrite(LED_C, HIGH);  // stops power to led 3 
  digitalWrite(LED_D, LOW);  // stops power to led 4 
  digitalWrite(LED_E, LOW);  // stops power to led 5 
  digitalWrite(LED_F, HIGH);  // stops power to led 6 
  digitalWrite(LED_G, LOW);  // stops power to led 7 
  digitalWrite(LED_H, HIGH);  // stops power to led 8

  delay(500);   // delays before starting

  digitalWrite(LED_A, LOW);  // stops power to led 1 
  digitalWrite(LED_B, LOW);  // stops power to led 2 
  digitalWrite(LED_C, LOW);  // stops power to led 3 
  digitalWrite(LED_D, LOW);  // stops power to led 4 
  digitalWrite(LED_E, HIGH);  // stops power to led 5 
  digitalWrite(LED_F, HIGH);  // stops power to led 6 
  digitalWrite(LED_G, LOW);  // stops power to led 7 
  digitalWrite(LED_H, HIGH);  // stops power to led 8

  delay(500);   // delays before starting

  digitalWrite(LED_A, HIGH);  // stops power to led 1 
  digitalWrite(LED_B, LOW);  // stops power to led 2 
  digitalWrite(LED_C, LOW);  // stops power to led 3 
  digitalWrite(LED_D, HIGH);  // stops power to led 4 
  digitalWrite(LED_E, HIGH);  // stops power to led 5 
  digitalWrite(LED_F, LOW);  // stops power to led 6 
  digitalWrite(LED_G, LOW);  // stops power to led 7 
  digitalWrite(LED_H, HIGH);  // stops power to led 8

  delay(500);   // delays before starting

  digitalWrite(LED_A, LOW);  // stops power to led 1 
  digitalWrite(LED_B, HIGH);  // stops power to led 2 
  digitalWrite(LED_C, LOW);  // stops power to led 3 
  digitalWrite(LED_D, LOW);  // stops power to led 4 
  digitalWrite(LED_E, HIGH);  // stops power to led 5 
  digitalWrite(LED_F, LOW);  // stops power to led 6 
  digitalWrite(LED_G, LOW);  // stops power to led 7 
  digitalWrite(LED_H, HIGH);  // stops power to led 8

  delay(500);   // delays before starting

  digitalWrite(LED_A, LOW);  // stops power to led 1 
  digitalWrite(LED_B, HIGH);  // stops power to led 2 
  digitalWrite(LED_C, LOW);  // stops power to led 3 
  digitalWrite(LED_D, LOW);  // stops power to led 4 
  digitalWrite(LED_E, LOW);  // stops power to led 5 
  digitalWrite(LED_F, LOW);  // stops power to led 6 
  digitalWrite(LED_G, LOW);  // stops power to led 7 
  digitalWrite(LED_H, HIGH);  // stops power to led 8

  delay(500);   // delays before starting

  digitalWrite(LED_A, LOW);  // stops power to led 1 
  digitalWrite(LED_B, LOW);  // stops power to led 2 
  digitalWrite(LED_C, LOW);  // stops power to led 3 
  digitalWrite(LED_D, HIGH);  // stops power to led 4 
  digitalWrite(LED_E, HIGH);  // stops power to led 5 
  digitalWrite(LED_F, HIGH);  // stops power to led 6 
  digitalWrite(LED_G, HIGH);  // stops power to led 7 
  digitalWrite(LED_H, HIGH);  // stops power to led 8

  delay(500);   // delays before starting

  digitalWrite(LED_A, LOW);  // stops power to led 1 
  digitalWrite(LED_B, LOW);  // stops power to led 2 
  digitalWrite(LED_C, LOW);  // stops power to led 3 
  digitalWrite(LED_D, LOW);  // stops power to led 4 
  digitalWrite(LED_E, LOW);  // stops power to led 5 
  digitalWrite(LED_F, LOW);  // stops power to led 6 
  digitalWrite(LED_G, LOW);  // stops power to led 7 
  digitalWrite(LED_H, HIGH);  // stops power to led 8

  delay(500);   // delays before starting

  digitalWrite(LED_A, LOW);  // stops power to led 1 
  digitalWrite(LED_B, LOW);  // stops power to led 2 
  digitalWrite(LED_C, LOW);  // stops power to led 3 
  digitalWrite(LED_D, LOW);  // stops power to led 4 
  digitalWrite(LED_E, HIGH);  // stops power to led 5 
  digitalWrite(LED_F, LOW);  // stops power to led 6 
  digitalWrite(LED_G, LOW);  // stops power to led 7 
  digitalWrite(LED_H, HIGH);  // stops power to led 8

  delay(500);   // delays before starting

  digitalWrite(LED_A, HIGH);  // stops power to led 1 
  digitalWrite(LED_B, HIGH);  // stops power to led 2 
  digitalWrite(LED_C, HIGH);  // stops power to led 3 
  digitalWrite(LED_D, HIGH);  // stops power to led 4 
  digitalWrite(LED_E, HIGH);  // stops power to led 5 
  digitalWrite(LED_F, HIGH);  // stops power to led 6 
  digitalWrite(LED_G, HIGH);  // stops power to led 7 
  digitalWrite(LED_H, LOW);  // stops power to led 8

  delay(500);   // delays before starting
}
