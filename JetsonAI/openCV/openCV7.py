import cv2
import numpy as np

ver = cv2.__version__
print(ver)

font = cv2.FONT_HERSHEY_PLAIN

evt = -1
coord = []
img = np.zeros((250, 250, 3), np.uint8)

def click(event, x, y, flags, params):
    global pnt
    global evt

    if event == cv2.EVENT_LBUTTONDOWN:
        print('Mouse event was:', event)
        print(x, ',', y)

        pnt = (x, y)
        evt = event
        
        coord.append(pnt)
        print(coord)
    
    if event == cv2.EVENT_RBUTTONDOWN:
        print(x, y)

        blue = frame[y, x, 0]
        green = frame[y, x, 1]
        red = frame[y, x, 2]

        colorString = '(' + str(blue) + ', ' + str(green) + ', ' + str(red) + ')'
        img[:] = [blue, green, red]

        r = 255 - int(red)
        g = 255 - int(green)
        b = 255 - int(blue)

        tp = (b, g, r)

        cv2.putText(img, colorString, (10, 25), font, 1.5, tp, 2)
        
        cv2.imshow('Color', img)

dispW = 320 * 2
dispH = 240 * 2

flip = 4

cv2.namedWindow('Camera')
cv2.setMouseCallback('Camera', click)

camSet = 'nvarguscamerasrc ! video/x-raw(memory:NVMM), width=3264, height=2464, format=NV12, framerate=21/1 ! nvvidconv flip-method=' + str(flip) + ' ! video/x-raw, width=' + str(dispW) + ', height=' + str(dispH) + ', format=BGRx ! videoconvert ! video/x-raw, format=BGR ! appsink'

piCam = cv2.VideoCapture(camSet)
webCam = cv2.VideoCapture(1)

# Web cam or pi cam setting
cam = webCam

w = int(cam.get(cv2.CAP_PROP_FRAME_WIDTH))
h = int(cam.get(cv2.CAP_PROP_FRAME_HEIGHT))

w2 = int(w / 2)
h2 = int(h / 2)

while True:
    ret, frame = cam.read()

    if not ret:
        print("Camera malfunction")
        break

    for pnts in coord:
        cv2.circle(frame, pnts, 5, (0, 0, 255), -1)
        
        myStr = str(pnts)
        cv2.putText(frame, myStr, pnts, font, 1.5, (255, 0, 0), 2)
    
    cv2.imshow('Camera', frame)
    cv2.moveWindow('Camera', 0, 0)

    keyEvent = cv2.waitKey(1)
    
    if keyEvent == ord('q'):
        break
    
    if keyEvent == ord('c'):
        coord = []
        print('Array cleared')

cam.release()
cv2.destroyAllWindows()