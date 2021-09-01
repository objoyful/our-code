import cv2
import numpy as np

dispW = 320 * 2
dispH = 240 * 2

flip = 4

camSet = 'nvarguscamerasrc ! video/x-raw(memory:NVMM), width=3264, height=2464, format=NV12, framerate=21/1 ! nvvidconv flip-method=' + str(flip) + ' ! video/x-raw, width=' + str(dispW) + ', height=' + str(dispH) + ', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! appsink'

piCam = cv2.VideoCapture(camSet)
webCam = cv2.VideoCapture(1)

# Web cam or pi cam setting
cam = webCam

w = int(cam.get(cv2.CAP_PROP_FRAME_WIDTH))
h = int(cam.get(cv2.CAP_PROP_FRAME_HEIGHT))

w2 = int(w / 2)
h2 = int(h / 2)

blank = np.zeros([h, w, 1], np.uint8)
#blank[0:h2, 0:w2] = 125

while True:
    ret, frame = cam.read()

    if not ret:
        print("Camera malfunction")
        break

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    
    print('(45, 50) Blue Value:', frame[50, 45, 0])

    #print(frame.shape)
    #print(gray.shape)
    #print(gray.size)
    #print(frame.size)

    #b = cv2.split(frame)[0]
    #g = cv2.split(frame)[1]
    #r = cv2.split(frame)[2]

    b, g, r = cv2.split(frame)

    blue = cv2.merge((b, blank, blank))
    green = cv2.merge((blank, g, blank))
    red = cv2.merge((blank, blank, r))

    g[:] = g[:] * 0.1

    merge = cv2.merge((b, g, r))

    cv2.imshow('Blue', blue)
    cv2.moveWindow('Blue', w + 80, 0)

    cv2.imshow('Green', green)
    cv2.moveWindow('Green', 0, h + 60)

    cv2.imshow('Red', red)
    cv2.moveWindow('Red', w + 80, h + 60)
    
    cv2.imshow('Camera', frame)
    cv2.moveWindow('Camera', 0, 0)

    cv2.imshow('Merge', merge)
    cv2.moveWindow('Merge', 2 * w + 80, 0)

    if cv2.waitKey(1) == ord('q'):
        break

cam.release()
cv2.destroyAllWindows()