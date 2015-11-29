<div style="width:800px;">

### Designing Hello.ftdi with Kokopelli


Download the program [hello.ftdi.44](http://academy.cba.mit.edu/classes/embedded_programming/index.html).

* open with gedit.
* search for LED_1206,R_1206,butten_6mm 


<center>![hello.ftdi.44 initially](img/hello.ftdi.44.arduino/44)</center>

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



<center>![](img/hello.ftdi.44.arduino/22.png)</center>


<center>![traces](img/hello.ftdi.44.arduino/traces.png)</center>

<center>![interior](img/hello.ftdi.44.arduino/interior.png)</center>


</div>
