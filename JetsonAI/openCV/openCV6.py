import cv2

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

BW = int(0.25 * w)
BH = int(0.15 * h)

posX = 10
posY = 270

dx = 6
dy = 6

while True:
    ret, frame = cam.read()

    if not ret:
        print("Camera malfunction")
        break

    frame = cv2.rectangle(frame, (posX, posY), (posX + BW, posY + BH), (255, 0, 0), -1)

    cv2.imshow('Camera', frame)
    cv2.moveWindow('Camera', 0, 0)

    posX = posX + dx
    posY = posY + dy

    if posX <= 0 or posX + BW >= w:
        dx = dx * (-1)
    if posY <= 0 or posY + BH >= h:
        dy = dy * (-1)

    if cv2.waitKey(1) == ord('q'):
        break

cam.release()
cv2.destroyAllWindows()