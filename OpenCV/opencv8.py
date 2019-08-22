import cv2
import numpy as np

frames = 0

cam = cv2.VideoCapture(0)

while(1):
    _, frame = cam.read()
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    hsv_kernel = np.ones((15, 15), np.float32) / 255
    hsv_blur = cv2.filter2D(hsv, -1, hsv_kernel)

    pixels = 5
    hsv_gaussian = cv2.GaussianBlur(hsv, (pixels, pixels), 0)

    lower_red = np.array([100, 150, 50])
    upper_red = np.array([255, 255, 255])

    mask = cv2.inRange(hsv, lower_red, upper_red)
    result = cv2.bitwise_and(frame, frame, mask = mask)

    kernel = np.ones((15, 15), np.float32) / 255
    smoothed = cv2.filter2D(result, -1, kernel)

    gaussian = cv2.GaussianBlur(result, (15, 15), 0)

    median = cv2.medianBlur(result, 15)

    bilateral = cv2.bilateralFilter(result, 15, 75, 75)
    
    cv2.putText(frame, f"{frames + 1} frames.", (200, 450), cv2.FONT_HERSHEY_COMPLEX, 1, (0, 0, 0), 2)

    cv2.putText(frame, "Press ESC to close Window", (50, 400), cv2.FONT_HERSHEY_COMPLEX, 1, (0, 0, 0), 2)
    cv2.imshow('Frame', frame)
    cv2.imshow('HSV', hsv)
    #cv2.imshow('HSV Blur', hsv_blur)
    #cv2.imshow('HSV Gaussian Blur', hsv_gaussian)
    cv2.imshow('Mask', mask)
    cv2.imshow('Result', result)
    cv2.imshow('Smoothed', smoothed)
    cv2.imshow('Gaussian Blur', gaussian)
    cv2.imshow('Median Blur', median)
    cv2.imshow('Bilateral Blur', bilateral)


    key = cv2.waitKey(5) & 0xFF

    if key == 27:
        print("There were", frames, "frames.")
        break
    else:
        frames += 1
        continue


cv2.destroyAllWindows()
cam.release()