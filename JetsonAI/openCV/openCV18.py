import cv2
import numpy as np

print(cv2.__version__)

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

    FGmask1 = cv2.inRange(hsv, l_b, u_b)
    FGmask2 = cv2.inRange(hsv, l_b2, u_b2)

    FGmask = cv2.add(FGmask1, FGmask2)
    cv2.imshow('FG Mask', FGmask)
    cv2.moveWindow('FG Mask', w + 60, 0)

    _, contours, _ = cv2.findContours(FGmask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    contours = sorted(contours, key = lambda x:cv2.contourArea(x), reverse = True)

    for cnt in contours:
        area = cv2.contourArea(cnt)
        (x, y, boxW, boxH) = cv2.boundingRect(cnt)
        
        linX = x + int(boxW / 2)
        linY = y + int(boxH / 2)

        if area >= 200:
            #cv2.drawContours(frame, [cnt], 0, (0, 0, 255), 3)
            #cv2.rectangle(frame, (x, y), (x + boxW, y + boxH), (255, 0, 0), 15)
            cv2.line(frame, (linX, 0), (linX, h), (0, 255, 0), 5)
            cv2.line(frame, (0, linY), (w, linY), (0, 255, 0), 5)

    cv2.moveWindow('Trackbars', 2 * w + 100, 0)    
    
    cv2.imshow('Camera', frame)
    cv2.moveWindow('Camera', 0, 0)

    if cv2.waitKey(1) == ord('q'):
        break

cam.release()
cv2.destroyAllWindows()