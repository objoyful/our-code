import cv2
import numpy as np

cam = cv2.VideoCapture(0)

while(1):
    _, frame = cam.read()
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    src = gray

    ddepth = cv2.CV_64F
    ksize = 15

    laplacian = cv2.Laplacian(src, ddepth)
    sobelx = cv2.Sobel(src, ddepth, 1, 0, ksize = ksize)
    sobely = cv2.Sobel(src, ddepth, 0, 1, ksize = ksize)
    edges = cv2.Canny(frame, 100, 200)

    cv2.imshow('Frame', frame)
    cv2.imshow('Source', src)
    cv2.imshow('Laplacian', laplacian)
    cv2.imshow('Sobel X', sobelx)
    cv2.imshow('Sobel Y', sobely)
    cv2.imshow('Edges', edges)

    key = cv2.waitKey(10) & 0xFF
    if key == 27 or key == ord('q'):
        break
    else:
        continue

cam.release()
cv2.destroyAllWindows()