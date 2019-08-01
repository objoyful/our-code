import cv2
import numpy as np 
from matplotlib import pyplot as plt

fluf = cv2.imread('newfluf.JPG', cv2.IMREAD_GRAYSCALE)

cv2.imshow('Fluffy', fluf)

cv2.imwrite('grayfluf.jpg', fluf)