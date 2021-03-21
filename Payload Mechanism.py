# This uses a PCA9685 16 channel servo expansion board and is Connected to the Jetson via the I2C protocol
# This is based out of the ServoKit library.
# This is an example code which opens and shuts the payload bay and drops packages for delivery.
# We will be using a connection between the Pixhawk and the Jetson to get location data to decide when to open the payload bay to drop packages.


import time
from adafruit_servokit import ServoKit

kit = ServoKit(channels=8)

for i in range(len(kit.servo)):
    kit.servo[i].angle = 90
time.sleep(4)
for i in range(len(kit.servo)):
    kit.servo[i].angle = 0
time.sleep(4)
