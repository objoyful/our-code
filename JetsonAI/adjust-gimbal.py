from adafruit_servokit import ServoKit

myKit = ServoKit(channels = 16)
myKit.servo[0].angle = 90
myKit.servo[1].angle = 90