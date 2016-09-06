<div style="width:1000px; margin:0 auto;">

<div align="justify" style="margin-left:2.5%" style="margin-right:3%">

<center>

# Week 2: 

# Computer Aided Design


</center>
--------------

## Topics:

2D, 3D design, game engines, simulation, audio, video


### Assignment:

Model a possible final project!

-------------------

## What's CAD ?

Computer Aided Design, or CAD, is a bunch of concepts and techniques of how to use the power of computers and graphics processors in design and simulations. CAD is a part of the Computer Aided Enginnering field. There's a variety of CAD Softwares and tools that you can use, it starts from free sketching softwares to sophisticated mechanical simulation softwares. You can categorize CAD softwares into.Raster and Vector formats. 

## 2D Design


### Raster

Raster formated design and raster-oriented softwares (like paint, GIMP, Photoshop) form the design as a huge combination of pixels, as a result the resoultion of the design or image is dependant on the size, whenever you enlarage the design or zoom in the image/design "pixel".

### Vector
Vector formatted designs save the data as vectors (startpoints, endpoints, lengths). Each format has different settings when you start working with the machines.

-------------

## 3D Design

### Antimony

Antimony is a computer-aided design (CAD) tool from a parallel universe in which CAD software evolved from Lisp machines rather than drafting tables.

#### Installing Antimony

All the requirments are to be install first. here the [link] (https://github.com/mkeeter/antimony)

or

follow instruction for Building Antimony.

The instructions are given there. First step is to install the Qt. Here is the link

Then install all the dependencies
  
```
    sudo apt-get install buildessential

    sudo apt-get install libpng-dev

    sudo apt-get install python3-dev

    sudo apt-get install libboost-all-dev

    sudo apt-get install libgl1-mesa-dev

    sudo apt-get install lemon

    sudo apt-get install flex
```


Next is to download the antimony zip file , or clone it using git clone command.

```

    git clone https://github.com/mkeeter/antimony.git

    cd antimony

    mkdir build

    cd build

    ~/Qt5.4.0/5.4/gcc_64/bin/qmake ../sb.pro make -j3

    ./app/antimony

```

#### Experimentation

Add 2D circle > 2D to 3D > Extrude > Add array > Add 2D rectange > And Extrude it > Add Deffernce > you can adjest the dimensions from where you need..

<center><img src="img/project/anti.png" width="800"/></center>


------------


## Modelled of final project in 2D and 3D software


I used AutoCAD for desgining 2D drawings of my Project.

### Top view

<center><img src="img/project/a1.png" width="800"/></center>

### Side View
 
<center><img src="img/project/a2.png" width="800"/></center>


--------------
### Perspective View


I used Rhyno for desgining 3D drawings of my Project. imported 2D '.dwg' file which drawn using AutoCad. I rendered it .

<center><img src="img/project/r2.jpg" width="800"/></center>

<center><img src="img/project/r1.jpg" width="800"/></center>


----------
## Original design files


* 2D drawing in <kbd> .dwg </kbd> format [here](file/c-shelf.dwg)

* 3D drawing in <kbd> .3dm </kbd> format [here](file/c-shelf.3dm)


</div>