<div style="width:800px; margin:0 auto;">

### Kokopelli installetion


Kokopelli is a Circut board designing software, By using programing we can create PCD design. With guidance of francisico and Github we intastaled following steps..

* Download [***kokopelli_retro.zip***](https://drive.google.com/folderview?id=0BzRX0YoH0d4OaHYxS3luS3pnVDg&usp=sharing&tid=0BzRX0YoH0d4OcjJSRTN6dW8wTms) file from google drive

or

  Downlod  Fab Modules ***[kokompe.cba.mit.edu](http://kokompe.cba.mit.edu/fab_src.zip)*** .(includes path planning, machine output and design GUIs)
  
    *  unziped it.

    * open ubuntu terminal.

    `cd Downloads/koko_retro`

    `make clean`

    `make fab`
    
    `make install`

     `cd bin`

     `./kokopelli -r`  

it opened and if it was not shown output file..

    * Then -> [**Install Python Galleries**](https://github.com/mkeeter/kokopelli/wiki/Installing)

    `sudo apt-get install python python-dev python-pip gcc g++ libpng12-dev make bash  cmake`

The required Python libraries are available through pip.

    `sudo pip install numpy PyOpenGL PyOpenGL_accelerate`
    
    `install_wxpython3.0.sh`

open it again..


</div>
