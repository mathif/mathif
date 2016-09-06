#include <SoftwareSerial.h>
SoftwareSerial mySerial(0,1);

const int buttonPin = 6;    
int buttonState = 0;

void setup() {
  mySerial.begin(9600);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin,HIGH);
}


void loop() {
 
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    mySerial.print('0');
    delay(100),
    mySerial.print('1');
    delay(100);
   
    }
}
