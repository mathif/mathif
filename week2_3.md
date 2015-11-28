<div style="width:800px;">

## Fab ISP

<center>
![](img/fabISP/hello.ISP.44.cutout)![](img/fabISP/hello.ISP.44)![](img/fabISP/hello.ISP.44.traces)
</center>

Download [fabISP](files/fabISP.zip)

### Milling

### Soldering

#### Needed components

* IC ATtiny 44-1
* USB mini port(female)-1
* ISP port 6 pin(Male)-1
* Crystal -20MHz-1
* Resistor - 1K-1
* Resistor - 499K-1
* Resistor - 100K-2
* Resistor - 10K-1
* Capacitor - 1uF-1
* Capacitor - 10uF-2
* Capacitor - 10pF-1
* Diode -3.3V-2

### [Programming](http://fabacademy.org/archives/2015/doc/programming_FabISP.html)


#### Get and install avrdude / GCC software and dependencies

Open Terminal and type:

```
    sudo apt-get install flex byacc bison gcc libusb-dev avrdude   

    sudo apt-get install gcc-avr 

    sudo apt-get install avr-libc 
    
    sudo apt-get install libc6-dev
```
#### Download the firmware from the Fab Academy Electronics Production page.

```
    wget http://academy.cba.mit.edu/classes/embedded_programming/firmware.zip 
```

Unzip the firmware, Move to the desktop

     
     
#### Edit the Makefile

The Makefile is set up to work with the AVRISP2 by default. If you are using another programmer, you will need to edit the Makefile.
```
    cd Desktop/firmware
```

```
    nano Makefile 
```
select your ISP , other inactive by ging '#' before.

save it 

#### Program the FabISP

Navigate to the directory where you saved the FabISP firmware. If you followed the instructions above, this will be the desktop.
Open your terminal / command line interface and move to the firmware directory.

```
    cd Desktop/firmware 

    make clean
    
    make hex
    
    make fuse
     
    make program
```
Wooo! Success! 

To Verify That Your ISP is working correctly:
```
    lsusb 
```
it shows on your terminal
```
    Bus 002 Device 004: ID 1781:0c9f Multiple Vendors USBtiny
```
#### After You Have Programmed the Board:

Remove the 0 ohm resistor and solder bridge as shown in the picture below.

<center>![](img/fabISP/fabISP.JPG)</center>

Now you can use it as a programmer to program other boards. 

</div>