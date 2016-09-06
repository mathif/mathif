title: week-13
tags: ["handlebars", "template"]
---

# Week - 13 : Output devices : Apr 27


## Assignment :

This week we need to add an output device into the existing microcontroller board we have made.


My plan for output device is to develop output board with LCD and power supply circuit. Which Reads the Input and Display it.

---------


## Preparation: Test the lcd module

Hardware testing：
        I picked Lumex  M E300052 1602 LCD module, . Trying to display "Hello world" message to testify the module.

 Connect the wire：
 
     GND <-> LCD GND-1
     
     VCC <-> LCD R/W-5 & VCC-2
     
     PA5 <-> RS 4
     
     PA4 <-> LCD E -6
     
     PA3 <-> DB4-11
     
     PA2 <-> DB5-12
     
     PA1 <-> DB6-13
     
     PA0 <-> DB7-14
     
     
<center><img src="img/w13/2.jpeg" width="800"/></center>

     
Use the following sample code to drive the LCD display using arduino.

<center><img src="img/w13/o1.1.png" width="600"/></center>

```
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(5, 4, 3, 2, 1, 0);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}

```


 The test program was sucess full.
 

<center><img src="gif/w13/1.gif" width="800"/></center>



--------------

Next I tried Niel's Program. 

```
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

#define output(directions,pin) (directions |= pin) // set port direction for output
#define set(port,pin) (port |= pin) // set port pin
#define clear(port,pin) (port &= (~pin)) // clear port pin
#define pin_test(pins,pin) (pins & pin) // test for port pin
#define bit_test(byte,bit) (byte & (1 << bit)) // test for bit set

#define LCD_port PORTA
#define LCD_direction DDRA
#define DB7 (1 << PA0)
#define DB6 (1 << PA1)
#define DB5 (1 << PA2)
#define DB4 (1 << PA3)
#define E (1 << PA4)
#define RS (1 << PA5)

#define long_delay() _delay_ms(1000) // delay before redraw
#define lcd_delay() _delay_ms(10) // delay between commands
#define strobe_delay() _delay_us(1) // delay for strobe

//
// lcd_putchar
//    put character in lcdbyte
//
void lcd_putchar(char lcdbyte) {
   //
   // set RS for data
   // 
   set(LCD_port, RS);
   //
   // output high nibble
   //
   if bit_test(lcdbyte, 7)
      set(LCD_port, DB7);
   else
      clear(LCD_port, DB7);
   if bit_test(lcdbyte, 6)
      set(LCD_port, DB6);
   else
      clear(LCD_port, DB6);
   if bit_test(lcdbyte, 5)
      set(LCD_port, DB5);
   else
      clear(LCD_port, DB5);
   if bit_test(lcdbyte, 4)
      set(LCD_port, DB4);
   else
      clear(LCD_port, DB4);
   //
   // strobe E
   //
   strobe_delay();
   set(LCD_port, E);
   strobe_delay();
   clear(LCD_port, E);
   //
   // wait
   //
   lcd_delay();
   //
   // output low nibble
   //
   if bit_test(lcdbyte, 3)
      set(LCD_port, DB7);
   else
      clear(LCD_port, DB7);
   if bit_test(lcdbyte, 2)
      set(LCD_port, DB6);
   else
      clear(LCD_port, DB6);
   if bit_test(lcdbyte, 1)
      set(LCD_port, DB5);
   else
      clear(LCD_port, DB5);
   if bit_test(lcdbyte, 0)
      set(LCD_port, DB4);
   else
      clear(LCD_port, DB4);
   //
   // strobe E
   //
   strobe_delay();
   set(LCD_port, E);
   strobe_delay();
   clear(LCD_port, E);
   //
   // wait and return
   //
   lcd_delay();
   }
//
// lcd_putcmd
//    put command in lcdbyte
//
void lcd_putcmd(char lcdbyte) {
   //
   // clear RS for command
   // 
   clear(LCD_port, RS);
   //
   // output command bits
   //
   PORTA = lcdbyte;
   //
   // strobe E
   //
   strobe_delay();
   set(LCD_port, E);
   strobe_delay();
   clear(LCD_port, E);
   //
   // wait and return
   //
   lcd_delay();
   }
//
// lcd_putstring
//    put a null-terminated string in flash
//
void lcd_putstring(PGM_P message) {
   static uint8_t index;
   static char chr;
   index = 0;
   while (1) {
      chr = pgm_read_byte(&(message[index]));
      if (chr == 0)
         return;
      lcd_putchar(chr);
      ++index;
      }
   }
//
// lcd_init
//    initialize the LCD
//
void lcd_init() {
   //
   // power-up delay
   //
   lcd_delay();
   //
   // initialization sequence
   //
   lcd_putcmd(DB5+DB4);
   lcd_putcmd(DB5+DB4);
   lcd_putcmd(DB5+DB4);
   //
   // 4-bit interface
   //
   lcd_putcmd(DB5);
   //
   // two lines, 5x7 font
   //
   lcd_putcmd(DB5);
   lcd_putcmd(DB7);
   //
   // display on
   //
   lcd_putcmd(0);
   lcd_putcmd(DB7+DB6+DB5);
   //
   // entry mode
   //
   lcd_putcmd(0);
   lcd_putcmd(DB6+DB5);
   }

int main(void) {
   //
   // main
   //
   // set clock divider to /1
   //
   CLKPR = (1 << CLKPCE);
   CLKPR = (0 << CLKPS3) | (0 << CLKPS2) | (0 << CLKPS1) | (0 << CLKPS0);
   //
   // initialize LCD pins
   //
   clear(LCD_port, DB7);
   output(LCD_direction, DB7);
   clear(LCD_port, DB6);
   output(LCD_direction, DB6);
   clear(LCD_port, DB5);
   output(LCD_direction, DB5);
   clear(LCD_port, DB4);
   output(LCD_direction, DB4);
   clear(LCD_port, E);
   output(LCD_direction, E);
   clear(LCD_port, RS);
   output(LCD_direction, RS);
   //
   // initialize LCD
   //
   lcd_init();
   //
   // main loop
   //
   while (1) {
      // 
      // go to zero position
      //
      lcd_putcmd(0);
      lcd_putcmd(DB5);
      //
      // print first line from flash
      //
      static const char line1[] PROGMEM = "Kerarla : Kerala";
      lcd_putstring((PGM_P) line1);
      //
      // move to second line
      //
      lcd_putcmd(DB7+DB6);
      lcd_putcmd(0);
      //
      // print second line from flash
      //
      static const char line2[] PROGMEM = "own country";
      lcd_putstring((PGM_P) line2);
      //
      // pause
      //
      long_delay();
      //
      // clear display
      //
      lcd_putcmd(0);
      lcd_putcmd(DB4);
      }
   }

```

