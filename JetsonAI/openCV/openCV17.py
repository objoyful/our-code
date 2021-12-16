import cv2
import numpy as np

def nothing(x):
    pass

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

cv2.namedWindow('Trackbars')

cv2.createTrackbar('Lower Hue', 'Trackbars', 50, 179, nothing)
cv2.createTrackbar('Higher Hue', 'Trackbars', 100, 179, nothing)

cv2.createTrackbar('Lower Hue #2', 'Trackbars', 50, 179, nothing)
cv2.createTrackbar('Higher Hue #2', 'Trackbars', 100, 179, nothing)

cv2.createTrackbar('Lower Saturation', 'Trackbars', 100, 255, nothing)
cv2.createTrackbar('Higher Saturation', 'Trackbars', 255, 255, nothing)

cv2.createTrackbar('Lower Value', 'Trackbars', 100, 255, nothing)
cv2.createTrackbar('Higher Value', 'Trackbars', 255, 255, nothing)

#cv2.imshow('Trackbars')

while True:
    ret, frame = cam.read()
    #frame = cv2.imread('JetsonAI/smarties.png')

    if not ret:
        print("Camera malfunction")
        break
    
    cv2.imshow('Camera', frame)
    cv2.moveWindow('Camera', 0, 0)

    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    #cv2.imshow('HSV', hsv)
    #cv2.moveWindow('HSV', 500, 0)

    hueLow = cv2.getTrackbarPos('Lower Hue', 'Trackbars')
    hueUp = cv2.getTrackbarPos('Higher Hue', 'Trackbars')
    
    hue2Low = cv2.getTrackbarPos('Lower Hue #2', 'Trackbars')
    hue2Up = cv2.getTrackbarPos('Higher Hue #2', 'Trackbars')

    Ls = cv2.getTrackbarPos('Lower Saturation', 'Trackbars')
    Us = cv2.getTrackbarPos('Higher Saturation', 'Trackbars')

    Lv = cv2.getTrackbarPos('Lower Value', 'Trackbars')
    Uv = cv2.getTrackbarPos('Higher Value', 'Trackbars')

    l_b = np.array([hueLow, Ls, Lv])
    u_b = np.array([hueUp, Us, Uv])

    l_b2 = np.array([hue2Low, Ls, Lv])
    u_b2 = np.array([hue2Up, Us, Uv])
    
    print('Lower Bound:', l_b)
    print('Upper Bound:', u_b)

    FGmask1 = cv2.inRange(hsv, l_b, u_b)
    cv2.imshow('FG Mask 1', FGmask1)
    cv2.moveWindow('FG Mask 1', 500, 0)

    FGmask2 = cv2.inRange(hsv, l_b2, u_b2)
    cv2.imshow('FG Mask 2', FGmask2)
    cv2.moveWindow('FG Mask 2', 1000, 0)

    FGmask = cv2.add(FGmask1, FGmask2)
    cv2.imshow('FG Mask', FGmask)
    cv2.moveWindow('FG Mask', 1500, 0)

    FG = cv2.bitwise_and(frame, frame, mask = FGmask)
    cv2.imshow('FG', FG)
    cv2.moveWindow('FG', 2000, 0)

    bgMask = cv2.bitwise_not(FGmask)
    cv2.imshow('BG Mask', bgMask)
    cv2.moveWindow('BG Mask', 500, 500)

    BG = cv2.cvtColor(bgMask, cv2.COLOR_GRAY2BGR)
    cv2.imshow('BG', BG)
    cv2.moveWindow('BG', 1000, 500)

    final = cv2.add(FG, BG)
    cv2.imshow('Final', final)
    cv2.moveWindow('Final', 2500, 0)

    cv2.moveWindow('Trackbars', 3000, 0)

    if cv2.waitKey(1) == ord('q'):
        break

cam.release()
cv2.destroyAllWindows()