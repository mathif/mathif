import serial
import time
 
s = serial.Serial('/dev/ttyUSB0', 9600) #port is /dev/ttyUSB0, and baud rate is 9600
time.sleep(2)    #wait for the Serial to initialize
s.write('Ready...')
while True:
    str = raw_input('Enter text: ')
    str = str.strip()
    if str == 'exit' :
        break
    s.write(str)


