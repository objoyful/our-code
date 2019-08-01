import cv2
import numpy as np
from matplotlib import pyplot as plt

img = cv2.imread('Windows.jpg',cv2.IMREAD_UNCHANGED)
cv2.imshow('Windows Timeline',img)
cv2.waitKey(0)
cv2.destroyAllWindows()