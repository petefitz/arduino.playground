const int SENSOR = 0;
const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 5;
const int LED5 = 6;
const int LED6 = 7;
const int LED7 = 8;
const int LED8 = 9;

int delayValue;

void setup() {
  pinMode(13, OUTPUT);     

  digitalWrite(13, HIGH);   // set the LED on
  delay(10);              // wait for a second
  digitalWrite(13, LOW);    // set the LED off
  delay(10);              // wait for a second

  pinMode(LED1, OUTPUT);   // led are output for low will be on
  pinMode(LED2, OUTPUT);   // led 2 is output
  pinMode(LED3, OUTPUT);   // led 3 is output
  pinMode(LED4, OUTPUT);   // led 4 is output
  pinMode(LED5, OUTPUT);   // led 5 is output
  pinMode(LED6, OUTPUT);   // led 6 is output
  pinMode(LED7, OUTPUT);   // led 7 is output
  pinMode(LED8, OUTPUT);   // led 8 is output

  digitalWrite(LED1, HIGH);  // stops power to led 1 
  digitalWrite(LED2, HIGH);  // stops power to led 2 
  digitalWrite(LED3, HIGH);  // stops power to led 3 
  digitalWrite(LED4, HIGH);  // stops power to led 4 
  digitalWrite(LED5, HIGH);  // stops power to led 5 
  digitalWrite(LED6, HIGH);  // stops power to led 6 
  digitalWrite(LED7, HIGH);  // stops power to led 7 
  digitalWrite(LED8, HIGH);  // stops power to led 8
}

void loop() {
  DisplayValue(192);
  delay(GetDelay());
  DisplayValue(249);
  delay(GetDelay());
  DisplayValue(164);
  delay(GetDelay());
  DisplayValue(176);
  delay(GetDelay());
  DisplayValue(153);
  delay(GetDelay());
  DisplayValue(146);
  delay(GetDelay());
  DisplayValue(130);
  delay(GetDelay());
  DisplayValue(248);
  delay(GetDelay());
  DisplayValue(128);
  delay(GetDelay());
  DisplayValue(144);
  delay(GetDelay());
}

void DisplayValue(int value)
{
  digitalWrite(LED1, value & 1);  // stops power to led 1 
  digitalWrite(LED2, value & 2);  // stops power to led 2 
  digitalWrite(LED3, value & 4);  // stops power to led 3 
  digitalWrite(LED4, value & 8);  // stops power to led 4 
  digitalWrite(LED5, value & 16);  // stops power to led 5 
  digitalWrite(LED6, value & 32);  // stops power to led 6 
  digitalWrite(LED7, value & 64);  // stops power to led 7 
  digitalWrite(LED8, value & 128);  // stops power to led 8
}

int GetDelay()
{
  delayValue = analogRead(SENSOR)+50;
  return delayValue;
}
