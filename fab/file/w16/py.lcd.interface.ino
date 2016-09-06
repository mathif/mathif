// include the library code:
#include <LiquidCrystal.h>

#include <SoftwareSerial.h>
SoftwareSerial mySerial(0, 1);


 
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
