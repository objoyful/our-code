import cv2
import numpy as np

cam = cv2.VideoCapture(0)

while(1):
    _, frame = cam.read()

    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

<<<<<<< HEAD
    lower_red = np.array([150, 150, 150])
    upper_red = np.array([255, 255, 255])
=======
    lower_red = np.array([50, 170, 170])
    upper_red = np.array([150, 255, 255])
>>>>>>> 7584ab6cd4c2fcdb30c3fcc27966a8adab47790b

    mask = cv2.inRange(hsv, lower_red, upper_red)

    result = cv2.bitwise_and(frame, frame, mask = mask)

    cv2.imshow('Camera', frame)
    cv2.imshow('Mask', mask)
    cv2.imshow('Result', result)

    key = cv2.waitKey(5) & 0xFF

    if key == 27:
        break

cv2.destroyAllWindows()
cam.release()