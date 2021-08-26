import cv2

dispW = 320 * 4
dispH = 240 * 4

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

BW = int(0.2 * w)
BH = int(0.2 * h)

posX = 10
posY = 270

dx = 2
dy = 2

while True:
    ret, frame = cam.read()

    if not ret:
        print("Camera malfunction")
        break

    roi = frame[posY:posY + BH, posX:posX + BW].copy()
    
    frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    frame = cv2.cvtColor(frame, cv2.COLOR_GRAY2BGR)

    frame[posY:posY + BH, posX:posX + BW] = roi

    cv2.rectangle(frame, (posX, posY), (posX + BW, posY + BH), (255, 0, 0), 3)
    
    cv2.imshow('Camera', frame)
    cv2.moveWindow('Camera', 0, 0)

    posX = posX + dx
    posY = posY + dy

    if posX + BW >= w or posX <= 0:
        dx = dx * (-1)
    if posY + BH >= h or posY <= 0:
        dy = dy * (-1)

    if cv2.waitKey(1) == ord('q'):
        break

cam.release()
cv2.destroyAllWindows()