import cv2
import numpy as np
import time

frames = 0
start_time = time.time()
cam = cv2.VideoCapture(0)

while(1):
    max_fps = 0
    fps = round(frames / (time.time() - start_time), 1)

    if fps > max_fps:
        max_fps = fps
    else:
        max_fps = max_fps
    
    _, frame = cam.read()
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    lower_red = np.array([100, 170, 170])
    upper_red = np.array([255, 255, 255])

    mask = cv2.inRange(hsv, lower_red, upper_red)
    result = cv2.bitwise_and(frame, frame, mask = mask)

    kernel = np.ones((5, 5), np.uint8)

    erosion_result = cv2.bitwise_and(frame, frame, mask = cv2.erode(mask, kernel))
    dilation = cv2.bitwise_and(frame, frame, mask = cv2.dilate(mask, kernel))

    opening = cv2.bitwise_and(frame, frame, mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel))
    closing = cv2.bitwise_and(frame, frame, mask = cv2.morphologyEx(mask, cv2.MORPH_CLOSE, kernel))

    tophat = cv2.bitwise_and(frame, frame, mask = cv2.morphologyEx(mask, cv2.MORPH_TOPHAT, kernel))
    blackhat = cv2.bitwise_and(frame, frame, mask = cv2.morphologyEx(mask, cv2.MORPH_BLACKHAT, kernel))

    cv2.putText(result, f"{frames + 1} frames.", (50, 300), cv2.FONT_HERSHEY_COMPLEX, 1, (255, 255, 255), 5)
    cv2.putText(result, f"{fps} FPS", (50, 400), cv2.FONT_HERSHEY_COMPLEX, 1, (255, 255, 255), 5)
    cv2.imshow('Frame', frame)
    cv2.imshow('Result', result)
    cv2.imshow('Erosion', erosion_result)
    cv2.imshow('Dilation', dilation)
    cv2.imshow('Opening', opening)
    cv2.imshow('Closing', closing)
    cv2.imshow('Tophat', tophat)
    cv2.imshow('Blackhat', blackhat)

    key = cv2.waitKey(10) & 0xFF
    if key == 27:
        break
    else:
        frames += 1
        continue

print("The max FPS was", max_fps, "FPS.")
cv2.destroyAllWindows()
cam.release()