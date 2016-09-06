<div style="width:1000px; margin:0 auto;">
<center>
#Week 12
#Input devices : Apr 13
</center>


##Assignment :

This week's assignment is to measure something: add a sensor to a microcontroller board that you have designed and read it.


An input device provides information about a work environment such as magnetic fields, temperature, light, sound, acceleration, orientation, vibration and more ,this information is sensed by a device called sensor and then is processed and measured by a microcontroller.There are hello world example circuits to measure magnetic fields, temperature, light, sound, acceleration, orientation, vibration and more. 

------------

## Making the Circuit Board

I decided to make a  the mic circuit.After refering some previous year student's documentations of input devices I decided to redesign Neil's design of mic .Using Eagle, first I drew the schematic and checked the error using ERC.



Then using switch to board option,by arranging and tracing the paths I completed the board.During tracing I needed to change the grid sizes for proper spacing.



Then I milled and stuffed the board with required components.

<center><img src="img/w12/i4.jpeg" width= "800"/></center>
<br>


To program the baard first i had to download hello.mic.45.c ,makefile, hello.mic.45.py,python,I used fabISP to program the board.Connect the board and fabISP together and also with computer.


<center><img src="img/w12/i4.1.jpeg" width= "800"/></center>
<br>

For compiling program to hex use the following code:

`
sudo make -f hello.mic.45.make 
`

code used to program 

`
sudo make -f hello.mic.45.make program-usbtiny
`

--------------------

## Testing

I made a four pin ribbon cable and connected it to the board.You need to remove connection to programmer before this.Then I used the example Python program and the FTDI USB to serial cable to communicate with the circuit and display the analog information.To run python program use following code :

`
python hello..mic.45.py /dev/ttyUSB0
`

<center><img src="img/w12/i6.png" width= "800"/></center>
<br>

</div>