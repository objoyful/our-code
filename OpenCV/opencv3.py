import numpy as np 
import cv2 #BGR!!

gray_fluf = cv2.imread('newfluf.jpg', cv2.IMREAD_GRAYSCALE)
first_fluf = cv2.imread('newfluf.jpg', cv2.IMREAD_COLOR)
fluf = cv2.imread('newfluf.jpg', cv2.IMREAD_COLOR)

cv2.imshow('Fluffy', first_fluf)
cv2.imshow('Gray Fluf', gray_fluf)

cv2.line(fluf, (42, 471), (726, 632), (255, 255, 255), 10)
cv2.rectangle(fluf, (565, 242), (900, 600), (0, 255, 0), 5)
cv2.circle(fluf, (735, 582), 60, (0, 255, 255), 5)

pts = np.array([[65, 239], [219, 124], [416, 105], [798, 216], [892, 322], [792, 629], [387, 468], [75, 441]], np.int32)
cv2.polylines(fluf, [pts], True, (0, 0, 255), 5)

cv2.putText(fluf, 'Fluffy!', (422, 60), cv2.FONT_HERSHEY_SIMPLEX, 2, (0, 0, 0), 4)

gray_fluf_with_drawings = cv2.cvtColor(fluf, cv2.COLOR_BGR2GRAY)

cv2.imshow('Gray Fluf with Drawings', gray_fluf_with_drawings)
cv2.imshow('Fluffy with Drawings', fluf)
cv2.waitKey(0)
cv2.destroyAllWindows()
cv2.imwrite('flufdrawings.jpg', fluf)