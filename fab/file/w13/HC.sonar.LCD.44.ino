 #include <LiquidCrystal.h> //Load Liquid Crystal Library
LiquidCrystal LCD(5,4,3,2,1,0);  //Create Liquid Crystal Object called LCD


const int trigPin = 7;
const int echoPin = 6;

void setup() {

LCD.begin(16,2); //Tell Arduino to start your 16 column 2 row LCD
LCD.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
LCD.print("Target Distance:");  //Print Message on First Row
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
  LCD.setCursor(0,1);  //Set LCD cursor to upper left corner, column 0, row 0
  LCD.print(" "); 
  LCD.setCursor(0,1);  //Set LCD cursor to upper left corner, column 0, row 0
  LCD.print(inches);  //Print Message on First Row
  LCD.print("  in"); 
  //Print your units.
  delay(250); //pause to let things settle
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
//long microsecondsToCentimeters(long microseconds)
//{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  //return microseconds /29 / 2;
//}

