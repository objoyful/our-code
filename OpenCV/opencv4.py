import cv2
import numpy as np

fluf = cv2.imread('newfluf.JPG', cv2.IMREAD_COLOR)
flufface = cv2.imread('flufface.jpg', cv2.IMREAD_COLOR)

fluf[0, 0] = [0, 0, 0]

px = fluf[0, 0]
print(px)

fluf[620:668, 0:1131] = [255, 255, 255]

print("Shape", fluf.shape)
print("Size",  fluf.size)
print("dtype", fluf.dtype)

face = fluf[250:610, 560:880]
flufface[0:360, 0:320] = face

cv2.imshow('Fluffy', fluf)
cv2.imshow('Fluffy\'s Face', flufface)
cv2.imwrite('flufface.jpg', flufface)
cv2.waitKey(0)
cv2.destroyAllWindows()