from adafruit_servokit import ServoKit
import time
import cv2

myKit = ServoKit(channels = 16)

while True:
    for i in range(0, 160, 1):
        myKit.servo[0].angle = i
        myKit.servo[1].angle = i
        time.sleep(0.005)

    for i in range(160, 0, -1):
        myKit.servo[0].angle = i
        myKit.servo[1].angle = i
        time.sleep(0.005)

    if cv2.waitKey(1) == ord('q'):
        break