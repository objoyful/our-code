import cv2
from matplotlib import pyplot as plt

fluf = cv2.imread('newfluf.JPG', cv2.IMREAD_GRAYSCALE)

plt.imshow(fluf, cmap = 'gray', interpolation = 'bicubic')
plt.xticks([]) 
plt.yticks([])
plt.plot([200, 300, 400], [100, 200, 300], 'c', linewidth = 5)
plt.show()