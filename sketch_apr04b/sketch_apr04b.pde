/*     ---------------------------------------------------------
 *     |  Arduino Experimentation Kit Example Code             |
 *     |  CIRC-02 .: 8 LED Fun :. (Multiple LEDs)   |
 *     ---------------------------------------------------------
 *  
 *  A few Simple LED animations
 *
 * For more information on this circuit http://tinyurl.com/d2hrud
 *
 */
 
//LED Pin Variables
int ledPins[] = {2,3,4,5,6,7,8}; //An array to hold the pin each LED is connected to
                                   //i.e. LED #0 is connected to pin 2, LED #1, 3 and so on
                                   //to address an array use ledPins[0] this would equal 2
                                   //and ledPins[7] would equal 9
int buttonPin1 = 10;
int buttonPin2 = 11;

int count = 0;
int val;

int numbers[10] = 
        /* 0     1     2     3     4     5     6     7     8     9  */
        { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f };

int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = HIGH;     // previous state of the button

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

/*
 * setup() - this function runs once when you turn your Arduino on
 * We the three control pins to outputs
 */
void setup()
{
  Serial.begin(9600);
  
  //Set each pin connected to an LED to output mode (pulling high (on) or low (off)
  for(int i = 0; i < 7; i++){         //this is a loop and will repeat eight times
      pinMode(ledPins[i],OUTPUT); //we use this to set each LED pin to output
  }                                   //the code this replaces is below
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);

  displayLEDs();
}
 
void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin1);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == LOW) {
      // if the current state is HIGH then the button
      // wend from off to on:
      buttonPushCounter=1;
    } 
    else {
      buttonPushCounter=0;
    }

    // save the current state as the last state, 
    //for next time through the loop
    lastButtonState = buttonState;
  }
  
  if (buttonPushCounter==1)
  {
    count++;
    displayLEDs();
    Serial.println(count);
  }
    
}

/*
 * loop() - this function will start after setup finishes and then repeat
 * we call a function called oneAfterAnother(). if you would like a different behaviour
 * uncomment (delete the two slashes) one of the other lines
 */
void loop1()                     // run over and over again
{
  int last = count;
  int button = 0;
  val = digitalRead(buttonPin1);
  if (val == LOW)
  {
    count++;
    button = buttonPin1;
  }
  else
  {
    val = digitalRead(buttonPin2);
    if (val == LOW)
      count--;
      button = buttonPin2;
  }
  if (last != count)
  {
    displayLEDs();
    Serial.println(count);
    delay(100);
    while (digitalRead(button) == LOW)
    {}
  }
  
}

void displayLEDs()
{
  int disp = numbers[count % 10];
  
//  Serial.println(disp);

  for (int i=0; i<7; i++)
  {
    if (disp & 1)
      digitalWrite(ledPins[i], HIGH);
    else
      digitalWrite(ledPins[i], LOW);

    disp = disp>>1;
//    Serial.println(disp);
  }
}

