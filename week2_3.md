<div style="width:800px; margin:0 auto;">

## Fab ISP
<div align="justify" style="margin-left:2.5%" style="margin-right:3%">

<center>
![](img/fabISP/hello.ISP.44.cutout)![](img/fabISP/hello.ISP.44)![](img/fabISP/hello.ISP.44.traces)
</center>

Download [fabISP](files/fabISP.zip)
</div>

### Milling


### Soldering

#### Needed components
<div align="justify" style="margin-left:2.5%" style="margin-right:3%">

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
</div>

### [Programming](http://fabacademy.org/archives/2015/doc/programming_FabISP.html)


#### Get and install avrdude / GCC software and dependencies
<div align="justify" style="margin-left:2.5%" style="margin-right:3%">

Open Terminal and type:

```
    sudo apt-get install flex byacc bison gcc libusb-dev avrdude   

    sudo apt-get install gcc-avr 

    sudo apt-get install avr-libc 
    
    sudo apt-get install libc6-dev
```
</div>

#### Download the firmware from the Fab Academy Electronics Production page.
<div align="justify" style="margin-left:2.5%" style="margin-right:3%">

```
    wget http://academy.cba.mit.edu/classes/embedded_programming/firmware.zip 
```

Unzip the firmware, Move to the desktop
</div>
     
     
#### Edit the Makefile
<div align="justify" style="margin-left:2.5%" style="margin-right:3%">

The Makefile is set up to work with the AVRISP2 by default. If you are using another programmer, you will need to edit the Makefile.
```
    cd Desktop/firmware
```

```
    nano Makefile 
```
select your ISP , other inactive by ging '#' before.

save it
</div> 

#### Program the FabISP
<div align="justify" style="margin-left:2.5%" style="margin-right:3%">

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
</div>

#### After You Have Programmed the Board:
<div align="justify" style="margin-left:2.5%" style="margin-right:3%">

Remove the 0 ohm resistor and solder bridge as shown in the picture below.

<center><img src="img/fabISP/fabISP.JPG" width= "400"/></center>

Now you can use it as a programmer to program other boards. 

</div>
</div>