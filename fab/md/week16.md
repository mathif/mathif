title: week-16
tags: ["handlebars", "template"]
---

# Week 16 : Interface and application programming (May 18)

## Assignment:

This week assignemt is to write an application that interface with an Input or Output device I've made as well as to compare as many tool options as possible.

------------


## Ubuntu terminal interface with LCD


I wish to interface my ubuntu terminal with my output device LCD board which I made during output week. I used python program for creating my interface application.[http://learnpythonthehardway.org/book/](http://learnpythonthehardway.org/book/)  is the best online site for learning the python language.

First I refered the pyhton program that interface with ubuntu terminal. then I started to create the interface app.



```
import serial
import time
 
s = serial.Serial('/dev/ttyUSB0', 9600) #port is /dev/ttyUSB0, and baud rate is 9600
time.sleep(2)    #wait for the Serial to initialize
s.write('Ready...')
while True:
    str = raw_input('Enter text: ')
    str = str.strip()
    if str == 'exit' :
        break
    s.write(str)
```
Then i tried to run the program. But it was't. Searched on online and got some solution. Confirm wheater npm,websocket,serialport installed or not. here the commends.


`
sudo apt install npm
`

`
sudo npm install websocket
`

`
sudo npm --websocket:verbose --nodedir=/home/ubuntu/node install -g websocket
`

`
sudo npm --websocket:verbose --nodedir=/home/ubuntu/node-v0.10.32 install -g websocket
`

`
npm install serialport
`



Install Minicom 

Minicom is a text-based serial port communications program. It is used to talk to external RS-232 devices such as mobile phones, routers, and serial console ports. 

`
sudo apt-get install minicom
`

`
dmesg | grep tty
`

Again I run  the progrm. Same problem.. I recheked it again. At last found the serial port name changed, Corrected it into `dev/ttyUSB0` and again restarted the program..


<video width="720" height="420" controls="">
           <source src="gif/w16/test.interface.mp4" type="video/mp4">
           Your browser does not support the video tag.
           </video>





-----------


I programmed the the board which i made during output week. Using Arduino IDE I upload the program to Attiny 44. Declare the LCD pins are 5,4,3,2,1,0 and the Rx, TX pins are 6,7.


```
// include the library code:
#include <LiquidCrystal.h>

#include <SoftwareSerial.h>
SoftwareSerial mySerial(6,7);
 
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(5, 4, 3, 2,1,0);
 
void setup() {
  mySerial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("start");
}
 
void loop() {
  if (mySerial.available()) {
    delay(100);  //wait some time for the data to fully be read
    lcd.clear();
    while (mySerial.available() > 0) {
      char c = mySerial.read();
      lcd.write(c);
    }
  }
}
```


Then I connected the LCD board  and again run it. checke the output. Some of the letters connot display on the LCD.


<video width="720" height="420" controls="">
           <source src="gif/w16/interface1.mp4" type="video/mp4">
           Your browser does not support the video tag.
           </video>



-------





## Interface With Ulrasonic sensor

Then I tried to create Python program for Printing the measured diatance value using HC-05 Sonar sensor. Also I added two Switch control options. There I am goin to place each LEDs. I want to print the measured distance in inches and in centimeters. I created the python refering the previous students.



```
from Tkinter import * # Import tk module
import tkFont
import serial
import time

arduino=serial.Serial() #Serial comunication with fabKit (Arduino UNO compatible)
arduino.port ="/dev/ttyUSB0" #Change this value for your COM / tty
arduino.baudrate = 9600 #comunication to 9600 bauds

arduino.open()

def sendOrder(order):
     vf['text']="Waiting response..."
     v0.update_idletasks()
     arduino.flushInput()
     arduino.flushOutput()
     arduino.write(order+"\r\n")

     if arduino.readline()=="OKI\r\n": # "OKI\r\n" is the default response of fabkit program

         if order=="b":
             v2['text']="State Output 2: ON"
             v2['bg']="green"
         elif order=="a":
             v2['text']="State Output 2: OFF"
             v2['bg']="red"
         elif order=="d":
             v1['text']="State Output 1: ON"
             v1['bg']="green"
         elif order=="c":
             v1['text']="State Output 1: OFF"
             v1['bg']="red"
         elif order=="e":
             t1['text']="Distance:  "+arduino.readline().rstrip() + " inches"
         elif order=="f":
             h1['text']="Distance:  "+arduino.readline().rstrip() + " centimeters"
     vf['text']=""

print ("Athif interface- Fab academy 2016") # Say hello in console (for debug, you can erase)
v0 = Tk() # Tk() Main window
v0.wm_title("Athif Fab Academy - Interface and Application Programming")
#v0.config(bg="black") # if you need change background color
v0.geometry("800x400") # windows size for aplication

helv16 = tkFont.Font(family="Helvetica",size=16,weight="bold")
helv24 = tkFont.Font(family="Helvetica",size=24,weight="bold")
helv14 = tkFont.Font(family="Helvetica",size=14,weight="bold")
helv8 = tkFont.Font(family="Helvetica",size=8,weight="bold")
l = Label(v0,font=helv16,text="Athif Fab Academy - Interface and Application Programming")
l.place(relx=.5, rely=.1, anchor="c")

v1 = Label(v0,font=helv14,text="State Output 1: OFF",bg="red")
v1.place(relx=.2, rely=.35, anchor="c")
v2 = Label(v0,font=helv14,text="State Output 2: OFF",bg="red")
v2.place(relx=.2, rely=.45, anchor="c")
t1 = Label(v0,font=helv14,text="Distance in inches: --")
t1.place(relx=.2, rely=.53, anchor="c")
h1 = Label(v0,font=helv14,text="Distance in centimeters: --")
h1.place(relx=.2, rely=.60, anchor="c")
b1=Button(v0,text="Activate output 1",width=20,command=lambda: sendOrder('d'))
b1.place(relx=.5, rely=.35, anchor="c")
#b1['text']="test"
b2=Button(v0,text="Disable output 1",width=20,command=lambda: sendOrder("c"))
b2.place(relx=.8, rely=.35, anchor="c")

b3=Button(v0,text="Activate output 2",width=20,command=lambda: sendOrder("b"))
b3.place(relx=.5, rely=.45, anchor="c")
#b1['text']="test"
b4=Button(v0,text="Disable output 2",width=20,command=lambda: sendOrder("a"))
b4.place(relx=.8, rely=.45, anchor="c")

b5=Button(v0,text="Update Distance",width=20,command=lambda: sendOrder("e"))
b5.place(relx=.8, rely=.53, anchor="c")

b6=Button(v0,text="Update Distance",width=20,command=lambda: sendOrder("f"))
b6.place(relx=.8, rely=.60, anchor="c")

vf = Label(v0,font=helv8,text="Waiting response...")
vf .place(relx=.5, rely=.97, anchor="c")
vf['text']=""
v0.mainloop() # launch the main window
```

Oped the program and tested the interfaces. Its oke..


<video width="720" height="420" controls="">
           <source src="gif/w16/atf.interface.ogv" type="video/ogg">
           Your browser does not support the video tag.
           </video>

Then created the Arduino program. which actaully is a modification of LCD print. Added 6 cases for reading each operations.



```
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
```


Compalied it and uploaded the program to the input board. Run the python program and tested it.. it almost okay..

<video width="720" height="420" controls="">
           <source src="gif/w16/interface.mp4" type="video/mp4">
           Your browser does not support the video tag.
           </video>



-----------------


## Files

* Ubuntu terminal interface with LCD,[py.lcd.interface.ino](file/w16/py.lcd.interface.ino),[py.lcd.interface.py](file/w16/py.lcd.interface.py)

* Interface With Ulrasonic sensor,[HC05.LED.python.interface.ino](file/w16/HC05.LED.python.interface.ino),[HC05.LED.python.interface.py](file/w16/HC05.LED.python.interface.py)
