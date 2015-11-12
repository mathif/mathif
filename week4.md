# Week-4

## Day-1

### Kokopelli installetion
Kokopelli is a Circut board designing software, By using programing we can create PCD design. With guidance of francisico and Github we intastaled following steps..

1. Download ***kokopelli_retro.zip*** file from google drive

or

  Downlod  Fab Modules ***[kokompe.cba.mit.edu]   (http://kokompe.cba.mit.edu/fab_src.zip)*** .(includes path planning, machine output and design GUIs)
  
2. unziped it.

3. open ubuntu terminal.
  
 `cd Downloads/koko_retro`

4. `make clean`

6. `make fab`

7. `make install`

8. `cd bin`

9. `./kokopelli -r`  

it opened and if it was not shown output file..

10. Then -> (**Install Python Galleries**)                            (https://github.com/mkeeter/kokopelli/wiki/Installing)

`sudo apt-get install python python-dev python-pip gcc g++ libpng12-dev make bash cmake`

The required Python libraries are available through pip.

    `sudo pip install numpy PyOpenGL PyOpenGL_accelerate`
    
    `install_wxpython3.0.sh`

open it again..

### Designing Circut Board in Kokopelli




## Day-2
### Clean up

It need a great habbit to maintain clean and arranged your lab when you are working, you must ensure your lab make clean and well arranged , must ensure nothing displaced anywhere. With fransisco we joined and within a half hour we arranged everthings in properway. it was a fun..

### Level a 3D Printer

### Bed leveling
When you printing the first layer of a print is very important. Therefore regular bed leveling is advised. Always re-level the build plate when you notice that the plastic is not equally placed on the glass plate
##### Setting the height

The first step is to roughly level the build plate by rotating the button at the front of your printer until there is approximately 1 mm distance between the nozzle and build plate. The measurement here is not critical, just make sure that the nozzle is close to the build plate without touching it
![setting height](img.level.bedsetting height.JPG)

##### Rough leveling
Next, a rough adjustment will be done on the front left and right side by turning the build plate screws. Turning the build plate screws to the left means that the build plate will get closer to the nozzle. Again there should be a distance of approximately 1 mm between the nozzle and build plate.
![rough leveling](/img/rough leveling.JPG)
##### Fine-tuning
The last step will be fine-tuning of the build plate with the calibration card or thin paper. Place the paper in between the nozzle and build plate on all 3 points and adjust the build plate screws until you feel slight friction when moving the card
![fine tuning](/img/fine tuning.JPG)
### 

### Designing Hello arduino with Kokopelli

Download the program [hello.ftdi.44](http://academy.cba.mit.edu/classes/embedded_programming/index.html).

* open with gedit.
* search for LED_1206,R_1206,butten_6mm 


![hello.ftdi.44 initially](img/hello.ftdi.44 initially.png)

 Then we need to add one LED, Resisistor, Botten . so we use these program to create the traces and soldering pints.
  
```
LED1 = LED_1206('LED1');
pcb = LED1.add(pcb,XTAL1.x,IC1.pad[5].y,z,180)

pcb = wire(pcb,w,
   IC1.pad[5],
   LED1.pad[1])

R2 = R_1206('R2')
pcb = R2.add(pcb,LED1.pad[2].x,J2.pad[6].y,z,90)

pcb = wire(pcb,w,
   R2.pad[2],
   LED1.pad[2])

pcb = wire(pcb,w,
   J1.pad[6],
   R2.pad[1])

B1= button_6mm('B1')
pcb = B1.add(pcb,R2.pad[2].x+.24,J1.pad[1].y-.045,z)

pcb = wire(pcb,w,
   IC1.pad[7],
   B1.pad[1])


pcb = wire(pcb,w,
   J1.pad[6],
   B1.pad[2])

```

### Lucture of Vedio conferinsing system


## Day-3

## Day-4
## Day-5

