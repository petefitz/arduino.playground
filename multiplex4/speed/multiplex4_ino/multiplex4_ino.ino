//LED TEST 2 w/ 74HC595
//by Amanda Ghassaei 2012
//http://www.instructables.com/id/Multiplexing-with-Arduino-and-the-74HC595/

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
*/

//this code will display the values of ledData across a 4x4 led matrix

//pin connections- the #define tag will replace all instances of "latchPin" in your code with A1 (and so on)
int latchPin = 4;
int clockPin = 3;
int dataPin = 2;

const int SENSOR = 0;

//looping variables
byte i;
byte j;

//storage variable
byte dataToSend;

//storage for led states, 4 bytes
byte ledData[] = {12, 12, 3, 3, 3, 3, 12, 12};

int offset = 4;
int count = 0;
int sensorValue = 0;

void setup() {
  //set pins as output
  
  count = 500; //getSensorValue();
  
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  int x;
  for (i=0;i<4;i++){
    
    //send data from ledData to each row, one at a time
    byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i+offset]);
      
    // setlatch pin low so the LEDs don't change while sending in bits
    digitalWrite(latchPin, LOW);
    // shift out the bits of dataToSend to the 74HC595
    shiftOut(dataPin, clockPin, LSBFIRST, dataToSend);
    //set latch pin high- this sends data to outputs so the LEDs will light up
    digitalWrite(latchPin, HIGH);
    
    x = getSensorValue();
    delay(map(x, 0, 1024, 0, 4)*100);
  } 
 count-=1;
if (count == 0)
  {
    count = 500; //map(sensorValue, 0, 1024, 100, 500);
    if (offset == 0)
      offset = 4;
    else
      offset = 0;
  }
}

int getSensorValue()
{
  sensorValue = analogRead(SENSOR);
  return sensorValue;
//  return map(sensorValue, 0, 1024, 10, 5000);
}


