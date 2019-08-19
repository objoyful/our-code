import cv2
import numpy as np

cam = cv2.VideoCapture(0)

while(1):
    _, frame = cam.read()
    