#include <SoftwareSerial.h>
SoftwareSerial mySerial(7,6);

#include <LiquidCrystal.h> //Load Liquid Crystal Library
LiquidCrystal LCD(5,4,3,2,1,0);  //Create Liquid Crystal Object called LCD


const int ledPin = 8 ;      // the number of the LED pin

char data;

void setup() {
  // initialize
  LCD.begin(16,2);
  LCD.setCursor(0,0);
  LCD.print("Welcome to ooty");
  
  pinMode(ledPin, OUTPUT);
  mySerial.begin(9600);
}

void loop() {
  data = mySerial.read();
  
  if (data == '1') {
    digitalWrite(ledPin, HIGH);  
    LCD.setCursor(0,1);
    LCD.print("Nice to meet you");
   }
    else {
 digitalWrite(ledPin, LOW);
 LCD.setCursor(0,1);
 LCD.print("                ");


  }
  delay(100);
}
