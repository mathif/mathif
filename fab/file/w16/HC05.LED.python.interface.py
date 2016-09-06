from Tkinter import * # Import tk module
import tkFont
import serial
import time

arduino=serial.Serial() #Serial comunication with fabKit (Arduino UNO compatible)
arduino.port ="/dev/ttyUSB0" #Change this value for your COM / tty
arduino.baudrate = 9600 #comunication to 9600 bauds

arduino.open()

def sendOrder(order):
     vf['text']="Waiting response..."
     v0.update_idletasks()
     arduino.flushInput()
     arduino.flushOutput()
     arduino.write(order+"\r\n")

     if arduino.readline()=="OKI\r\n": # "OKI\r\n" is the default response of fabkit program

         if order=="b":
             v2['text']="State Output 2: ON"
             v2['bg']="green"
         elif order=="a":
             v2['text']="State Output 2: OFF"
             v2['bg']="red"
         elif order=="d":
             v1['text']="State Output 1: ON"
             v1['bg']="green"
         elif order=="c":
             v1['text']="State Output 1: OFF"
             v1['bg']="red"
         elif order=="e":
             t1['text']="Distance:  "+arduino.readline().rstrip() + " inches"
         elif order=="f":
             h1['text']="Distance:  "+arduino.readline().rstrip() + " centimeters"
     vf['text']=""

print ("Athif interface- Fab academy 2016") # Say hello in console (for debug, you can erase)
v0 = Tk() # Tk() Main window
v0.wm_title("Athif Fab Academy - Interface and Application Programming")
#v0.config(bg="black") # if you need change background color
v0.geometry("800x400") # windows size for aplication

helv16 = tkFont.Font(family="Helvetica",size=16,weight="bold")
helv24 = tkFont.Font(family="Helvetica",size=24,weight="bold")
helv14 = tkFont.Font(family="Helvetica",size=14,weight="bold")
helv8 = tkFont.Font(family="Helvetica",size=8,weight="bold")
l = Label(v0,font=helv16,text="Athif Fab Academy - Interface and Application Programming")
l.place(relx=.5, rely=.1, anchor="c")

v1 = Label(v0,font=helv14,text="State Output 1: OFF",bg="red")
v1.place(relx=.2, rely=.35, anchor="c")
v2 = Label(v0,font=helv14,text="State Output 2: OFF",bg="red")
v2.place(relx=.2, rely=.45, anchor="c")
t1 = Label(v0,font=helv14,text="Distance in inches: --")
t1.place(relx=.2, rely=.53, anchor="c")
h1 = Label(v0,font=helv14,text="Distance in centimeters: --")
h1.place(relx=.2, rely=.60, anchor="c")
b1=Button(v0,text="Activate output 1",width=20,command=lambda: sendOrder('d'))
b1.place(relx=.5, rely=.35, anchor="c")
#b1['text']="test"
b2=Button(v0,text="Disable output 1",width=20,command=lambda: sendOrder("c"))
b2.place(relx=.8, rely=.35, anchor="c")

b3=Button(v0,text="Activate output 2",width=20,command=lambda: sendOrder("b"))
b3.place(relx=.5, rely=.45, anchor="c")
#b1['text']="test"
b4=Button(v0,text="Disable output 2",width=20,command=lambda: sendOrder("a"))
b4.place(relx=.8, rely=.45, anchor="c")

b5=Button(v0,text="Update Distance",width=20,command=lambda: sendOrder("e"))
b5.place(relx=.8, rely=.53, anchor="c")

b6=Button(v0,text="Update Distance",width=20,command=lambda: sendOrder("f"))
b6.place(relx=.8, rely=.60, anchor="c")

vf = Label(v0,font=helv8,text="Waiting response...")
vf .place(relx=.5, rely=.97, anchor="c")
vf['text']=""
v0.mainloop() # launch the main window
