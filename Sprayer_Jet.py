# This uses the smbus library to use I2C with the Jetson

from smbus import SMBus

addr = 0x8 # Arduino address
bus = SMBus

numb = 1

# Example code which takes input and sends data to the Arduino
print("Enter 1 for starting the sprayer and 0 for turning it off")
while (numb == 1):
  spray = input(">>")
  
  if spray == "1":
    bus.write_byte(addr, 0x1) # Turns on sprayer
  elif spray == "0":
    bus.write_byte(addr, 0x0) # Turns off sprayer
  else :
    numb = 0
