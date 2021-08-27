import cv2
import numpy as np

print(cv2.__version__)

dispW = 320 * 2
dispH = 240 * 2

flip = 4

camSet = 'nvarguscamerasrc ! video/x-raw(memory:NVMM), width=3264, height=2464, format=NV12, framerate=21/1 ! nvvidconv flip-method=' + str(flip) + ' ! video/x-raw, width=' + str(dispW) + ', height=' + str(dispH) + ', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! appsink'

piCam = cv2.VideoCapture(camSet)
webCam = cv2.VideoCapture(1)

# Web cam or pi cam setting
cam = piCam

w = int(cam.get(cv2.CAP_PROP_FRAME_WIDTH))
h = int(cam.get(cv2.CAP_PROP_FRAME_HEIGHT))

w2 = int(w / 2)
h2 = int(h / 2)

w4 = int(w / 4)
h4 = int(h / 4)

img1 = np.zeros((h, w, 1), np.uint8)
img1[0:h, 0:w2] = [255]

img2 = np.zeros((h, w, 1), np.uint8)
img2[h2 - 50:h2 + 50, w2 - 50:w2 + 50] = [255]

bitAnd = cv2.bitwise_and(img1, img2)
bitOr = cv2.bitwise_or(img1, img2)
bitXOr = cv2.bitwise_xor(img1, img2)

while True:
    ret, frame = cam.read()

    if not ret:
        print("Camera malfunction")
        break

    cv2.imshow('IMG 1', img1)
    cv2.moveWindow('IMG 1', 1300, 0)

    cv2.imshow('IMG 2', img2)
    cv2.moveWindow('IMG 2', 2600, 0)

    cv2.imshow('Bitwise AND', bitAnd)
    cv2.moveWindow('Bitwise AND', 0, 900)
    
    cv2.imshow('Bitwise OR', bitOr)
    cv2.moveWindow('Bitwise OR', 1300, 900)

    cv2.imshow('Bitwise XOR', bitXOr)
    cv2.moveWindow('Bitwise XOR', 2600, 900)

    frame = cv2.bitwise_and(frame, frame, mask=bitXOr)
    
    cv2.imshow('Camera', frame)
    cv2.moveWindow('Camera', 0, 0)

    if cv2.waitKey(1) == ord('q'):
        break

cam.release()
cv2.destroyAllWindows()