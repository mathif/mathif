<div style="width:800px;">


#### [Arduino](https://www.arduino.cc/en/Main/Software) Installetion and setting FabISP

download arduino 1.6.6 zip file

unzip it

move to desktop

open terminal in arduino folder

```
    sudo ./arduino
```

Or  

if you need desktp icon
 
open terminal in arduino folder

```
    sh arduino.desktop
```    
in desktop you can see Arduino IDE file , rigth click on it > properties > permisions> mark tick on "Allow executeing file as program"

now you can see aurduino IDE in your desktop.

#### Programming

##### IC Attiny 44 diagram

![](img/hello.ftdi.44.arduino/ATtiny44)<center></center>


##### [Blink led](code/Blink.zip)

```
    void setup() {
     pinMode(8, OUTPUT);
    }
    void loop() {
    digitalWrite(8, HIGH);   
    delay(1000); 
    digitalWrite(8, LOW);    
    delay(1000);             
    }

``` 
##### [Button press LED on](code/Button_press_LED_on.zip)

```
const int buttonPin = 6;   
const int ledPin =  8;      


int buttonState = 0;         

void setup() {
  
  pinMode(ledPin, OUTPUT);
  
  digitalWrite(buttonPin,HIGH);
}

void loop() {
  
  buttonState = digitalRead(buttonPin);

  
  if (buttonState == HIGH) {
    
    digitalWrite(ledPin, LOW);
  } else {
   
    digitalWrite(ledPin, HIGH);
  }
}

```

##### [Serial communication](code/serialcommunication.zip)

```
 #include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1);


const int buttonPin = 6;     
const int ledPin =  8;    

int buttonState = 0;        

void setup() {
  mySerial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
}

void loop() {
 
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    digitalWrite(ledPin, HIGH);
    mySerial.write("Hello world");
  } else {
    digitalWrite(ledPin, LOW);
  }
}   
    
```



</div>
