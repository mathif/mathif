
#include <SoftwareSerial.h>
SoftwareSerial mySerial(0, 1);

const int trigPin = 7;
const int echoPin = 6;

#define PIN1 4
#define PIN2 5

void setup() {
 mySerial.begin(9600);
 pinMode(PIN1,OUTPUT);
 pinMode(PIN2,OUTPUT);
 digitalWrite(PIN1,LOW);
   digitalWrite(PIN2,LOW);
}

void loop()
{

  long duration, inches, cm;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  delay (100);
   if(mySerial.available()>0)
   {
     switch(mySerial.read())
     {
       case 'b':
         mySerial.println("OKI");
         digitalWrite(PIN1,HIGH);
         break;
       case 'a':
         mySerial.println("OKI");
         digitalWrite(PIN1,LOW);
         break;
       case 'c':
         mySerial.println("OKI");
         digitalWrite(PIN2,LOW);
         break;
       case 'd':
         mySerial.println("OKI");
         digitalWrite(PIN2,HIGH);
         break;
       case 'e':
         mySerial.println("OKI");
         mySerial.print(inches);
         mySerial.print("\n");
         break;
       case 'f':
         mySerial.println("OKI");
         mySerial.print(cm);
         mySerial.print("\n");
         break;

       default: mySerial.println("?");
     }
   }
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