I edited the text which going to display. 



<center><img src="img/w13/c.png" width="600"/></center>

I used the commend on the terminal for genrating the hex.

<center><img src="img/w13/make.png" width="300"/></center>


```
sudo make -f hello.LCD.44.make
```

<br>


<center><img src="img/w13/prgm.1.png" width="400"/></center>
<br>

`
sudo make -f hello.LCD.44.make program-usbtiny
`
<br>
<center><img src="img/w13/prgm.png" width="600"/></center>
<br>

the programming was sucess. Its start agiain displaying.

<br>

<center><img src="gif/w13/3.gif" width="800"/></center>

<br>
--------------

## Distance display on LCD

Then I tried to program di

<br>

```
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

```
<br>

<center><img src="gif/w13/4.gif" width="800"/></center>
<br>
-------------

## Files

* atf.HC-SR04.LCD.44 [board](file/w11/atf.HC-SR04.LCD.44/atf.HC-SR04.LCD.44.png), [traces](file/w11/atf.HC-SR04.LCD.44/atf.HC-SR04.LCD.44.traces.png), [interior](file/w11/atf.HC-SR04.LCD.44/atf.HC-SR04.LCD.44.interior.png), [holes](file/w11/atf.HC-SR04.LCD.44/atf.HC-SR04.LCD.44.holes.png)

* [hello.world.ino](file/w13/hello.world.ino)

* [hello.LCD.44.c](file/w13/hello.LCD.44.c), [hello.LCD.44.c.hex](file/w13/hello.LCD.44.c.hex)

* [HC.sonar.LCD.44.ino](file/w13/HC.sonar.LCD.44.ino) 

