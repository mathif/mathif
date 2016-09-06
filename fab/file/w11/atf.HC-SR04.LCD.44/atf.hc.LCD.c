/* HC-SR04 Sensor
   https://www.dealextreme.com/p/hc-sr04-ultrasonic-sensor-distance-measuring-module-133696
  
   This sketch reads a HC-SR04 ultrasonic rangefinder and returns the
   distance to the closest object in range. To do this, it sends a pulse
   to the sensor to initiate a reading, then listens for a pulse 
   to return.  The length of the returning pulse is proportional to 
   the distance of the object from the sensor.
     
   The circuit:
  * VCC connection of the sensor attached to +5V
  * GND connection of the sensor attached to ground
  * TRIG connection of the sensor attached to digital pin 2
  * ECHO connection of the sensor attached to digital pin 4
   Original code for Ping))) example was created by David A. Mellis
   Adapted for HC-SR04 by Tautvidas Sipavicius
   This example code is in the public domain.
 */
 
//#include <SoftwareSerial.h>
//SoftwareSerial mySerial(0, 1);

#include <LiquidCrystal.h> //Load Liquid Crystal Library
LiquidCrystal LCD(5,4,3,2,1,0);  //Create Liquid Crystal Object called LCD



const int trigPin = 7;
const int echoPin = 6;

void setup() {
  
 // initialize serial communication:
 // mySerial.begin(9600);

LCD.begin(16,2); //Tell Arduino to start your 16 column 2 row LCD

LCD.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
//LCD.print("Target Distance:");  //Print Message on First Row
  
}


void loop()
{
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration, inches, cm;

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  
 // mySerial.print(inches);
  //mySerial.print("in, ");
 // mySerial.print(cm);
 // mySerial.print("cm");
 // mySerial.println();

  //LCD.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
  //LCD.print(cm);  //Print Message on First Row
  //LCD.print("cm");  //Print your units.

  
  LCD.setCursor(0,0);  //Set cursor to first column of second row
 // LCD.print(" "); //Print blanks to clear the row
  LCD.setCursor(0,0);   //Set Cursor again to first column of second row
  LCD.print(inches); //Print measured distance
  LCD.print(" inches");  //Print your units.

  
  LCD.setCursor(0,1);   //Set Cursor again to first column of second row
  //LCD.print(" "); //Print blanks to clear the row
  LCD.print(cm);  //Print Message on First Row
  LCD.print("cm");  //Print your units.

  delay(250); //pause to let things settle

  
  delay(100);
}

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds /29 / 2;
}
